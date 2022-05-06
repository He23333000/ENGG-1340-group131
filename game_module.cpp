#include <iostream>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
using namespace std;

struct game_data{
    string hand_dealer[5];
	string hand_player[5];
	string game_result;
	int bet_amount;
	int bankroll_change;
};
void showhand(int n, int side, string hand[]){
    int i;
    if (side==0) {
        cout << "Dealer's hand: ";
        for (i=0;i<n;i++) cout<<hand[i]<<" ";
        cout<<endl;
    }
    if (side==1) {
        cout << "Your hand: ";
        for (i=0;i<n;i++) cout<<hand[i]<<" ";
        cout<<endl;
    }        
}

int hand_cal(string hand_string[5]){
    int i;
    int j;
    bool Ace = false;
    int total_point=0;
    string card[13]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    int card_int[13]={1,2,3,4,5,6,7,8,9,10,10,10,10};
    int hand[5];
    
    //把string转化成相应的int;
    for (i=0;i<5;i++){
        hand[i]=0;
        for (j=0;j<13;j++){
        if (card[j]==hand_string[i]) hand[i]=card_int[j];
        }
    }
    
    
    for (i=0; i<5; i++){
        if (hand[i]==1) Ace=true;
    }
    
    if (Ace == false){
        for (i=0; i<5; i++){
            total_point+=hand[i];
        }
    }
    
    else{
        int temp=0;
        int not_A=0;
        for (i=0; i<5; i++){
            if (hand[i]!=1){
                temp +=hand[i];
                not_A++;
            }
        }
        
        for (i=0; i<5-not_A;i++){
            if (temp<=10){
                temp +=11;
            }
            else temp++;
        }
        total_point=temp;
    }
 
    
    if (total_point<=21) return total_point;
    else return 0;
}

//hand compare 比较两副手牌大小
int hand_com(int dealer, int player, int bet){
    cout<<"Dealer Hand: "<<dealer<<endl;
    cout<<"Your Hand: "<<player<<endl;
    cout<<"Your Bet: "<<bet<<endl;
    
    if (dealer>player){
        cout<<"Game result: dealer wins."<<endl;
        cout<<"You lost $"<<bet<<" for this hand"<<endl;
        return 0;
    }

    if (dealer<player){
        cout<<"Game result: you win."<<endl;
        cout<<"You won $"<<bet<<" for this hand"<<endl;
        return 1;
    }  
    
    if (dealer == player){
        cout<<"Game result: draw."<<endl;
        return 2;
    }
    return 0;
}

int hand_com_new(int dealer, int player, int bet){
    
    if (dealer>player) return 0;

    if (dealer<player) return 1;
    
    if (dealer == player) return 2;

    return 0;
}


//major function
game_data game(int bet_amount)
{
    string card[13]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    string hand_dealer[5];
    string hand_player[5];
    int i;
    int n=0;
    bool stand=false;
    
    
    srand(time(NULL));
    
    for (i=0;i<2;i++) {
        hand_dealer[i]=card[rand()%13];
        hand_player[i]=card[rand()%13];
        n++;
    }
    
    showhand(2,0, hand_dealer);
    cout<<hand_cal(hand_dealer)<<endl;
    showhand(2,1, hand_player);
    cout<<hand_cal(hand_player)<<endl;

    while (n<5 and stand==false){
        string option;
        cout<<endl;
        cout<<"Hit or stand? Please enter 'hit' or 'stand'"<<endl;
        ifstream fin;
        string file="hitstand1.txt";
        fin.open(file);
        fin>>option;
        cout<<option<<endl;
        
        if (option == "hit"){
           hand_dealer[n]=card[rand()%13]; 
           hand_player[n]=card[rand()%13];
           n++;
           cout<<endl;
           cout<<"Your chose to hit"<<endl;
           showhand(2,0,hand_dealer);
           showhand(n,1,hand_player);
           cout<<endl;
           
           int q=hand_cal(hand_player);
           if (q==0){
               cout<<"You are busted"<<endl;
               cout<<endl;
               stand=true;
           }
        }
        else stand=true;
    }
    
    cout<<endl;
    cout<<"It's now dealer's turn"<<endl;
    cout<<endl;
    sleep(3);
    
    int m=2;
    stand=false;
    while(m<5 and stand==false){
        int p=hand_cal(hand_dealer);
        cout<<p<<endl;
        if (p<17 and p>0){
            cout<<"Dealer chose to hit"<<endl;
            hand_dealer[m]=card[rand()%13];
            m++;
            showhand(m,0,hand_dealer);
            showhand(n,1,hand_player);
            cout<<endl;
            sleep(3);
        }
        else if (p>=17){
            cout<<"Dealer chose to stand"<<endl;
            cout<<endl;
            stand=true;
            sleep(3);
        }
        else{
            stand=true;
            cout<<"Dealer is busted"<<endl;
            cout<<endl;
            sleep(3);
        }
    }
    struct game_data result;
    
    if(hand_com(hand_cal(hand_dealer),hand_cal(hand_player),bet_amount)==0) {
    result.game_result="Dealer";
    result.bankroll_change=bet_amount;
    }
    else if (hand_com_new(hand_cal(hand_dealer),hand_cal(hand_player),bet_amount)==1) {
    result.game_result="Player";
    result.bankroll_change=bet_amount;
    }
    else {
    result.game_result="Draw";
    result.bankroll_change=0;
    }
    for (i=0;i<n;i++) result.hand_dealer[i]=hand_dealer[i];
    for (i=0;i<n;i++) result.hand_player[i]=hand_player[i];
    result.bet_amount=bet_amount;
    return result;
}

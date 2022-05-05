#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include <unistd.h>
using namespace std;
int main()
{
	Bet bet;
	game_data data;
	cout<<string(35,'*')<<" Welcome to Blackjack game "<<setw(13)<<string(35,'*')<<endl;
	
	vector<string> win;
	string file_name;
	cout<<"input the file name for bet record: ";
	cin>>file_name;
	
	while (file_name.substr(file_name.find_last_of('.')+1) != "txt")
	{
		cout<<"invalid file name!"<<endl<<"re-enter the file name: ";
		cin>>file_name;
	}
	
	ofstream fout;
	fout.open(file_name);
	if (fout.fail())
	{
		cout<<"open failed";
		exit(1);
	}
	
	cout<<"Enter the total bet for tonight: ";
	cin>>bet.initial_bet;
	
	int round=1;
	double bet_amount;
	bet.current_bet=bet.initial_bet;
	while (true)
	{
		cout<<"bet for round "<<round<<": ";
		round++;
		cin>>bet_amount;
		
		if (bet.current_bet<bet_amount)
		{
			cout<<"Invalid bet amount"<<endl;
			cout<<"re-enter bet amout again: ";
			cin>>bet_amount;
		}
		
		data=game(bet_amount);
		cout<<"Your original bet: "<<bet.current_bet<<endl;
		bet.bet_change=data.bankroll_change;
		if (data.game_result=="Dealer") bet.current_bet-=bet.bet_change;
		else if (data.game_result=="Player") bet.current_bet+=bet.bet_change;
		cout<<"Your current bet: "<<bet.current_bet<<endl<<endl;
		bet.winner=data.game_result;
		
		
		win.push_back(bet.winner);
		fout<<bet.current_bet<<" "<<bet.bet_change<<endl;
		
		if (bet.current_bet<=0)
		{
			cout<<"Game over, thanks for comming.";
			break;
		}
		string command;
		cout<<"input command (continue/show record/quit): ";
		
		getline(cin>>ws,command);
		
		while (command!="quit" && command!="show record" && command!="continue")
		{
			cout<<"Invalid. Re-enter the command: ";
			getline(cin>>ws,command);
		}
		cout<<endl;
		
		if (command=="continue")
		{
			cout<<endl;
			cout<<string(35,'*')<<" New turn "<<setw(13)<<string(35,'*')<<endl;
			cout<<endl;
		}
		
		else if (command=="show record")
		{
			ifstream fin;
			fin.open(file_name);
			string word;
			double a,b,c;
			int cnt=1;
			cout<<"The Total_bet = "<<bet.initial_bet<<endl;
			cout<<string(20,'-')<<endl;
			
			while (getline(fin,word))
			{
				
				if (word=="") break;
				istringstream num(word);
				num>>b>>c;
				cout<<"Round "<<cnt<<": "<<"winner is "<<((win[cnt-1]=="Draw")?"No one":win[cnt-1])<<endl;
				cout<<setw(14)<<right<<"Previous bet: "<<fixed<<setprecision(2)<<b+c<<endl;
				cout<<setw(14)<<right<<"Bet change: "<<fixed<<setprecision(2)<<c<<endl;
				cout<<setw(14)<<right<<"Current bet: "<<fixed<<setprecision(2)<<b<<endl;
				cout<<string(20,'-')<<endl;
				cnt++;
			}
			cout<<string(35,'*')<<" New turn "<<setw(13)<<string(35,'*')<<endl;
			
		}
		else if (command=="quit")
		{
			cout<<"Thanks for comming, your left bet is: $"<<bet.current_bet;
			break;
		}
		
			
	}
	
}

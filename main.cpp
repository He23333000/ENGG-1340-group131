#include "test.h"
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
	game_data game(int bet_amount);
	{
	ifstream fin;
	string file2="textinput1.txt";
	fin.open(file2);
	Bet bet;
	game_data data;
	cout<<string(35,'*')<<" Welcome to Blackjack game "<<setw(13)<<string(35,'*')<<endl;
	
	vector<string> win;//for storing winner in each round
	
	string file_name;
	cout<<"input the output file name for bet record: ";
	fin>>file_name;
	cout<<file_name<<endl;
	
	while (file_name.substr(file_name.find_last_of('.')+1) != "txt") //error for file
	{
		cout<<"invalid file name!"<<endl<<"re-enter the output file name: ";
		fin>>file_name;
		cout<<file_name<<endl;
	}
	cout<<endl;
	
	ofstream fout;
	fout.open(file_name);
	if (fout.fail())
	{
		cout<<"open failed";
		exit(1);
	}
	
	cout<<"Enter the total bet for tonight: ";
	fin>>bet.initial_bet;
	cout<<bet.initial_bet<<endl<<endl;
	cout<<string(15,'*')<<" GAME STARTS "<<setw(13)<<string(15,'*')<<endl;
	cout<<endl;
	
	int round=1;
	double bet_amount;
	bet.current_bet=bet.initial_bet;
	while (true) //error for bet
	{
		cout<<"bet for round "<<round<<": ";
		round++;
		fin>>bet_amount;
		cout<<bet_amount<<endl;
		
		if (bet.current_bet<bet_amount)
		{
			cout<<"Invalid bet amount"<<endl;
			cout<<"re-enter bet amout again: ";
			fin>>bet_amount;
			cout<<bet_amount<<endl;
		}
		cout<<string(30,'-')<<endl; 
		
		data=game(bet_amount); //update the struct in each round
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
		
		getline(fin>>ws,command); //input command with getline
		cout<<command<<endl;
		
		while (command!="quit" && command!="show record" && command!="continue")
		{
			cout<<"Invalid. Re-enter the command: ";
			getline(fin>>ws,command);
			cout<<command<<endl;
		}
		cout<<endl;
		int determination_of_break=0;
		while (true)
		{
			
			if (command=="continue")
			{
				cout<<endl;
				cout<<string(35,'*')<<" New turn "<<setw(13)<<string(35,'*')<<endl;
				cout<<endl;
				break;
			}
			
			else if (command=="show record")
			{
				ifstream input;
				input.open(file_name);
				string word;
				double a,b,c;
				int cnt=1;
				cout<<"The Total_bet = "<<bet.initial_bet<<endl;
				cout<<string(20,'-')<<endl;
				
				while (getline(input,word))
				{
					
					if (word=="") break;
					istringstream num(word);
					num>>b>>c;
					cout<<"Round "<<cnt<<": "<<"winner is "<<((win[cnt-1]=="Draw")?"No one":win[cnt-1])<<endl;
					double previous;
					cout<<setw(14)<<right<<"Previous bet: ";
					if (win[cnt-1]=="Dealer" || win[cnt-1]=="Draw") previous=b+c;
					else if (win[cnt-1]=="Player") previous=b-c;
					cout<<fixed<<setprecision(2)<<previous<<endl;
					cout<<setw(14)<<right<<"Bet change: "<<fixed<<setprecision(2)<<c<<endl;
					cout<<setw(14)<<right<<"Current bet: "<<fixed<<setprecision(2)<<b<<endl;
					cout<<string(20,'-')<<endl;
					cnt++;
				}
				cout<<"input command (continue/show record/quit): ";
		
				getline(fin>>ws,command);
				cout<<command<<endl;
				
				while (command!="quit" && command!="show record" && command!="continue")
				{
					cout<<"Invalid. Re-enter the command: ";
					getline(fin>>ws,command);
					cout<<command<<endl;
				}
				cout<<endl;
				if (command=="continue")
				{
					cout<<string(35,'*')<<" New turn "<<setw(13)<<string(35,'*')<<endl;
					cout<<endl;
					break;
				}
				else if (command=="quit")
				{
					cout<<"Thanks for comming, your left bet is: $"<<bet.current_bet;
					determination_of_break=1;				
					break;
				}
				
				
			}
			
			else if (command=="quit")
			{
				cout<<"Thanks for comming, your left bet is: $"<<bet.current_bet;
				break;
			}
			if (determination_of_break==1) break;
		}
			
		if (determination_of_break==1) break;
	}
	
}
	
}

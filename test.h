#ifndef test
#define test
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

struct game_data{
    string hand_dealer[5];
	string hand_player[5];
	string game_result;
	int bet_amount;
	int bankroll_change;
};

struct Bet
{
	double initial_bet=0;
	double bet_change=0;
	double current_bet=0;
	string winner;
};

void showhand(int n, int side, string hand[]);
int hand_cal(string hand_string[5]);
int hand_com(int dealer, int player, int bet);
int hand_com_new(int dealer, int player, int bet);
game_data game(int bet_amount);
int main();

#endif

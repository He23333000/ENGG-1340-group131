#ifndef test
#define test

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

game_data game(int bet_amount)

#endif

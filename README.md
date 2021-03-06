``` 
Group Number: 131
Group Member: Xu Chenning (3035771804)
              He Jinliang (3035949279)
              
Project Game: Blackjack 
```
# reminder
Acamemy server 21 is used for testing procedure

# Blackjack
Blackjack (formerly Black Jack and Vingt-Un) is a casino banking game, and we will implement c++ to create this text-based player-to-machine game.

# Rules
* different cards will gain different number of points
  1. Cards with numbers – from 2 to 10 – gain respective points (have their face value).
  2. Jack (J), Queen (Q) and King (K) gain 10 points.
  3. Ace (A) might be counted as 11 or 1 point, depending on the value needed for a best hand.
  
* The goal of blackjack is to beat the dealer's hand without going over 21.

* Each player starts with two cards, one of the dealer's cards is hidden until the end.

* To 'Hit' is to ask for another card. To 'Stand' is to hold your total and end your turn.

* Dealer will hit until his/her cards total 17 or higher.

* Winning condition
  1. If the dealer's hand goes over 21 the dealer bust (lose), and you win regardless of your hand.
  2. If your hand is greater than the dealer's and is not exceeding 21.

* losing condition
  1. If you go over 21 you bust (lose), and the dealer wins regardless of the dealer's hand.
  2. If the dealer's hand is greater than yours and is not exceeding 21.
 
* If you are dealt 21 from the start (Ace & 10), you got a blackjack.

* Winning consequence
  1. If you win without blackjack, the dealer will give you all his bet for a single play. 
  2. If you win with blackjack, the dealer will give you 1.5 x the amount of his bet for a single play.
 
* losing consequence
  1. If the dealer wins without blackjack, you will give the dealer all his bet for a single play. 
  2. If the dealer wins with blackjack, you will give the dealer 1.5 x the amount of his bet for a single play.



# Process
Assumption: the allocation of cards is completely a random process.
1. There are decks of 52 cards in total and are shuffled randomly before each round
2. Initially the system allocates 2 cards (both are visible) to the player and 2 cards (1 visible and 1 invisible to the player) to the dealer.  
3. player has to decide whether to 'Hit' a new card or not, and this extraction process can be repeated until the player chooses to 'Stand', stating that the winning or losing condition stated in the rules is not reached.
4. The dealer will automatically decide to 'Hit' or to 'Stand'.
5. If the player wins, the correspoinding bet is given from the dealer to the player, otherwise, it is the reverse.
6. Once you enter 'N' for no, the game will end, and the overall gain or loss will be displayed.


# Features
1. 2 Data structures are used for recording game status and bet change for a single round.
2. It allows a full record of game status as the game is processing. We will keep a record of the result of every game and the changes in the plays’ bankroll. file input for gamer input and file output for recording previous records will be applied to achieve this feature.
3. It deploys an automatic dealer. We completely mock the behavior of blackjack dealers in casinos. The dealer will assign cards randomly for each game and operate according to the game rule. Generation of random game sets or events will be used for card assignment and program codes in multiple files will be applied to modulize each function of the deal's tasks.
4. Programs are compiled in multiple files including .h/.cpp/.txt, and then compiled and converged through makefile.
5. Dynamic array, vectors are used to store winners since we don't know how many times you will play, combined with the file storage, we can update the previous features more completely.
6. Checking data validation. If the input data including file text, amount of bet, and command, are not the data we want, we'll ask the player to retype the input information to prevent any possible input errors.

# Assumptions 
1. Random features have been implemented. However, it can't be ensured to generate different outputs under the same data inputs.
2. This program assumes that the user will input the data in the correct format. For example, when asked for how much money they have, we assume that the user will input 4000 instead of "four thousand".
3. The program will only terminate once the user chooses to exit or the bet has used up.
4. The dealer has a greater chance to win due to programming calculation.
5. There is a limited number of file inputs, but the program can function successfully under all testing conditions.

# Compilation and execution instruction
1. Download the source files on GitHub and export them to Linux.
2. Once exported to Linux, simply type in "make" and the program will be compiled.
3. Type "./program" to execute the program.




# Blackjack
Blackjack (formerly Black Jack and Vingt-Un) is a casino banking game, and we will implement c++ to create this text-based player-to-machine game.

# Rules
* different cards will gain different number of points
  Cards with numbers – from 2 to 10 – gain respective points (have their face value).
  Jack (J), Queen (Q) and King (K) gain 10 points.
  Ace (A) might be counted as 11 or 1 point, depending on the value needed for a best hand.
  
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

* Blackjack usually means you win 1.5 the amount of your bet. Depends on the casino.

* Winning consequence
  If you win without blackjack, the dealer will give you all his bet for a single play. 
  If you win with blackjack, the dealer will give you 1.5 x the amount of his bet for a single play.
 
* losing consequence
  If the dealer wins without blackjack, you will give the dealer all his bet for a single play. 
  If the dealer wins with blackjack, you will give the dealer 1.5 x the amount of his bet for a single play.



# Process
Assumption: the allocation of cards is completely a random process.
1. There are decks of 52 cards in total and are shuffled randomly before each round
2. Initially the system allocates 2 cards (both are visible) to the player and 2 cards (1 visible and 1 invisible to the player) to the dealer.  
3. player has to decide whether to 'Hit' a new card or not, and this extraction process can be repeated until the player chooses to 'Stand', stating that the winning or losing condition stated in the rules is not reached.
4. The dealer will automatically decide to 'Hit' or to 'Stand'.
5. If the player wins, the correspoinding bet is given from the dealer to the player, otherwise, it is the reverse.
6. Once you lose all bets, you can't play anymore.





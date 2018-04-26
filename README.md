# pic10c-assignment1: Siete y Medio
## Layton Webber

This program is made to learn to use Git version control software in the development of a program. The underlying program being written will be able to play the card game '_siete y medio_'. The rules can be found at the [Wikipedia entry](https://en.wikipedia.org/wiki/Sette_e_mezzo), but are summarized below.

* A player makes a bet about whether they will win the next hand playing against the dealer.
* Next the player and dealer each draw one card to begin.
* The player then has the option to keep drawing cards until they either bust (go over 7 1/2) or choose to not draw another card.
* The dealer then plays, drawing cards as long as their total is below 5 1/2.

The outcomes after a round and their results are as follows:
1. The player has a higher total than dealer, or dealer busts: The player doubles their bet.
2. The player and dealer tie: The player keeps their bet.
3. The player has a lower total, or the player busts: The player loses their bet.
4. The player and dealer both bust: The player loses their bet.

The game is played using a ['_Spanish baraja_'](http://en.wikipedia.org/wiki/Spanish_playing_cards) which is an old style of playing card from Spain. The deck is made up of four suits bastos _(clubs)_, oros _(golds)_, copas _(cups)_, espadas _(swords)_, and each suit has ranks 1-7 and 3 face cards the sota _(jack)_, caballo _(knight)_, rey _(king)_. 

In _siete y medio_, the values of the 1-7 ranks are face values, but sota, caballo, rey are each worth 0.5.

The player starts with $100, and the goal is to reach $1000 without dropping to $0.
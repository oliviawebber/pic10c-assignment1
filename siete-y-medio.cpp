#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "cards.h"
using namespace std;

// Global constants (if any)
const int STARTING_MONEY = 100;
const int PRINT_WIDTH = 20;

// Non member functions declarations (if any)
int get_bet(const Player&);
ostream& operator<<(ostream&, const Hand&);

// Non member functions implementations (if any)
int get_bet(const Player& p1) {
    int bet;
    bool valid_bet = false;
    while (!valid_bet) { 
        cout << "You have $" << p1.get_money() << ". Enter bet: ";
        cin >> bet;
        if(bet <= p1.get_money()) {
            valid_bet = true;
        }
        else {
            cout << "Sorry you must enter a bet that is less than your current money.\n";
        }
    }
    return bet;
}

ostream& operator<<(ostream& out, const Hand& h1) {
    std::vector<Card> cards(h1.get_hand());
    for(size_t i = 0; i < cards.size(); ++i) {
        out << setw(PRINT_WIDTH) << (cards[i].get_spanish_rank() + " de " + cards[i].get_spanish_suit());
        out << setw(PRINT_WIDTH) << (cards[i].get_english_rank() + " of " + cards[i].get_english_suit());
        out << endl;
    }
    return out;
}


// Stub for main
int main(){
    /* --STATEMENTS-- */
    Player p1(STARTING_MONEY);
    Hand player_hand;
    Hand dealer_hand;
    while(p1.get_money() > 0) {
        int player_bet = get_bet(p1);
        cout << "Your cards:\n";
        cout << player_hand;
        cout << "Your total is " << player_hand.get_total() << ". Do you want another card?(y/n) ";
        char another_card;
        cin >> another_card;
        while(another_card != 'y' || another_card != 'n') {
            cout << "Please enter either y or n: ";
            cin >> another_card;
        }
    }
    return 0;
}

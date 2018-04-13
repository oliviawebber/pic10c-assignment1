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
ostream& operator<<(ostream&, const Card&);

// Non member functions implementations (if any)
int get_bet(const Player& p1) {
    int bet;
    bool valid_bet = false;
    while (!valid_bet) { 
        cout << "You have $" << p1.get_money() << ". Enter bet: ";
        cin >> bet;
        if(bet <= p1.get_money() && bet > 0) {
            valid_bet = true;
        }
        else {
            cout << "Sorry you must enter a bet that is less than your current money and greater than zero.\n";
        }
    }
    return bet;
}

ostream& operator<<(ostream& out, const Hand& h1) {
    std::vector<Card> cards(h1.get_hand());
    for(size_t i = 0; i < cards.size(); ++i) {
        out << cards[i];
    }
    return out;
}

ostream& operator<<(ostream& out, const Card& c1) {
    out << setw(PRINT_WIDTH) << (c1.get_spanish_rank() + " de " + c1.get_spanish_suit());
    out << setw(PRINT_WIDTH) << ("(" + c1.get_english_rank() + " of " + c1.get_english_suit() + ")");
    out << endl;
    return out;
}

// Stub for main
int main(){
    /* --STATEMENTS-- */
    Player p1(STARTING_MONEY);
    while(p1.get_money() > 0 && p1.get_money() < 1000) {
        Hand player_hand;
        Hand dealer_hand;
        int player_bet = get_bet(p1);

        char another_card = 'q';
        while(another_card != 'n') {
            cout << "Your cards:\n";
            cout << player_hand;
            if(player_hand.get_total() > 7.5) {
                cout << "Your total is " << player_hand.get_total() << endl;
                another_card = 'n';
                break;
            }
            cout << "Your total is " << player_hand.get_total() << ". Do you want another card?(y/n) ";
            cin >> another_card;
            while(another_card != 'y' && another_card != 'n') {
                cout << "Please enter either y or n: ";
                cin >> another_card;
            }
            if(another_card == 'y') {
                player_hand.add_card();
                cout << "New card:\n";
                cout << player_hand.get_hand()[player_hand.get_hand().size() - 1] << endl;
            }
        }

        while(dealer_hand.get_total() < 5.5) {
            cout << "Dealer's cards:\n";
            cout << dealer_hand;
            cout << "The dealer's total is " << dealer_hand.get_total() << ".\n";
            dealer_hand.add_card();
            cout << "\nNew card:\n";
            cout << dealer_hand.get_hand()[dealer_hand.get_hand().size() - 1] << endl;
        }
        cout << "Dealer's cards:\n";
        cout << dealer_hand;
        cout << "The dealer's total is " << dealer_hand.get_total() << ".\n";

        int p_total = player_hand.get_total();
        int d_total = dealer_hand.get_total();
        bool p_bust = p_total > 7.5;
        bool d_bust = d_total > 7.5;
        bool p_beat_d = p_total > d_total;

        if((p_beat_d || d_bust) && !p_bust) {
            cout << "\nYou win " << player_bet << ".\n\n";
            p1.update_money(player_bet);
        }
        else if(p_total == d_total) {
            cout << "\nYou tie.\n\n";
        }
        else {
            cout << "\nYou lose " << player_bet << ".\n\n";
            p1.update_money(-player_bet);
        }
    }
    if(p1.get_money() < 0) {
        cout << "You have $0. Game Over!\nCome back when you have more money.\n\nBye!";
    }
    else {
        cout << "Congratulations. You beat the casino!\n\nBye!";
    }

    return 0;
}

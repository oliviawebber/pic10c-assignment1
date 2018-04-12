#include "cards.h"

// All hands should start with one card
Hand::Hand() {
    add_card();
}

// Generate new card and add it to hand
void Hand::add_card() {
    Card c1;
    cards.push_back(c1);
}

// Return a reference to the hand
const std::vector<Card>& Hand::get_hand() const {
    return cards;
}

// Loop over all the cards and get the total points for the hand
double Hand::get_total() const {
    double total = 0;
    for(size_t i = 0; i < cards.size(); ++i) {
        int rank = cards[i].get_rank();
        if(rank < 10) {
            total += rank;
        }
        else {
            total += 0.5;
        }
    }
    return total;
}

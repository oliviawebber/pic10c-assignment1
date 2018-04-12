#include "cards.h"

//Constructor player starts with a certain amount of money
Player::Player(int m) : money(m) {}

// By passing positive vs negative amounts this function can both lower and raise
// the players money total
void Player::update_money(int amt) {
    money += amt;
}

// Accessor for money private field
int Player::get_money() const {
    return money;
}
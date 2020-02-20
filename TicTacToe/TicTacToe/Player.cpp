#include "Player.h"
#include <iostream>

Player::Player() {
	this->letter = 'X';
	this->wins = 0;
	this->losses = 0;
}

Player::~Player() {

}

Player::Player(char letter) {
	this->letter = letter;
	this->wins = 0;
	this->losses = 0;
}

void Player::addWin() {
	wins++;
}

void Player::addLoss() {
	losses++;
}

int Player::getLosses() {
	return losses;
}

int Player::getWins() {
	return wins;
}

char Player::getLetter() {
	return letter;
}

int Player::getMove() {
	int move;
	std::cout << "Where would you like to place your " << letter << " [0-8]:";
	std::cin >> move;
	
	return move;
}
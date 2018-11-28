#include "Player.h"
#include <iostream>
using namespace std;

void Player::setName(string name){
	this->name=name;
}
string Player::getName(){
	return this->name;
}

void Player::setActive(bool trueOrFalse){
	this->active = trueOrFalse;
}

bool Player::isActive(){
	return this->active; 
}

int Player::getNrubies() const{
	return this->nRubies;
}

Side Player::getSide(){
	return mSide;
}

void Player::setSide(Side s){
	this->mSide = s;
}

/*void Player::addReward(const Reward&){
	this->nRubies+=Reward;
}*/

void Player::setDisplaymode(bool endOfGame){
	Player player;
	if(endOfGame==false){
		cout<<player.getName()<<": "<<endl;
	}else{
		cout<<player.getName()<<": "<<player.getNrubies()<<" rubis"<<endl;
	}
	}


#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
using namespace std;

class Card{
	public:
		enum FaceAnimal{Crabe, Pingouin, Octopus, Turtle, Walrus};
		enum FaceBackground{Green, Mauve, Blue, Yellow, Red};
	private:
		FaceAnimal animal;
		FaceBackground background;
	public:
		Card(){
		}
		string cardConvertor(Card::FaceAnimal a){
			std::string str1;
			switch(a){
				case Card::Crabe: str1 = "C"; break;
				case Card::Walrus: str1 = "W"; break;
				case Card::Octopus: str1 = "O"; break;
				case Card::Pingouin: str1 = "P"; break;
				case Card::Turtle: str1 = "T"; break;
			}
		return str1;
		}
		string cardConvertor(Card::FaceBackground b){
			std::string str2;
			switch(b){
				case Card::Red: str2 = "r"; break;
				case Card::Yellow: str2 = "y"; break;
				case Card::Mauve: str2 = "m"; break;
				case Card::Blue: str2 = "b"; break;
				case Card::Green: str2 = "g"; break;
			}
		return str2;
		}
		
		Card(Card::FaceAnimal, Card::FaceBackground);
		Card(const Card&);
		void affiche();
		FaceAnimal getAnimal() const { return animal; }
  		FaceBackground getBackground() const { return background; }
		
};

#endif

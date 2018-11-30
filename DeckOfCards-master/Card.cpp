#include "Card.h"


//Card(FaceAnimal, FaceBackground), cree une carte contenant une des enum de FaceAnimal et FaceBackground
Card::Card(FaceAnimal a, FaceBackground b) : animal(a), background(b) {
}

//Card(const Card&), retourne les valeurs contenues d'une carte
Card::Card(const Card& c) : animal(c.getAnimal()), background(c.getBackground()) {}

void Card::affiche(){
	FaceAnimal a;
	FaceBackground b;
	a = this->getAnimal();
	b = this->getBackground();
	
	std::string str1, str2, str;
	str1 = cardConvertor(a);
	str2 = cardConvertor(b);
	for(int i=0; i<3;i++){	
		int k=1;		
		for(int j=0; j<3; j++){
			
			if(i==1 && j==1){
				cout<<str1;
			}else{
				cout<<str2;
			
			}
			if(k==3){
				cout<<endl;
			}
			k++;		
		}
	}
}


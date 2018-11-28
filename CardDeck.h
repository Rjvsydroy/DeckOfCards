#ifndef CARDDECK_H
#define CARDDECK_H
#include<ctime>
#include<cstdlib>
#include "Card.h"
/*class CardDeck
{
	private:
		void shuffle();
		bool isEmpty();
		
	public:
		CardDeck(){
		}
		static CardDeck& make_cardDeck(){
			CardDeck cardDeck;
			Card::FaceAnimal a;
			Card::FaceBackground b;
			int count =0;
			for(int i =0; i<5; i++){
				for(int k=0; k<5; k++){
					Card card(Card::FaceAnimal(a+i),Card::FaceBackground(b+k));
					cardDeck.deck[count].affiche();
					cardDeck.deck[count] = card;
					count++;
				}
			}
			return cardDeck;
	}
	
	private:
		Card deck[25];
};*/

#endif

#include <iostream>
#include <string>
#include "player.h"
#include "Reward.h"
#include "Card.h"
#include "Deck.h"
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>


////////////////////////////
class Carte{

	public:
		enum FaceAnimal{Crabe, Pingouin, Octopus, Turtle, Walrus};
		enum FaceBackground{Green, Mauve, Blue, Yellow, Red};
		Carte(){	
		}
		Carte(Carte::FaceAnimal animal,Carte::FaceBackground){	
			this->animal = animal;
			this->background = background; 
		}
		string cardConvertor(Carte::FaceAnimal a){
			std::string str1;
			switch(a){
				case Carte::Crabe: str1 = "C"; break;
				case Carte::Walrus: str1 = "W"; break;
				case Carte::Octopus: str1 = "O"; break;
				case Carte::Pingouin: str1 = "P"; break;
				case Carte::Turtle: str1 = "T"; break;
			}
		return str1;
		}
		string cardConvertor(Carte::FaceBackground b){
			std::string str2;
			switch(b){
				case Carte::Red: str2 = "r"; break;
				case Carte::Yellow: str2 = "y"; break;
				case Carte::Mauve: str2 = "m"; break;
				case Carte::Blue: str2 = "b"; break;
				case Carte::Green: str2 = "g"; break;
			}
		return str2;
		}
		FaceAnimal getAnimal(){
			return this->animal;
		}
		FaceBackground getBackground(){
			return this->background;
		}
		string affiche(){
			FaceAnimal a;
			FaceBackground b;
			a = this->getAnimal();
			b = this->getBackground();
		
			std::string str1, str2, strfinal;
			str1 = cardConvertor(a);
			str2 = cardConvertor(b);
			for(int i=0;i<3;i++){
				for(int k=0;k<3;k++){
					if(i==1 and k==1){
						strfinal+=str1;
					}else{
					strfinal+=str2;
					}	
				}
			strfinal+='\n';
			}	
		return strfinal;
		}
		
	private:
		Carte::FaceAnimal animal;
		Carte::FaceBackground background;
		
	friend class DeckCarte;
};
template <class C>
class Deckk{
	protected:
	vector<C> d;
	public:
		void shuffle(){
			vector<C> deck;
			random_device rd;
			mt19937 g(rd());
			shuffle(deck.begin(),deck.end(),g);
		}
		C* getNext(){
			vector<C> deck;
			typename std::vector<C>::iterator it=deck.begin();
			if(deck.empty()){
				cout<<" empty deck";
			}else{
				//code
			}
		}
		//erreur
		bool isEmpty(){
			vector<C> deck;
			return deck.empty();
		}
};
class DeckCarte: public Deckk<Carte>{
	private:
		vector<Carte> d;
		int currentCard;
	public:
		static DeckCarte& make_CardDeck(){
			DeckCarte deck;
		
  			for (int face = 0; face != 5; ++face){
    			for (int back = 0;back != 5; ++back){
      				deck.d.push_back(Carte(Carte::FaceAnimal(face), Carte::FaceBackground(back)));
      			}
      			
      		}    
      		cout<<deck.d.empty()<<endl;
			return deck;
		}
};
class DeckReward: public Deckk<Reward>{
	public:
		vector<Reward> d;
	public:
		static DeckReward& make_RewardDeck(){
			DeckReward *deck;
			vector<Reward> d;
			for(int i=0;i<3;i++){
				deck->d.push_back(Reward(1));
			}
			for(int i=0;i<2;i++){
				deck->d.push_back(Reward(2));
			}
			deck->d.push_back(3);
			deck->d.push_back(4);
			cout<<deck->d.empty();
			return *deck;
		}
};
/////////////////////////////////////////////
int main(){	
	DeckCarte deck;
	deck.make_CardDeck();
	DeckReward deck1;
	deck1.make_RewardDeck();
    return 0;
}

	


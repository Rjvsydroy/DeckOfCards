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
#include <windows.h>
#include <map>

////////////////////////////
class Carte{
		
	public:
		enum FaceAnimal{Crabe, Pingouin, Octopus, Turtle, Walrus};
		enum FaceBackground{Green, Mauve, Blue, Yellow, Red};
		vector<string> d;
		
		Carte(Carte::FaceAnimal animal,Carte::FaceBackground background){	
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
		string row(int rowNum) {
			FaceAnimal a;
			FaceBackground b;
			a = this->getAnimal();
			b = this->getBackground();
		
			std::string str1, str2, strfinal;
			str1 = cardConvertor(a);
			str2 = cardConvertor(b);
			if(rowNum == 0 || rowNum == 2) {
				return str2+str2+str2;
			} else {
				return str2+str1+str2;
			}
		}
		void print() {
			Carte c;
			for(int row = 0; row<3; ++row) {
				
				string rowString = c.row(row);
				cout << rowString << endl;
			}
		}
		string affiche(int n){
			Carte c;
			vector<string> d;
			FaceAnimal a;
			FaceBackground b;
			a = this->getAnimal();
			b = this->getBackground();
		
			std::string str1, str2, strfinal;
			str1 = cardConvertor(a);
			str2 = cardConvertor(b);
			if(n==0 || n==2){
				return str2+str2+str2;
			}else{
				return str2+str1+str2;
			}
		}
		
	private:
		Carte(){
			this->faceUp=false;
		}
		Carte::FaceAnimal animal;
		Carte::FaceBackground background;
		bool faceUp;
		
		
	friend class DeckCarte;
};
/*template <class C>
class Deckk{
	protected:
		static vector<C> d;
		static C* currentCard;
		
	public:
		virtual void shuffle() = 0;
		virtual C getNext() = 0;
		virtual bool isEmpty() = 0;
		
};*/
class DeckCarte{//: public Deckk<Carte>{
	public:
		vector<Carte> d;
		int current;
		Carte* currentCard;
	public:
		void shuffle(){
	random_shuffle(d.begin(), d.end());
	}

		bool isEmpty() {
			if (currentCard == nullptr) {
				return true;
			}else{
			return false;
			}
		}
	
		Carte getNext(){
			Carte nextCard = *currentCard;
			d.pop_back();
			currentCard = &(d.back());
			return nextCard;
		}
			
			
		
		static DeckCarte& make_CardDeck(){
			DeckCarte *deck;
			vector<Card> d;
  			for (int face = 0; face != 5; ++face){
    			for (int back = 0;back != 5; ++back){
      				deck->d.push_back(Carte(Carte::FaceAnimal(face), Carte::FaceBackground(back)));
      			}
      			
      		}    
    
			return *deck;
		}
};
class DeckReward{//: public Deckk<Reward>{
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
class Board{
	public:
		string b1[25];
	public:
		
		enum Letter{A,B,C,D,E};
		enum Number{one=1,two=2,three=3,four=4,five=5};
		
		multimap<Board::Letter, string> letter; 
		multimap<Board::Number, string> number;   

    	
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD CursorPosition;
		void gotoXY(int x, int y) {
			CursorPosition.X = x; 
			CursorPosition.Y = y; 
			SetConsoleCursorPosition(console,CursorPosition); 
		}
		Board(){
		
			DeckCarte deck;
			deck.make_CardDeck();
			deck.shuffle();
			vector<Carte>::iterator it=deck.d.begin();
			
			int k=0;
			
				while(it!=deck.d.end()){
					for(int x=0; x<5;x++) {
						for(int n=0; n<3; n++){
							if(x==2&&k==2){
								gotoXY(x*4+2,k*4+n);
								cout<<"   ";	
							}else{
							
							gotoXY(x*4+2,k*4+n);
							
							letter.insert(make_pair(Board::Letter(k), (*it).affiche(n)));
							number.insert(make_pair(Board::Number(x),(*it).affiche(n)));
							
							cout<<(*it).affiche(n);
						}}
			
						it++;
					}k++;
		}
		cout<<endl;
		
				
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
		string afficheLetter(int n){
			Board::Letter *a;
			int b = *a;
		
		}
		string afficheNumber(int n){
			
		}
		bool isFaceUp( const Letter&, const Number&) const {};
		bool turnFaceUp( const Letter&, const Number& ){};
		bool turnFaceDown( const Letter&, const Number& ) {};
		Card* getCard( const Letter&, const Number& ) {};
		void setCard( const Letter&, const Number&, Card* ){};
		void reset();
};
/////////////////////////////////////////////






int main(){	
	/*DeckCarte deck;
	deck.make_CardDeck();
	DeckReward deck1;
	deck1.make_RewardDeck();
	cout<<endl<<deck1.d.empty()<<endl<<cout<<deck.d.empty();
	cout<<deck.d.empty();*/
	
	/*vector<int> d;
	int current;
	d.push_back(5);
	d.push_back(4);
	cout<<d[current];
	*/Board board;
	multimap<Board::Letter,string> m= board.letter;
	multimap<Board::Number,string> n= board.number;
	/*for(auto it=m.begin();it!=m.end();it++){
		cout<<it->first<<it->second<<" ";
	}*/
	auto it1 = m.begin();
	auto it2 = n.begin();
	for(int i=0; i<6; i++){
		
	cout<<it1->second;
	it1++;
	cout<<endl;
	
	}
	cout<<endl;
	for(int i=0;i<6;i++){
		cout<<it2->second;
		it2++;
		cout<<endl;
	}
	
	
	/*Carte c(Carte::Crabe,Carte::Blue);
	//cout<<d.getNext().affiche();
	/*cout<<c.affiche(3);*/
    return 0;
}

	


#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;
enum Side{top,bottom,lft,rghtZZ};
class Player
{
	string name;
	bool active;
	int nRubies;
	Side mSide;
	
	public:
		Player(){
			this->name ="Tom";
			this->active = false;
			this->nRubies = 0;
			this->mSide =top;
		}
		void setName(string);
		string getName();
		void setActive(bool);
		bool isActive();
		int getNrubies() const;
		Side getSide();
		void setSide(Side s);
		//void addReward(const Reward&);
		void setDisplaymode(bool);
};

#endif

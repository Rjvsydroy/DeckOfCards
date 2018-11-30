#ifndef REWARD_H
#define REWARD_H

class Reward{	
	private:
		int reward;
	
	public:
		
		Reward(){}
		Reward(int reward){
			this->reward=reward;
		}
		
	friend Reward operator+(const Reward &r1, const Reward &r2);

};

#endif

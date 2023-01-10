#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
class GAME{
	int total_players,t1_hits,t2_hits,num1,num2;
	void check_pair_generator(){
		num1=rand()%100+1,num2=rand()%100+1;
		cout<<"Pair of Numberts:\nNumber1: "<<num1<<"\nNumber2: "<<num2<<endl;
		if (num1==num2){
		cout<<"Enemy got hit by your team!\n\n";
		t1_hits++;
		}
		else{
		cout<<"You got hit by the enemy team!\n\n";
		t2_hits++;
		}
	}
public:
	GAME(){
		srand(time(NULL));
		total_players=rand()%10+1,t1_hits=0,t2_hits=0;
	}
	void play_game(){
		cout<<"Total No. of Players in your team: "<<total_players<<"\n\n";
		for (unsigned int i=0;i<total_players;i++){
		check_pair_generator();
		}
		if (t1_hits>t2_hits)
		cout<<"Game Over! You Won!!";
		else if(t1_hits<t2_hits)
		cout<<"Game Over! You Lost!!";
		else
		cout<<"Game Over! Draw!";
	}
};
int main(){	
	GAME match_the_pairs;
	match_the_pairs.play_game();
	return 0;
}

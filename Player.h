#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
using namespace std;

// to let player enter their name
class Player 
{
	protected:
    	string playerName;  

	public:
		
		
		Player () // constructor
		{
			playerName = " ";
		}
		
    	void setName(const string& name)  // to set player name
		{
        	playerName = name;
    	}

    	string getName() const // to get player name
		{
        	return playerName;
    	}    	
} ;

#endif
#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include <iostream>
#include <iomanip>
#include "Player.h"
#include "Item.h"

using namespace std;

class GamePlay : public Player, public Item
{
	private:
		int totalPoints;  // to calculate total score
		int currentPoints;  // to tell current score for each round
		DynIntStack<string> foundItem1; //found item by player1
    	DynIntStack<string> foundItem2;//found item by player2
		
	public:
		GamePlay ()   // constructor
		{
			totalPoints=0;
			currentPoints=0;
		}
		
		int getCurrentPoints(string item, bool status)  // pass item and status of the answer to decide either get points or not for each round
		{
			if (status)
				currentPoints = getItemPoints(item);
			else
				currentPoints = 0;
			return currentPoints;	
		}
		
		void calcTotalPoints ()  // calculate total score 
		{	
			totalPoints +=  currentPoints;
		}
		
		int getTotalPoints () // return total score
		{
			return totalPoints;
		}
		
		void displayPoints ()  // to display both player total score
		{
			cout << getName() << "'s points: " << getTotalPoints() << endl;
		}
		
    	void stackFoundItemPlayer1 (bool found, string s)  // to add item guess correctly by player into the stack
		{
			if (found)
				foundItem1.push(s);
			
			//deleteItem(s);		
		}
		
		void stackFoundItemPlayer2 (bool found, string s)  // to add item guess correctly by player into the stack
		{
			if (found)
				foundItem2.push(s);
	
			//deleteItem(s);		
		}
		
		void displayFoundItemPlayer1 (string name) // display item that have been quess correctly by player
		{
			int point;
			cout << "\n--------------------------------------------------------------------";
			string i;
			cout << "\nHere items found by " << name << endl;
			cout <<"\n--------------------------------------------------------------------\n";			 
			while (!foundItem1.isEmpty())
			{
				foundItem1.pop(i);
				cout << setw(10) << i << setw(10) << endl;
			}
	
		}
		
		void displayFoundItemPlayer2 (string name) // display item that have been quess correctly by player
		{	
			int point;
			cout << "\n--------------------------------------------------------------------";
			string i;		
			cout << "\nHere items found by " << name << endl;
    		cout <<"\n--------------------------------------------------------------------\n";	
			while (!foundItem2.isEmpty())
			{
				foundItem2.pop(i);
				cout << setw(10) << i << setw(10)  << endl;
			} 		
		}
    	   
		friend void determineWinner(GamePlay& player1, GamePlay& player2)  // to determine which player win the game by compare their total points
		{
			if (player1.getTotalPoints() == player2.getTotalPoints())
				cout << "It's a tie!" << endl;
			
    		else 	
			{
				cout << "Congratulations, " ;
				
				if (player1.getTotalPoints() > player2.getTotalPoints()) 
					cout << player1.getName() ;
				
    			else if (player1.getTotalPoints() < player2.getTotalPoints()) 
        			cout << player2.getName() ;
        			
        		cout << " your cunning and tenacity have prevailed over the malevolent forces that reside within the House of Secrets." 
					 << "\nYou shall forever be remembered as the one who triumphed over the darkness and emerged as the true embodiment of a master detective.";
			}
		}
};

#endif
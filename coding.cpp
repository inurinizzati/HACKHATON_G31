#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
using namespace std;

class Player 
{
	protected:
    	string playerName;

	public:

    	Player(const string& name) 
		{
        	playerName = name;
    	}

    	string getName() const 
		{
        	return playerName;
    	}
    	
} ;

#endif

#ifndef SCENE_H
#define SCENE_H
#include <iostream>
using namespace std;

class Scene
{
		
	public:
		
		Scene() {}
		
		
		void displayScene (int item) 
		{
			if (item == 0)
    		{
        		cout << "You heard walking steps; you need to find a weapon to protect yourself from unknown creatures." 
             	 	 << "\nDo not make noises or it will find you.";
             	
             	cout << "\nPlease select which room do you think the weapon is: " ;
    		}
    		else if (item == 1)
    		{
        		cout << "\nSuddenly, the house went blackout, you need to find a flashlight to light your way.";
    			cout << "\nPlease select which room do you think the flashlight is: " ;
			}
    		else if (item == 2)
    		{
        		cout << "\nYou need to recharge your energy as your energy is getting lower now." 
             		 << "\nFind cooking utensils and cook yourself some food to survive.";
             	cout << "\nPlease select which room do you think the cooking untensil is: " ;
    		}
			else if (item == 3)
    		{
        		cout << "\nYou accidentally hit the corner of the table. You now have a small wound and need to be treated." 
             		 << "\nNext, you need to find a bandage and iodine.";
                cout << "\nPlease select which room do you think the bandage and iodine is: " ;
    		}
    		
    		else if (item == 4)
    		{
        		cout << "\nFinally, the ultimate item is the key." 
             		 << "\nYou need to find where the key is hidden to unlock the exit door.";
             	cout << "\nPlease select which room do you think the key is: " ;
    		}
		}
		
		void displayResult (bool answer, int item)
		{
			if(item == 0)
			{
				if(answer)
					cout << "\nYou found it! Now you have extra protection. " ;
				else
					cout << "\nUnfortunately, you did not find it. You need to be extra careful to escape from this house.";
			}
			
			else if (item == 1)
			{
				if (answer)
					cout << "\nGreat, you have  found it! Now you can see better in the dark. Please bear in mind not to enter wrong room or else you will die.";
				else
					cout << "\nYou picked the wrong room! You could not find the flashlight. Thus, you need to search in the dark." ;
			}
			
			else if (item == 2)
			{
				if (answer)
					cout << "\nFantastic! Now you can cook to gain more energy to continue this journey. Keep up the hard work.";
				else
					cout << "\nHm... It seems like you need to starve for a while. You have to use your remaining energy to keep on surviving in this journey.";
			}
			else if (item == 3)
			{
				if (answer)
					cout << "\nAmazing! You have found it. Your wound now already covered and can be heal.";
				else
					cout << "\nOh no! You could not find the bandage and iodine. Your wound cannot be treated and you have to be extra cautious with your wound.";
			}
			else if (item == 4)
			{
				if(answer)
					cout << "\nCongratulations! You have found the ultimate item. Do you think you can escape and unlock the exit door? MUAHAHAHA *evil laugh";
				else
					cout << "\nOh Oh.. You could not find the ultimate item. This will reduce the chances for you to escape from this house and win this game.";
			}
			
			else
				cout << "\nNo item is found." ;
		}
		
};

#endif

#ifndef ITEM_H
#define ITEM_H
#include "Scene.h"
#include <iostream>
using namespace std;

class Item 
{
	private:
		string items[5] = {"weapon", "flashlight", "cooker", "bandage", "key"};
		//Scene scene;
	protected:
    	struct ListNode 
		{
        	int room;
        	string item;
        	Scene scene;
        	ListNode* next;
    	};
		
    	ListNode *head;

	public:
		
    	Item() 
		{
        	head = nullptr;
        }


    	~Item() {}

    	void hideItem(int i, int roomNum)
		{
			ListNode* newNode;
			ListNode *nodePtr;
			ListNode *previousNode = nullptr;
		
			newNode = new ListNode;
			newNode->item=items[i];
        	newNode->room = roomNum;
        	newNode->next = nullptr;

			if(!head)
			{
				head = newNode;
				newNode->next = nullptr;
			}
		
			else
			{
				nodePtr= head;
				previousNode = nullptr;
				
				while(nodePtr!=nullptr && nodePtr->room < roomNum)
				{
					previousNode = nodePtr;
					nodePtr= nodePtr->next;
				}
				
				if (previousNode == nullptr)
				{
					head = newNode;
					newNode->next = nodePtr;
				}
				
				else
				{
					previousNode->next = newNode;
					newNode->next = nodePtr;
				}
			}	
		}
		
		void displayHiddenItems()
		{
			ListNode *nodePtr;
			nodePtr = head;
			while(nodePtr)
			{
				cout << "Room " << nodePtr->room << ":" ;
				cout << nodePtr ->item << endl;
				nodePtr = nodePtr->next;
			}	
		}
		
		void itemScene(int i)
		{
			ListNode *nodePtr;
			nodePtr = head;
			
			while(nodePtr)
			{
				if (nodePtr->item == items[i])
				{
					nodePtr->scene.displayScene(i) ;
					break;
				}
				else
				nodePtr = nodePtr->next;
			}	
		}
		
		bool guessRoom(int i, int room) 
		{
    		ListNode* nodePtr = head;
			
			while (nodePtr)
			{
				if (nodePtr->item == items[i]) 
				{ 
            		if (nodePtr->room == room) 
					{ 
                		return true; 
						break; 
            		}
        		}

        		nodePtr = nodePtr->next;
			}
				
    		return false;
		}
		
		void result(bool status, int i)
		{
			ListNode *nodePtr;
			nodePtr = head;
			
			while(nodePtr)
			{
				if (nodePtr->item == items[i] )
				{
					nodePtr->scene.displayResult(status,i) ;
					break;
				}
				else
				nodePtr = nodePtr->next;
			}	
		}
		
};

#endif

#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include <iostream>
#include "Player.h"
#include "Item.h"

using namespace std;

class GamePlay : public Player, public Item
{
	private:
		int points; 
		
	public:
		GamePlay (const string &name) : Player (name) 
		{
			points=0;
		}
		
		void addPoints ()
		{
			points++;
		}
		
		int getPoints ()
		{
			return points;
		}
		
		void displayPoints ()
		{
			cout << getName() << "'s points: " << getPoints() << endl;
		}
		
		friend void determineWinner(GamePlay& player1, GamePlay& player2)
		{
    		if (player1.getPoints() > player2.getPoints()) 
				cout << player1.getName() << " is the winner!" << endl;
    		else if (player1.getPoints() < player2.getPoints()) 
        		cout << player2.getName() << " is the winner!" << endl;
     		else 
        		cout << "It's a tie!" << endl;
    	}

};

#endif

#include <iostream>
#include <fstream>
#include "GamePlay.h"
#include "Scene.h"
using namespace std;

void displayHistoricalData();

int main() 
{
	string name1, name2;
	
	cout << "Enter Player 1 name: " ;
	getline (cin,name1) ;
	
	cout << "Enter Player 2 name: " ;
	getline (cin,name2) ;
	
    GamePlay player1(name1);
    GamePlay player2(name2);
	
	cout << endl;
	cout << "\nYou need to hide these items to ensure that another player could not escape from the house." 
	     << "\nYou may hide these items at anywhere in the house." << endl;
	
	cout << "\n";     
	cout << player1.getName() << " is hiding items.....\n";
	cout << "\nEnter room number to hide: " << endl;
	
    // Hide items for player 1
    for (int i = 0; i < 5; i++) 
	{
        int roomNum;
        cout << "Item " << i + 1 << ": ";
        cin >> roomNum;
        player1.hideItem(i, roomNum);
    }
	 cout << endl;
	cout << player2.getName() << " is hiding items.....\n";
	cout << "\nEnter room number to hide: " << endl;
	
    // Hide items for player 2
    for (int i = 0; i < 5; i++) 
	{
        int roomNum;
        cout << "Item " << i + 1 << ": ";
        cin >> roomNum;
        player2.hideItem(i, roomNum);
    }
    
    cout << "\n__________________________________________________________________________________\n";

    // Display hidden items for each player (for testing purposes)
    cout << player1.getName() << "'s hidden items: " << endl;
    player1.displayHiddenItems();
    cout << endl;
    
    cout << player2.getName() << "'s hidden items: " << endl;
    player2.displayHiddenItems();
    
    cout << "\n__________________________________________________________________________________\n\n";
    
    for (int i = 0; i < 5; i++) 
	{
		bool status;
        int guess;
        player1.itemScene(i);
        cin >> guess;
        status = player2.guessRoom(i, guess);
        if (player2.guessRoom(i, guess))
		{
			player1.addPoints() ;
		}
		player1.result(status,i);
    }
    cout << endl;
    
    for (int i = 0; i < 5; i++) 
	{
		bool status;
        int guess;
        player2.itemScene(i);
        cin >> guess;        
        status =  player1.guessRoom(i, guess);          
        if (player1.guessRoom(i, guess))                      
		{
			player2.addPoints() ;
	    }
	    	
		player2.result(status,i);
	}
	
    player1.displayPoints();
    player2.displayPoints();
    
    determineWinner(player1, player2);
    

    return 0;
}

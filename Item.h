#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>
using namespace std;

class Item 
{
	// ListNode to store roomNum, numItem , item and point
	private:
    	struct ListNode 
		{
        	int room;
        	int numItem;
        	string item;
        	ListNode* next;
    	};
		
    	ListNode *head;

	public:
		
    	Item() // constructor
		{ head = nullptr;}

    	~Item() //destructor
		{
			ListNode *current = head;
        	while (current != nullptr) 
			{
            	ListNode *next = current->next;
            	delete current;
            	current = next;
        	}
		}
		
		void addItem (int choice, int i)  //create linked list for selected item
		{
			ListNode *newNode = new ListNode;
        	newNode->numItem = i;
        	switch (choice)
        	{
        		case 1: 
				{
					newNode->item = "Weapon";
					break;
				}
				
				case 2:
				{
					newNode->item = "Flashlight";
					break;
				}
				
				case 3:
				{
					newNode->item = "Cooker";
					break;
				}
				
				case 4:
				{
					newNode->item = "Bandage";
					break;
				}
				
				case 5:
				{
					newNode->item = "Key";
					break;
				}
        		
        		case 6:
        		{
        			newNode->item = "Map";
					break;
				}
				
				case 7:
				{
					newNode->item = "Rope";
					break;
				}
				
				default:
				{
					newNode->item = " ";
				}	
			}
        	
        	newNode->next = nullptr;

        	if (!head) 
			{
            	head = newNode;
        	} 
		
			else 
			{
            	ListNode *current = head;
            	while (current->next != nullptr) 
				{
                	current = current->next;
            	}
            	current->next = newNode;
        	}	
		}
		
		void displayItem() // traverse node to display item choosen by player
		{
			ListNode *nodePtr;
			nodePtr = head;
			while(nodePtr)
			{
				cout << nodePtr ->item << "      ";
				nodePtr = nodePtr->next;
			}	
		}	
   
		string getItemName(int i) 	//traverse to find item name
    	{
    		ListNode *nodePtr;
			nodePtr = head;
			while(nodePtr)
			{
				if (i == nodePtr->numItem)
				{
					return nodePtr->item;
				}
				nodePtr = nodePtr->next;
			}
			return " ";
		}
		
		int getItemPoints(string s) // to get item point 
		{
			int p;
			
				if (s == "Weapon")
   					p = 3;
    
    			else if (s == "Flashlight")
    				p = 3;
        
    			else if (s == "Cooker")
    				p = 2;
   
				else if (s == "Bandage")
					p = 3;
    		
    			else if (s == "Key")
    				p = 5;
    		
    			else if (s == "Map")
    				p = 2;
    		
    			else if (s == "Rope")
    				p = 4;
    
    			else 
					p = 0;
				
			return p;
		}

    	void hideItem(int i, int roomNum) // to hide item
		{
			ListNode *nodePtr = head;
			
			while (nodePtr)
			{
				if (nodePtr->numItem == i)
				{
					nodePtr->room = roomNum;
					break;
				}
				nodePtr = nodePtr->next;	
			}
		}
		
		void displayHiddenItems()
		{
			ListNode *nodePtr;
			nodePtr = head;
			while(nodePtr)
			{
				cout << nodePtr->item << " at Room:" ;
				cout << nodePtr->room << endl;
				nodePtr = nodePtr->next;
			}	
		}

		
		bool isTrue(int i, int roomNum)  // to decide either the player guess the room correct or not
		{
    		ListNode* nodePtr = head;
			
			while (nodePtr)
			{
				if (nodePtr->numItem == i) 
				{ 
            		if (nodePtr->room == roomNum) 
					{ 
                		return true; 
						break; 
            		}
        		}

        		nodePtr = nodePtr->next;
			}
				
    		return false;
		}
		
};

#endif

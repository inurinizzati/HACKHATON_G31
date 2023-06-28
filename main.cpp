#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <cstdlib>
#include <iomanip>
#include "GamePlay.h"
using namespace std;

void displayItem();  //to display item that can be selected by player
void readData (GamePlay &player1, GamePlay &player2, const string &filename); // read text file to retrieve history data(if exist)
void getScene (string item); // get scene for each item
void getResult (bool answer, string item); // result of guess
void clearScreen(); //to clear the screen
void getRoomName (int choice); //get room name
void displayRoom(); //display list of rooms

int main()  
{
	int screenWidth = 100; // Set the desired screen width

    // Calculate the padding required for center alignment
    int padding = (screenWidth - 1 - 83) / 2;

    // Output the top border of the box
    cout << setw(padding) << "+" << setfill('-') << setw(120) << "+" << setfill(' ') << endl;

    // Output the text with center alignment
    cout << setw(padding + 83) << "\tWelcome to House of Secrets: The Sinister Quest!" << setw(padding + 1) << endl
         << setw(padding + 86) << "\tIn the forgotten realm of Silhouettes, where moonlight casts ghostly shadows and whispers of the past intertwine," << setw(padding + 1) <<  endl
         << setw(padding + 94) << "\ttwo formidable detectives have heeded the call of darkness. In this accursed mansion, where every creaking floorboard " << setw(padding + 1) << endl
         << setw(padding + 87) << "\tholds a secret and every flickering candle illuminates the unknown, Detective Kleo and Detective Zeke prepare" << setw(padding + 1) << endl
		 << setw(padding + 85) << "to embark on a harrowing journey." << setw(padding + 1)  << endl;

    // Output the bottom border of the box
    cout << setw(padding) << "+" << setfill('-') << setw(120) << "+" << setfill(' ') << endl;

	char playGame = 'y'; //to start game
	
	do //do-while loop to make sure this game run at least once
	{	
		string filename = "inputs.txt" ;  //text file name
		string name1, name2;
		int numItem;
		GamePlay player1, player2;  // object of GamePlay
	
		readData(player1, player2, filename); //read input from text file(if exist). if not exist, start a new game

		cout << "\n==========================================================================================================================" ;
		//hiding phase
		cout << "\nThe time has come to venture into the heart of the House of Secrets, where forgotten tales and unspeakable horrors lie in wait." 
			 << "\nEach detective must strategically hide their treasured items, ensuring their secrets remain concealed from prying eyes and "
			 <<	"\nthe restless spirits that haunt these cursed halls. There are only 5 of 7 treasures to hide which are map, cooker, rope, flashlight, key, bandage, and rope." << endl;
		clearScreen();
		
		displayRoom();
		cout << "\nDetective KLEO, with unwavering resolve, takes the first turn. She selects a room, from 1 to 6, her fingers trembling with a mix of excitement and trepidation: " << endl;
		cout << "\nEnter room number to hide (1-6): " << endl;
	
    	// player 1 hides items 
		int roomNum;
    	for (int i = 1; i<=5; i++) 
		{
        	do
			{
        		cout << i <<"." << player1.getItemName(i) << ": ";
        		while (!(cin >> roomNum))
        		{
        			cin.clear();
        			cin.ignore(numeric_limits<streamsize>::max(), '\n');
        			cout << "Invalid input. Please enter a number: ";
				}
        	
        		if (roomNum < 1 || roomNum > 6) 
				{
            		cout << "Invalid room number. Please enter a number between 1 and 6." << endl;
        		}
			} while (roomNum < 1 || roomNum > 6);
		
			player1.hideItem(i, roomNum);
    	}
		clearScreen();
		
		cout << "\nNow, Detective Zeke, the stage is yours. Choose a room, from 1 to 6, guided by a sixth sense that allows you to navigate this house of shadows: " << endl;
		cout << "\nEnter room number to hide (1-6): " << endl;
	
    	//player 2 hides items
    	for (int i = 1; i<=5; i++) 
		{
        	do
			{
        		cout << i <<"." << player2.getItemName(i) << ": ";
        		while (!(cin >> roomNum))
        		{
        			cin.clear();
        			cin.ignore(numeric_limits<streamsize>::max(), '\n');
        			cout << "Invalid input. Please enter a number: ";
				}
        		
        		if (roomNum < 1 || roomNum > 6) 
            		cout << "Invalid room number. Please enter a number between 1 and 6." << endl;
        	
			} while (roomNum < 1 || roomNum > 6);
		
			player2.hideItem(i, roomNum);
   	 	}
		cout << endl;
		clearScreen();
		
		//searching phase
		int guess;
		bool status1, status2;
		string object1, object2;
		
		cout << "\nThe time has come to navigate the treacherous depths of the House of Secrets and uncover your opponent's sinister treasures." << endl;
		for (int round=1; round<=5; round++)
		{	
			cout << "\n---------------------------------------------------------------------------------------------------\n";
			cout << "\nROUND " << round << endl;
			
			//player 1 guess player's 2 hidden item room 
			if(round != 1)
			{
				cout << endl;
				cout <<  player2.getName() << " has gained " << player2.getCurrentPoints(object2,status2) << "pts.\n" ;
				player2.calcTotalPoints();
						
				player2.stackFoundItemPlayer2(status2, object2);			
			}
			
			cout << "\nNow, it is " << player1.getName() << "'s turn."<< endl ;
			object1 = player2.getItemName(round);
			getScene(object1);
			do
			{
        		while (!(cin >> guess))
        		{
        			cin.clear();
        			cin.ignore(numeric_limits<streamsize>::max(), '\n');
        			cout << "Invalid input. Please enter a number: ";
				}
        		
        		if (guess < 1 || guess > 6) 
            		cout << "Invalid room number. Please enter a number between 1 and 6." << endl;
        	
			} while (guess < 1 || guess > 6);
			
			getRoomName(guess);
			status1 = player2.isTrue(round, guess);
			cout << endl;
			
			getResult(status1, object1);
			
			cout << endl;
			cout << player1.getName() << " has gained " << player1.getCurrentPoints(object1,status1) << "pts.\n";
			player1.calcTotalPoints();
			
			//player 2 guess player's 1 hidden item room 
			cout << "\nNow, it is " << player2.getName() << "'s turn." << endl;
			object2 = player1.getItemName(round);
			getScene(object2);
			do //input validation for room guess
			{
        		while (!(cin >> guess))
        		{
        			cin.clear();
        			cin.ignore(numeric_limits<streamsize>::max(), '\n');
        			cout << "Invalid input. Please enter a number: ";
				}
        		
        		if (guess < 1 || guess > 6) 
            		cout << "Invalid room number. Please enter a number b etween 1 and 6." << endl;
        	
			} while (guess < 1 || guess > 6);
			
			getRoomName(guess);
			status2 = player1.isTrue(round, guess) ;
			//system("pause");
			getResult(status2, object2);
			
			player1.stackFoundItemPlayer1(status1, object1);
			
			if(round == 5)
			{
				player2.getCurrentPoints(object2,status2) ;
				player2.calcTotalPoints();
						
				player2.stackFoundItemPlayer2(status2, object2);			
			}
			clearScreen();				
		}
		//end of searching phase

		cout << "\nAs the echoes of their footsteps reverberate through the mansion, the final scores are tallied, and destiny prepares to crown its victor." << endl;
    	
    	cout << "\nIn this battle of intellect and nerves, only one detective can claim the title of the true master of the House of Secrets." 
			 << "\nThe other shall forever be entwined in the shadows, a mere footnote in the macabre history of Silhouettes.\n";
    	
    	system("pause");
		player1.displayFoundItemPlayer1 (player1.getName()) ;
    	cout <<"\n--------------------------------------------------------------------\n";	
    	player1.displayPoints();
    	cout <<"--------------------------------------------------------------------\n";	

		player2.displayFoundItemPlayer2 (player2.getName());
    	cout <<"\n--------------------------------------------------------------------\n";	
    	player2.displayPoints(); 
    	cout <<"--------------------------------------------------------------------\n";	
    	
    	determineWinner(player1, player2); // to 
    	
    	cout <<"\n--------------------------------------------------------------------\n";	
    	cout << "\nIt's' time to reveal the truth...\n";

    	// Display hidden items for each player (for testing purposes)
    	cout << player1.getName() << "'s hidden items: " << endl;
    	player1.displayHiddenItems();
    	cout << endl;
    
    	cout << player2.getName() << "'s hidden items: " << endl ;
    	player2.displayHiddenItems();
    
    	cout << "\n----------------------------------------------------------------------------------------------\n";
    	//clearScreen();
    	
    	system("pause");
		cout << "Thank you for daring to enter House of Secrets: The Sinister Quest!" 
			 << "\nMay its haunting whispers and chilling puzzles continue to linger in your thoughts long after the game is over.";    
    	cout << "\nDo you want to play again? y/n  ";
		cin >> playGame;
		
	} while (playGame = 'y' || playGame == 'Y');
	
    return 0;
}

void displayItem()  // to display item for palyer to choose
{
	cout << "Here is the list of items:\n\n";

    cout << setw(5) << "No." << setw(12) << "Item" << setw(8) << "Points" << endl;
    cout << setw(5) << "----" << setw(12) << "------------" << setw(8) << "------" << endl;

    cout << setw(5) << "1." << setw(12) << "Weapon" << setw(8) << "3pts" << endl;
    cout << setw(5) << "2." << setw(12) << "Flashlight" << setw(8) << "3pts" << endl;
    cout << setw(5) << "3." << setw(12) << "Cooker" << setw(8) << "2pts" << endl;
    cout << setw(5) << "4." << setw(12) << "Bandage" << setw(8) << "3pts" << endl;
    cout << setw(5) << "5." << setw(12) << "Key" << setw(8) << "5pts" << endl;
    cout << setw(5) << "6." << setw(12) << "Map" << setw(8) << "2pts" << endl;
    cout << setw(5) << "7." << setw(12) << "Rope" << setw(8) << "4pts" << endl;;
    
}

void readData (GamePlay &player1, GamePlay &player2, const string &filename) // to reaf from file
{
	string name1, name2;
	int numItem;
	char choice;
	
	ifstream inFile;
	inFile.open(filename);
	
	cout << "\nDo you want to restore the data? y/n  ";
	
	do
	{
		cin >> choice;
		if (choice != 'y'&& choice != 'Y' && choice != 'N'&& choice != 'n')
			cout << "Invalid input. Re-enter again: ";
	} while (choice != 'y' && choice != 'Y' && choice != 'N'&& choice != 'n');
	
	
	if (inFile && (choice=='y'||choice=='Y'))
	{
		cout << "Data file found. Reading data..." << endl;
        getline(inFile,name1);
		getline(inFile,name2);
        
        player1.setName(name1);
       	player2.setName(name2);
       	
       	cout << "Detective Kleo: " << player1.getName() << endl;
       	cout << "Detective Zeke: " << player2.getName() << endl << endl;
       	
       	displayItem();
       	if (inFile)
       	{
       		cout << "\nHistory item found.";
       		for (int i=1; i<=5; i++)
    		{	
    			inFile >> numItem;
				player1.addItem(numItem,i);
			}
			
			cout << "\n===========================================================================" ;
			cout << "\nHere the list of " << player1.getName() << "'s [Detective KLEO] items: " << endl;
			player1.displayItem();
			
       		for (int i=1; i<=5; i++)
    		{
				inFile >> numItem;
				player2.addItem(numItem,i);
			}
			
			cout << "\n===========================================================================" ;
			cout << "\nHere the list of " << player2.getName() << "'s [Detective ZEKE] items: " << endl;
			player2.displayItem();	
			clearScreen();	
		}

		else	
		{	
			cout << "\nHistory item is not found. Please select the items again.";
			displayItem();
		}
		
		inFile.close();
	}
	
	//players start a new game 
	else
	{
		ofstream outFile;
 		outFile.open(filename, ios::app);
 		
 		if (!inFile)
 			cout << "Data file not found.";
 		
 		 inFile.close();
 			
		cout << "Starting a new game..." << endl;
		
		//player1 enter the name
		cout << "\nWith bated breath, Detective KLEO steps forward, her eyes gleaming with determination. "
			 << "\nIn a voice that resonates with unyielding resolve, she enters her name into the annals of the House: " ;
		cin.ignore() ;
		getline (cin, name1); 
		outFile << name1 << endl;
		player1.setName(name1);
		cout << endl << player1.getName() << ", now you are Detective KLEO.\n";
		
		//player2 enter the name
		cout << "\nNot to be outdone, Detective ZEKE, a master of deduction and renowned for his unwavering nerve, steps forth from the depths of the shadows. "
			 << "\nHis name, whispered in hushed tones, fills the room with an aura of mystery: " ;
		getline (cin, name2) ;
		outFile << name2 << endl;
		player2.setName(name2);
		cout << endl << player2.getName() << ", now you are Detective ZEKE.\n";
		
		clearScreen();
    	cout << endl;
    	
    	cout << "Detective KLEO and Detective ZEKE, it is time to strategically select the treasures you wish to hide within the House of Secrets." 
			 << "Remember, you must choose only five out of the seven available treasures.";
			 
		cout << "\nChoose wisely, for the treasures you hide may hold the key to victory or become a double-edged sword. Each item you pick has its own point."
		 	 << "May your decisions be guided by your cunning and instincts."
		 	 << "\nGood luck, detectives!" << endl;

    	displayItem();
    	cout << endl;
    	
    	//player1 selects items
    	cout << player1.getName() << ", [Detective KLEO], please enter the numbers corresponding to the five treasures you wish to hide.\n";
    	for (int i=1; i<=5; i++)
    	{
    		do 
    		{	
    			cout << "Add item " ;
    			while (!(cin >> numItem ))
        		{
        			cin.clear();
        			cin.ignore(numeric_limits<streamsize>::max(), '\n');
        			cout << "Invalid input. Please enter a number: ";
				}
    		
    			if (numItem < 1 || numItem > 7)
    				cout << "Invalid choice. Re-enter again" ;
			} while (numItem < 1 || numItem > 7);
			
    		outFile << numItem << " " ;
    		player1.addItem(numItem,i);
		}
		outFile << endl;
		
		//display items list player1
		cout << "\n===========================================================================" ;
		cout << "\nHere the list of " << player1.getName() << "'s [Detective KLEO] items:\n " << endl;
		player1.displayItem();
	
		//clearScreen();
	
		cout << "\n===========================================================================\n" ;
		//player 2 selects items
		cout <<  player2.getName() << ", [Detective ZEKE] it is now your turn. Please select the five treasures you wish to hide by entering their corresponding numbers.\n";
    	//displayItem();
    	
    	for (int i=1; i<=5; i++)
    	{
    		do 
    		{	
    			cout << "Add item " ;
    			while (!(cin >> numItem))
        		{
        			cin.clear();
        			cin.ignore(numeric_limits<streamsize>::max(), '\n');
        			cout << "Invalid input. Please enter a number: ";
				}
    	
    			if (numItem < 1 || numItem > 7)
    				cout << "Invalid choice. Re-enter again\n" ;
			} while (numItem < 1 || numItem > 7);
			
			outFile << numItem << " ";
			player2.addItem(numItem,i);
		}
		outFile << endl;
		
		//display items list player2
		cout << "\n===========================================================================" ;
		cout << "\nHere the list of "<< player2.getName() << "'s [Detective ZEKE] items:\n " << endl;
		player2.displayItem();
		
		outFile.close();
		//clearScreen ();
	}
}

void getScene (string item)  // display scene for eeach item
{
	if (item == "Weapon")
    {
        cout << "\nYou hear the faint echo of footsteps, a sign that you are not alone." 
             << "\nYou must find a weapon to protect yourself from the unknown horrors that lurk within the house.";
             	
        cout << "\nChoose a room (1-6) where you believe the weapon is hidden: " ;
    }
    else if (item == "Flashlight")
    {
        cout << "\nA sudden darkness engulfs the house, leaving you in complete obscurity. To light your way and uncover the hidden secrets, you must find a flashlight. ";
    	cout << "\nChoose a room (1-6) where you believe the flashlight is hidden: " ;
	}
    else if (item == "Cooker")
    {
        cout << "\nFatigue begins to take its toll, and you must replenish your energy to continue your perilous journey." 
             << "\nFind cooking utensils and cook yourself some food to survive.";
        cout << "\nChoose a room (1-6) where you believe the cooker is hidden: " ;
    }
	else if (item == "Bandage")
    {
        cout << "\nAs you explore the house, you accidentally injure yourself, a small wound that demands attention." 
             << "\nTo tend to your wound, you must find a bandage";
        cout << "\nChoose a room (1-6) where you believe the bandage is hidden: " ;
    }
    		
    else if (item == "Key")
    {
        cout << "\nThe ultimate item, the key that unlocks the path to salvation, awaits your discovery." ;
        cout << "\nChoose a room (1-6) where you believe the key is hidden: " ;
    }
    		
    else if (item == "Map")
    {
        cout << "\nThe House of Secrets is a labyrinth of darkness, with countless twists and turns. A map will serve as your guide through its perilous corridors." ;
        cout << "\nChoose a room (1-6) where you believe the map is hidden:  " ;
    }
    		
    else if (item == "Rope")
    {
        cout << "\nThe House of Secrets harbours treacherous obstacles and unfathomable depths. To navigate through perilous chasms or scale dizzying heights, you'll require a trusty rope. A well-crafted rope can be your lifeline, enabling you to conquer daunting challenges that lie ahead." ;
        cout << "\nChoose a room (1-6) where you believe the rope is hidden: " ;
    }
    else 
	{}			
}

void getResult (bool answer, string item) // to display result for each item
		{
			if (item == "Weapon")
			{
				if(answer)
					cout << "\n[Result: Correct]."
						 << "\nYou have found the weapon! Its weight in your hand brings a sense of security and readiness to face whatever awaits. " << endl ;
				else
					cout << "\n[Result: Incorrect]."
						 << "\nUnfortunately, you could not find the weapon. Your heart pounds with every creaking floorboard, reminding you of the imminent danger that surrounds you." << endl;
			}
			
			else if (item == "Flashlight")
			{
				if (answer)
					cout << "\n[Result: Correct]."
						 << "\nWell done! The beam of the flashlight pierces through the darkness, revealing the sinister details of the house's haunting past." << endl;
				else
					cout << "\n[Result: Incorrect]."
						 << "\nAlas, you could not find the flashlight. You are left to navigate the pitch-black corridors, relying solely on your instincts and the chilling whispers that echo through the shadows" << endl;
			}
			
			else if (item == "Cooker")
			{
				if (answer)
					cout << "\n[Result: Correct]."
						 << "\nWonderful! The aroma of a hot meal fills the air as you cook, revitalizing your weary body and mind. You are prepared to face the horrors that await." << endl;
				else
					cout << "\n[Result: Incorrect]."
						 << "\nAlas, the cooker remains elusive, denying you the sustenance needed to persevere. Hunger gnaws at your stomach, threatening to weaken your resolve as you confront the unknown." << endl;
			}
			else if (item == "Bandage")
			{
				if (answer)
					cout << "\n[Result: Correct]."
						 << "\nCongratulations! You have found the bandage. With careful precision, you tend to your wound, providing relief and allowing you to press on with renewed vigor." << endl;
				else
					cout << "\n[Result: Incorrect]."
						 << "\nOh no! The bandage eludes you, and your wound remains untreated, a constant reminder of the perils that surround you. Every step becomes a test of endurance as pain gnaws at your every move." << endl;
			}
			else if (item == "Key")
			{
				if(answer)
					cout << "\n[Result: Correct]."
						 << "\nCongratulations! You hold the key, the symbol of your impending freedom. But beware, for the House of Secrets won't surrender its grip easily. Your destiny hangs in the balance." << endl;
				else
					cout << "\n[Result: Incorrect]."
						 << "\nOh no! The key eludes your grasp, dimming the hope of escape. The weight of your failure lingers, casting a shadow over your chances of triumphing in this sinister duel." << endl;
			}
			
			else if (item == "Map")
			{
				if(answer)
					cout << "\n[Result: Correct]."
						 << "\nExcellent! The map unfolds before your eyes, revealing the intricate layout of the house. With this knowledge in your hands, you can navigate its treacherous paths with confidence." << endl;
				else
					cout << "\n[Result: Incorrect]."
						 << "\nAlas, the map remains elusive, leaving you to rely on your instincts and memory to find your way. Every turn becomes a gamble, as you tread deeper into the heart of darkness." << endl;
			}
			
			else if (item == "Rope")
			{
				if(answer)
					cout << "\n[Result: Correct]."
						 << "\nHuzzah! Your fingers brush against the coarse fibers of the rope, instilling you with a renewed sense of determination. With its sturdy presence, you can now venture into the abyss, confident in your ability to traverse the most harrowing precipices." << endl;
				else
					cout << "\n[Result: Incorrect]."
					     << "\nAlas, the rope eludes your search, leaving you without a lifeline to navigate the treacherous terrain that awaits. Each bottomless pit and towering ledge becomes an insurmountable obstacle, testing your bravery and resourcefulness to their limits." << endl;
			}
			
			else
				cout << "\nNo item is found." << endl ;
		}

void displayRoom() // display room for player to choose
{
	cout << endl;
	cout << setw(5) << "Room No." << setw(8) << "Name"  << endl;
    cout << setw(5) << "----" << setw(12) << "------------"  << endl;
    cout << setw(5) << "1" << setw(12) << "Kitchen"  << endl;
    cout << setw(5) << "2" << setw(12) << "Basement" << endl;
    cout << setw(5) << "3" << setw(12) << "Store" << endl;
    cout << setw(5) << "4" << setw(12) << "Bathroom"  << endl;
    cout << setw(5) << "5" << setw(12) << "Library"  << endl;
    cout << setw(5) << "6" << setw(12) << "Bedroom" << endl;
}
	
void getRoomName (int choice) // to display choosen room
{
	string roomName;
	switch (choice)
	{
		case 1: cout << "\nYou have picked room 1 which is kitchen. Now, you'll enter the kitchen to search for that item." << endl; break;
		case 2: cout << "\nYou have picked room 2 which is basement. Now, you'll enter the basement to search for that item." << endl; break;
		case 3: cout << "\nYou have picked room 3 which is store. Now, you'll enter the store to search for that item." << endl; break;
		case 4: cout << "\nYou have picked room 4 which is bathroom. Now, you'll enter the bathroom to search for that item." << endl; break;
		case 5: cout << "\nYou have picked room 5 which is library. Now, you'll enter the library to search for that item." << endl; break;
		case 6: cout << "\nYou have picked room 6 which is bedroom. Now, you'll enter the bedroom to search for that item." << endl; break;	
	}	
}

void clearScreen () // to clear screen
{
	system("pause");
	system ("cls");
}
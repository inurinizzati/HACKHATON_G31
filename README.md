## HACKHATON_G31

| No. | Tittle |
|----- | -----------------------------|
| 1.0 | Introduction |
| 1.1 | Game Storyline |
| 1.0 | Objective |
| 2.0 | Game Analyzation |
| 2.1 | Game Concept |
| 2.2 | Game Features |
| 2.3 | Classes and Its Relationships |
| 2.4 | Object Oriented Programming Concepts |
| 2.5 | Linked List Concepts |

## 1. INTRODUCTION OF OUR TEXT-BASED GAME

**1.1 Game Storyline**

Title: House of Secrets 


Story: 

In the eerie town of Silhouette, shrouded in a dark and mysterious past, a bone-chilling competition is about to unfold. Two exceptional detectives, Detective Kleo and Detective Samuel, known for their unwavering resolve and unwinding enigmatic puzzles, find themselves entangled in a harrowing quest of wits within the sinister House of Secrets. 

Amelia and Samuel, drawn by their insatiable curiosity for the macabre, agree to engage in a sinister contest within the House of Secrets—a foreboding mansion whispered to be a haven for hidden treasures and unsolved mysteries steeped in the occult. 

As the moon casts an ominous glow, the players take their positions, each driven by a desperate desire to outwit the other and survive the nightmarish depths of this malevolent game. They enter their names into the game interface, unwittingly sealing their fate within the realm of terror. 

The first phase of the game commences as Amelia and Samuel take turns hiding five cursed artifacts within five separate rooms of the House of Secrets. With every hidden item, they cautiously choose their hiding spots, ensuring that their selections are diabolically clever and shielded from prying eyes. 

Once the hiding phase is complete, the second phase descends—the harrowing search. Amelia and Samuel must now rely on their trembling senses and acute deductive prowess to unearth the items hidden by their opponent. Six rooms stand before them, each oozing with a haunting charm, but only one holds the coveted relic they seek. 

Unbeknownst to them, the House of Secrets yearns to claim their souls. Within the six rooms, sinister traps lie in wait, cunningly designed to confuse, and torment the hapless detectives. Shadows dance, whispers echo through the halls, and apparitions attempt to lure them astray. False trails, illusory clues, and grotesque specters conspire to lead them astray from their quarry. Amelia and Samuel must steel their nerves, for only the most resolute can navigate the twisted corridors and unveil the truth behind their opponent's treacherous prizes. 

With every successful discovery, a chill runs down their spines, and they earn a point—a grim reminder of their progress in this nightmarish contest. The tension mounts with each correct guess, propelling them ever closer to the abyss of victory or damnation. Their minds become razor-sharp, dissecting cryptic hints, and discarding treacherous misdirection with each fateful turn. The air crackles with a palpable dread as they wage their battle for the highest score, struggling against the malevolent forces that seek to consume them. 

Driven by their competitive spirits, Amelia and Samuel push the boundaries of their sanity and unravel the intricate tapestry of enigmas before them. Their intuition and strategic acumen serve as shields against the encroaching darkness. Each room they venture into unveils a sinister fragment of the House's nefarious secrets, providing vital clues to make more informed guesses and inch closer to salvation or eternal damnation. 

As the game approaches its climax, the detectives find themselves standing on the precipice of their fate. With bated breath, they step into the rooms they believe imprison their opponent's forbidden treasures, desperately hoping their deductions hold true. The House of Secrets tightens its grip, amplifying the sense of impending doom as their destinies intertwine within its malevolent embrace. 

In the end, only one detective emerges, their victory measured by the highest score achieved through accurately deducing the locations of their opponent's accursed artifacts. The House of Secrets unveils its darkest secrets, etching the victor's name into the annals of Silhouette’s ominous history as a master of the macabre. 

With hearts pounding and minds haunted by the horrors they witnessed, Amelia and Samuel bid each other farewell. Though the competition has reached its chilling climax, a lingering respect for each other's skills remains. They part ways, forever marked by the haunting memories of a spine-chilling game, forever changed by their encounter with the House of Secrets. 

And so, the House of Secrets stands, an eternal sentinel, forever ready to ensnare the souls of future detectives who dare to venture into its accursed halls. Who will be the next pair of intrepid souls to test their mettle and unravel the mysteries that dwell within its heart of darkness? Only the brave or the foolish will dare to find out. 

**1.2 Objective**

- To construct object-oriented programming with the appropriate data structures. 

- To use multiple file inclusion to have a more readable program. 

- To read from text file and store historical data and must be reused when the program is restarted. The program will read from the text file if it exists (the text file acts as a simple database). 

- To store two or more nodes in the linked list. 

- To showcase a high level of understanding of classes and multiple class relationships. 

- To maintain data encapsulation of the classes and respect the concept of information hiding amongst classes. 

- To use the main () doubles as the main menu of the game, and allows the user to start a new game, choose the number of players, load their previous game, or any other required functionalities.

## 2.0 GAME ANALYZATION 

**2.1 Game Concept** 

“House of Secrets: The Sinister Quest” is a two-player game, whereby the characters and players are called ‘Detectives’ and they are both humans. Both players will enter their name as input. In this game, the players will take turns making their moves, attempting to contest their opponent to gain highest score by guessing hidden items in the correct room. Each correct guess will contribute to a different point depends on items.  

Firstly, both players will pick 5 from 7 items and hide them in 6 different rooms by taking turns. Next, they will need to search for items hidden by another player by guessing the correct room from 6 rooms where there is an extra distraction. The winning player is determined by the values of score which is higher.  

The items are map, cooker, water, flashlight, key, bandage, and key while the rooms are kitchen, bedroom, toilet, living room, store and basement. 

Immerse yourself in the House of Secrets: The Sinister Quest as a Detective, hiding and seeking hidden items within its mysterious rooms. Use your intuition and outwit your opponent to claim victory in this challenging and strategic game of deduction. 


         **2.2 Game Features** 

Players and Setup: 

The game is designed for two players, referred to as "Detectives." At the start of the game, both players enter their names as input to personalize their experience. 

Item Hiding Phase: 

Players take turns hiding five items each in five different rooms within the House of Secrets. During their turn, a player selects an item from their collection and chooses a room to hide it in. The goal is to strategically place the items to make them challenging to find. Each player must ensure that their items remain hidden. 

Searching Phase: 

After the item hiding phase, the game progresses to the searching phase. Players take turns guessing the correct room where their opponent has hidden an item. The house consists of six rooms, with one room containing a distraction (e.g., a false clue or decoy item) and the remaining five or lesser rooms holding the hidden items. Players need to use their deductive skills, analyse clues, and consider their opponent's strategies to make educated guesses. If a player guesses the correct room, they earn point for their score. However, if they guess the distraction room or a room with no hidden item, they do not earn any points. 

Scoring and Winning: 

Each correct guess adds one point to the player's score. The game continues with players taking turns guessing until all five hidden items have been found. Once all the items are discovered, the game ends, and the player with the highest score wins. In the event of a tie, the game can be extended with additional rounds until there is a clear winner. 

*Additional Features:*

Distraction Rooms: 

The presence of a distraction room adds an element of challenge and uncertainty to the game. Detectives must carefully analyse clues and make informed decisions to avoid falling for the distractions. 

Clues and Strategy: 

Players can incorporate the use of clues and strategic thinking to maximize their chances of guessing the correct rooms. Analysing patterns, considering previous guesses, and adapting their strategies can help players improve their performance. 

Score Tracking and Display: 

The game includes a score tracking system to keep a record of each player's score. The current scores of both players are displayed throughout the game, providing a sense of competition and progress. 

Replay ability: 

The game can be played multiple times, with players taking turns as both the hider and the seeker. Each playthrough offers new opportunities for strategic thinking and improving gameplay tactics. 

**2.3 Classes and Its Relationships** 

- Scene Class 

  - The Scene class has a default constructor and two member functions: displayScene() and displayResult().The displayScene() function takes an integer parameter item and displays a specific message based on the value of item. It prompts the user to choose a room number where they believe a certain item is hidden. 

  - The displayResult() function takes a boolean parameter answer and an integer parameter item. It displays a message based on the result of the player's guess. If the guess was correct (answer is true), it provides a congratulatory message for finding the item. Otherwise, it displays a message indicating that the item was not found. 

- Item Class 

  - The Item class has a private nested struct called ListNode, which represents a node in a linked list.The class has a pointer to the head of the linked list, initialized as nullptr. The class provides a default constructor and a destructor to manage memory for the linked list. 

   - The class contains member functions for adding an item to the linked list (addItem()), displaying all the items (displayItem()), retrieving the name of an item based on its number (getItemName()), hiding an item in a specific room (hideItem()), displaying the hidden items with their corresponding rooms (displayHiddenItems()), displaying the scene for a specific item (itemScene()), checking if the player's guess of a room matches the item's hidden room (guessRoom()), and displaying the result of the guess (result()). 

- Player Class 

   - The Player class has a single data member playerName of type string, representing the name of the player.The class provides a constructor that takes a string parameter name to initialize the player Name. The class also provides a member function getName() that returns the playerName. 

   - Overall, these classes seem to be part of a game where the player explores a house and tries to find hidden items in different rooms. The Item class manages the items and their corresponding scenes, while the Scene class handles the display of messages related to the items. The Player class is responsible for managing the player's information.  

- GamePlay Class 

   - The GamePlay class has a private member variable point, which represents the score of the player. It is initialized to 0 in the constructor, which takes a const string& parameter representing the player's name. The constructor also calls the Player constructor using the name parameter. 

   - The class provides member functions to manipulate the score: addPoints() increments the score by 1. getPoints() returns the current score. displayPoints() prints the player's name and their score to the standard output. Additionally, there is a friend function determineWinner() defined outside the class. It takes two GamePlay objects as parameters and compares their scores to determine the winner or a tie.  

   - Overall, the GamePlay class combines functionality from the Player and Item classes and adds scoring capabilities. It allows players to accumulate points, display their score, and determine the winner between two players using the determineWinner() function. 

**2.4 Object Oriented Programming Concept**

1. Inheritance: The GamePlay class inherits from both the Player and Item classes using public inheritance. By inheriting from these classes, GamePlay can access their members and extend their functionality. Inheritance allows code reuse and promotes the "is-a" relationship, where GamePlay is a specialized type of both Player and Item. 

1. Encapsulation: The class members (points) are declared as private, encapsulating the internal state of the GamePlay class. This encapsulation allows data hiding and ensures that the internal state can only be accessed and modified through the public member functions provided by the class. This promotes information hiding and encapsulates related data and behavior within the class. 

1. Polymorphism: The GamePlay class demonstrates polymorphism through inheritance. By inheriting from the Player and Item classes, GamePlay can exhibit different behaviors while maintaining a common interface. For example, GamePlay can call the getName() function inherited from the Player class, even though it also inherits from the Item class. Polymorphism allows objects of different classes to be treated interchangeably when they share a common base class. 

1. Constructor: The GamePlay class defines a constructor that initializes the points member variable to 0. The constructor takes a const string& parameter representing the player's name and calls the Player constructor with the name parameter. The constructor allows proper initialization of objects of the GamePlay class when they are created, ensuring that necessary setup is performed. 

1. Member Functions: The class provides member functions to manipulate and access the points member variable. The addPoints() function increments the score, the getPoints() function returns the current score, and the displayPoints() function displays the player's name and their score. These member functions encapsulate the behavior related to the points variable within the class, promoting code organization and maintainability. 

1. Friend Function: The GamePlay class defines a friend function determineWinner(), which is defined outside the class. The friend keyword allows the function to access the private members of the GamePlay class. The determineWinner() function takes two GamePlay objects as parameters and compares their scores to determine the winner or a tie. This demonstrates the use of friend functions to provide access to private members of a class to external functions when necessary. 

1. By utilizing these object-oriented concepts, the code promotes modularity, code reuse, and encapsulation. It allows for the creation of objects with specific behaviors and attributes, promoting a more organized and maintainable codebase. 

**2.5 Linked List Concepts**

Linked lists play a role in managing and organizing the items in the game. Let's analyse the code to understand how linked lists are utilized: 

The Item class represents the collection of items in the game. It uses a linked list to store the items. Each item is represented by a node in the linked list, defined by the inner ListNode structure. 

 

- The ListNode structure contains several members: 

   - room: Represents the room number where the item is hidden. 

   - numItem: Represents the item number. 

   - item: Represents the name of the item. 

   - scene: An instance of the Scene class, which is responsible for displaying scenes related         to the item. 

   - next: A pointer to the next node in the linked list. 

- The Item class provides various functions to manipulate the linked list: 

   - addItem: Adds a new item to the linked list. It creates a new node, assigns the item's         details, and appends it to the end of the list. 

   - displayItem: Displays all the items in the list along with their item numbers. 

   - getItemName: Retrieves the name of an item based on its item number. 

   - hideItem: Sets the room number where an item is hidden by finding the corresponding node         and updating its room member. 

   - displayHiddenItems: Displays the name of each item along with the room number where it is         hidden. 

   - itemScene: Displays the scene related to a particular item by finding the corresponding         node and invoking the displayScene function of the Scene class. 

   - guessRoom: Checks if the player's guess for the room where an item is hidden matches the         actual room number. It traverses the linked list to find the corresponding item node         and compares the room numbers. 
        
   - result: Displays the result of the player's guess for a particular item by finding the corresponding node and invoking the displayResult function of the Scene class. 

In summary, linked lists are used to manage and store the items in the game. Each item is represented by a node in the linked list, containing information such as the item name, room number, and scene details. The linked list allows for efficient storage, retrieval, and manipulation of the items during gameplay. 
      

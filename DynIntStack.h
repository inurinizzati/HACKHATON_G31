#ifndef DYNINTSTACK_H
#define DYNINTSTACK_H
#include <iostream>
using namespace std;

template <class T>
class DynIntStack
{
	private:
		// Structure for stack nodes
		struct StackNode
		{
			T value; // Value in the node
			StackNode *next; // Pointer to the next node
		};
	
		StackNode *top;
		
	public:
		
		DynIntStack() // constructor
		{ top = nullptr; }
		
		~DynIntStack()  // destructor
		{
			StackNode *nodePtr = nullptr, *nextNode = nullptr;
	
			// Position nodePtr at the top of the stack.
			nodePtr = top;

			// Traverse the list deleting each node.
			while (nodePtr != nullptr)
			{
				nextNode = nodePtr->next;
				delete nodePtr;
				nodePtr = nextNode;
			}
		}
		
		void push(T item)  // add item into the stack
		{
			StackNode *newNode = nullptr; 
			
			newNode = new StackNode;  // create new node 
			newNode->value = item;

 			if (isEmpty()) // to check if stack empty  
 			{
 				top = newNode;  // first node point to stack top
 				newNode->next = nullptr;
			}
			
			else
			{
				newNode->next = top; 
				top = newNode;
			}
 		}
 		
 		void pop (T &item) // to delete item from the stack
 		{
 			StackNode *temp = nullptr;
 			
 			if (isEmpty())
 				cout << "The stack is empty.\n";
 			
 			else
 			{
 				item = top->value;
				temp = top->next;
				delete top;
				top = temp;
			}
		}
		
		bool isEmpty()  // to check if the stack is empty
		{
			if (!top)
				return true;
			else
				return false;	
		}	
};

#endif
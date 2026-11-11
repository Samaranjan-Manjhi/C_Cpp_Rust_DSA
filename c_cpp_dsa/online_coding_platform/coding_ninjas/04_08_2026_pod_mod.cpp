/*
 
  Cycle Detection in a Singly Linked List 
 
  Problem statement
You are given a Singly Linked List of integers. Return true if it has a cycle, else return false.
A cycle occurs when a node's next points back to a previous node in the list.

Sample Input 1 :
1 2 3 4 -1
1
Sample Output 1 :
true
Explanation of Sample Input 1:
The linked list given in the input is as follows:

Sample Input 2 :
1 2 3 4 -1
0
Sample Output 2 :
true
Explanation of Sample Input 2:
The linked list given in the input is as follows:

Sample Input 3 :
5 -1
-1
Sample Output 3 :
false
Explanation of Sample Input 3:
 The linked list given in the input is as follows:

Expected Time Complexity:
Try to solve this problem in O(n).

Expected Space Complexity:
Try to solve this problem in O(1).

Constraints :
0 <= n <= 10^6
-1 <= pos < n
-10^9 <= data <= 10^9 and data != -1
Where 'n' is the size of the singly linked list, 'pos' represents the position (0-indexed) in the linked list where the tail connects to, and 'data' is the Integer data of the singly linked list.

Time Limit: 1 sec

 */



#include <iostream>

using namespace std;

class Node
{
	public:
		int data;
		Node *next;
		Node()
		{
			this->data = 0;
			next = NULL;
		}
		Node(int data)
		{
			this->data = data;
			this->next = NULL;
		}
		Node(int data, Node* next)
		{
			this->data = data;
			this->next = next;
		}
};

bool detectCycle(Node *head)
{
	Node* slow = head;
	Node* fast = head;
	if(head == NULL || head->next == NULL)
		return false;

	while(fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if(slow == fast)
			return true;
	}

	return false;
}

int main() 
{
	int n;
	cout << "Enter the number of nodes in the linked list: ";
	if (!(cin >> n) || n <= 0) 
	{
		cout << "The list is empty. No cycle detected." << endl;
		return 0;
	}

	Node* head = NULL;
	Node* tail = NULL;
	Node* cycleStartNode = NULL; // To keep track of a node for creating a cycle

	cout << "Enter the elements of the linked list:\n";
	for (int i = 0; i < n; i++) 
	{
		int val;
		cin >> val;
		Node* newNode = new Node(val);

		if (head == NULL) 
		{
			head = newNode;
			tail = newNode;
		} 
		else 
		{
			tail->next = newNode;
			tail = newNode;
		}

		// Let's save a reference node, e.g., the 2nd node (index 1), to optionally create a cycle later
		if (i == 1) 
		{
			cycleStartNode = newNode;
		}
	}

	// Optional: Create a cycle for testing purposes
	char choice;
	cout << "Do you want to create a cycle in the linked list? (y/n): ";
	cin >> choice;

	if (choice == 'y' || choice == 'Y') 
	{
		if (cycleStartNode != NULL) 
		{
			// Point the last node's next to the cycleStartNode
			tail->next = cycleStartNode;
			cout << "Cycle created pointing to node with value: " << cycleStartNode->data << endl;
		} 
		else 
		{
			// If there is only 1 node, point it to itself
			head->next = head;
			cout << "Cycle created pointing to the single node itself." << endl;
		}
	}

	// Test the detectCycle function
	if (detectCycle(head)) 
	{
		cout << "Result: Cycle detected! (true)" << endl;
	} 
	else 
	{
		cout << "Result: No cycle detected. (false)" << endl;
	}

	return 0;
}

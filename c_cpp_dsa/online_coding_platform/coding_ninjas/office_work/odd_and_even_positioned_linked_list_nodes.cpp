/*

   Odd and even positioned linked list nodes

   Problem statement

   You are given a singly linked list ‘HEAD’ consisting of ‘N’ nodes. The task is to group all the odd nodes together, followed by the even nodes, maintaining the relative order of nodes given in the input. Note that we are talking about the node’s positions and not the value stored in the node. Try to write an in-place algorithm (i.e., without using any extra space) to solve this problem.

Example:
Given linked list: ‘2 => 1 => 3 => 4 => 6 => 5’
While maintaining the relative order of nodes as it is in the input, Nodes at odd positions are (2, 3, 6), and nodes at evens position are (1, 4, 5).
Modified linked list: ‘2 => 3 => 6 => 1 => 4 => 5’

Note:
1. Consider that the first node is odd, the second is even, and so on.

Constraints:
1 <= T <= 100
1 <= N <= 10^3
-10^6 <= Node value <= 10^6 (Node Value != -1)  
Time limit: 1 second

Sample input 1:
2 
1 2 3 -4 5 6 -1    
-3 -1 
Sample output 1:
1 3 5 2 -4 6 -1
-3 -1 

Explanation of sample input 1:

Test Case 1:
Given linked list: ‘1 => 2 => 3 => -4 => 5 => 6’
While maintaining the relative order of nodes as it is in the input, Nodes at odd positions are (1, 3, 5), and nodes at evens position are (2, -4, 6). 
Modified linked list: ‘1 => 3 => 5 => 2 => -4 => 6’

Test Case 2:
Input linked list: ‘-3’
The linked list contains only one node.
Modified linked list: ‘-3’

Sample input 2:
2
3 5 -2 1 7 -1
-2 3 5 3 -1  
Sample output 2:
3 -2 7 5 1 -1
-2 5 3 3 -1

 */


#include <iostream>
#include <vector>

using namespace std;

class Node 
{
     public:
          int value;
          Node *next;
          Node(int value) : value(value), next(nullptr){};
};

Node *oddEvenLinkedList(Node *head) 
{
     // Write your code here.
     if(head == nullptr || head->next == nullptr)
          return head;

     Node* odd = head;
     Node* even = head->next;
     Node* evenHead = even;
     while(even != nullptr && even->next != nullptr)
     {
          odd->next = even->next;
          odd = odd->next;
          even->next = odd->next;
          even = even->next; 
     }
     odd->next = evenHead;
     return head;
}

Node* createList(const vector<int>& values) 
{
     if (values.empty()) 
          return nullptr;

     Node* head = new Node(values[0]);
     Node* current = head;
     for (size_t i = 1; i < values.size(); ++i) 
     {
          current->next = new Node(values[i]);
          current = current->next;
     }
     return head;
}

void freeList(Node* head) 
{
     while (head != nullptr) 
     {
          Node* temp = head;
          head = head->next;
          delete temp;
     }
}

int main() 
{
     int n;
     cout << "Enter the number of elements in the linked list: ";
     if (!(cin >> n) || n <= 0) 
     {
          cout << "Invalid list size!" << endl;
          return 1;
     }

     vector<int> values(n);
     cout << "Enter " << n << " space-separated integers: ";
     for (int i = 0; i < n; ++i) 
     {
          cin >> values[i];
     }

     Node* head = createList(values);
     Node* temp = head;
     cout << "    Linked List Before oddEvenLinkedList Operation:- ";
     while(temp != NULL)
     {
          cout << temp->value << "->";
          temp = temp->next;
     }
     cout << "NULL\n";

     Node* res = oddEvenLinkedList(head);
     cout << "    Linked List After oddEvenLinkedList Operation:- ";
     while(res != NULL)
     {
          cout << res->value << "->";
          res = res->next;
     }
     cout << "NULL\n";

     freeList(head);

     return 0;
}

/*

   Problem statement

   You are given a doubly-linked list of size 'N', consisting of positive integers. Now your task is to reverse it and return the head of the modified list.
Note:
A doubly linked list is a kind of linked list that is bidirectional, meaning it can be traversed in both forward and backward directions.

Example:
Input: 
4
4 3 2 1
This means you have been given doubly linked list of size 4 = 4 <-> 3 <-> 2 <-> 1.
Output: 
1 2 3 4
This means after reversing the doubly linked list it becomes 1 <-> 2 <-> 3 <-> 4.

Sample Input 1 :
8
1 2 3 4 5 6 7 8 
Sample Output 1 :
8 7 6 5 4 3 2 1
Explanation for sample output 1
Input: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6 <-> 7 <-> 8
Output: 8 <-> 7 <-> 6 <-> 5 <-> 4 <-> 3 <-> 2 <-> 1
Explanation: It's self explanatory.

Sample Input 2 :
5
5 8 4 9 1
Sample Output 2 :
1 9 4 8 5

Constraints :
1 <= 'N' <= 10^3
0 <= 'data' <= 10^3 
Where 'N' is the size of the doubly linked list.
Time Limit: 1 sec

 */


#include <iostream>
using namespace std;

// Definition of Node
class Node 
{
     public:
          int data;
          Node* prev;
          Node* next;

          Node(int val) 
          {
               data = val;
               prev = nullptr;
               next = nullptr;
          }
};

// Function to insert node at the end
void insert(Node*& head, int val) 
{
     Node* newNode = new Node(val);
     if (head == nullptr) 
     {
          head = newNode;
          return;
     }

     Node* temp = head;
     while (temp->next != nullptr) 
     {
          temp = temp->next;
     }

     temp->next = newNode;
     newNode->prev = temp;
}

// Function to reverse DLL
Node* reverseDLL(Node* head)
{
     Node* temp = head;
     Node* last = nullptr;

     while (temp)
     {
          swap(temp->prev, temp->next);
          last = temp;
          temp = temp->prev;
     }

     if (last)
          head = last;

     return head;
}

// Function to display DLL
void display(Node* head) 
{
     Node* temp = head;

     while (temp) 
     {
          cout << temp->data << " ";
          temp = temp->next;
     }
     cout << endl;
}

int main() 
{
     Node* head = nullptr;
     int n, value;

     cout << "Enter number of nodes: ";
     cin >> n;

     cout << "Enter node values: ";
     for (int i = 0; i < n; i++) 
     {
          cin >> value;
          insert(head, value);
     }

     cout << "Original Doubly Linked List: ";
     display(head);

     head = reverseDLL(head);

     cout << "Reversed Doubly Linked List: ";
     display(head);

     return 0;
}

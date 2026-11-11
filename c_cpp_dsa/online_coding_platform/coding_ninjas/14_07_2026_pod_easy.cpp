/*

   Deletion In Doubly Linked List 

   Problem statement

   You are given a Doubly Linked List of ‘N’ positive integers. Your task is to delete a node at position ‘POS’ in the linked list.
Note:

Assume that the Indexing for the linked list starts from 0.

EXAMPLE:

Input: ‘N’ = 5, 'LIST' = [1, 1, 2, 3, 4, -1], ‘POS’ = 1.
Output: 1 < - > 2 < - > 3 < - > 4 
Here in the given list, we can see that the node at position 1 is deleted.

Constraints :
1 <= ‘T’ <= 10 
2 <= ‘N’ <= 10^4 
0 <= ‘POS < N  
1 <= ‘data’ <= 10^7
Where 'N' is the size of the doubly linked list, and ‘data’ is the Integer data of the doubly linked list.
Time Limit: 1 sec

Sample Input 1 :
2
1 1 2 3 4 -1
1
1 2 -1
1
Sample Output 1 :
1 2 3 4
1 

Explanation Of Sample Input 1 :

For the first test case,
‘N’ = 5, 'LIST' = [1, 1, 2, 3, 4, -1], ‘POS’ = 1.
After deleting the node at position 1 the list will be:
1 < - > 2 < - > 3 < - > 4.

For the second test case,
‘N’ = 2,  'LIST' = [1, 2, -1], ‘POS’ = 1.
After deleting the node at position 1 the list will be:
1.

Sample Input 2 :
2
1 2 3 -1
0
3 4 4 -1
2
Sample Output 2 :
2 3
3 4

 */

#include <iostream>
using namespace std;

class Node
{
     public:
          int data;
          Node *next;
          Node *prev;

          Node(int data)
          {
               this->data = data;
               next = NULL;
               prev = NULL;
          }
};

void insertAtEnd(Node* &head, int data)
{
     Node* newNode = new Node(data);

     if(head == NULL)
     {
          head = newNode;
          return;
     }

     Node* temp = head;
     while(temp->next)
          temp = temp->next;

     temp->next = newNode;
     newNode->prev = temp;
}

void deleteNode(Node* &head, int pos)
{
     if(head == NULL)
          return;

     Node* temp = head;

     if(pos == 0)
     {
          head = head->next;
          if(head)
               head->prev = NULL;

          delete temp;
          return;
     }

     for(int i = 0; i < pos && temp; i++)
          temp = temp->next;

     if(temp == NULL)
          return;

     temp->prev->next = temp->next;

     if(temp->next)
          temp->next->prev = temp->prev;

     delete temp;
}

void printList(Node* head)
{
     while(head)
     {
          cout << head->data << " ";
          head = head->next;
     }
     cout << endl;
}

int main()
{
     Node* head = NULL;

     // Input: 1 1 2 3 4 -1
     int x;
     while(cin >> x && x != -1)
     {
          insertAtEnd(head, x);
     }

     int pos;
     cin >> pos;

     deleteNode(head, pos);

     printList(head);

     return 0;
}

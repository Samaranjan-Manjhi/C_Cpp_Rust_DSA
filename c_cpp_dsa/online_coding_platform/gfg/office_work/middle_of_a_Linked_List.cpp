/*

   Middle of a Linked List

   You are given the head of a linked list, You have to return the value of the middle node of the linked list.

   If the number of nodes is odd, return the middle node value.
   If the number of nodes is even, there are two middle nodes, so return the second middle node value.

Examples:

Input: 1->2->3->4->5
Output: 3
Explanation: The given linked list is 1->2->3->4->5 and its middle is 3.


Input:2->4->6->7->5->1 
Output: 7 
Explanation: The given linked list is 2->4->6->7->5->1 so, there are two middle node 6 and 7, return the second middle node as 7.

Constraints:
1 ≤ no. of nodes in head ≤ 105
1 ≤ head.node->data ≤ 105

 */


#include <iostream>
#include <vector>

using namespace std;

struct Node
{
     int data;
     Node* next;

     Node(int x)
     {
          data = x;
          next = nullptr;
     }
};

int getMiddle(Node* head) 
{
     // code here
     Node* slow = head;
     Node* fast = head;
     while(fast != NULL && fast->next != NULL)
     {
          slow = slow->next;
          fast = fast->next->next;
     }

     return slow->data;
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

     int middleValue = getMiddle(head);
     cout << "The middle element is: " << middleValue << endl;

     freeList(head);

     return 0;
}

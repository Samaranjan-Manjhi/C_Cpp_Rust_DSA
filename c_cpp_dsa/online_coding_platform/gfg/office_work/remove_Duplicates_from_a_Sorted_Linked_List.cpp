/*

   Remove Duplicates from a Sorted Linked List

   Given the head of a sorted singly linked list, remove all duplicate nodes so that each element appears only once. The resulting linked list should remain sorted.

Note: Try to solve the problem without using extra space.

Examples:

Input: Head: 2->2->4->5
Output: 2 -> 4 -> 5

Explanation: In the given linked list 2 -> 2 -> 4 -> 5, only 2 occurs more than 1 time. So we need to remove it once.

Input: Head: 2->2->2->2->2
Output: 2

Explanation: In the given linked list  2 -> 2 -> 2 -> 2, 2 is the only element and is repeated 5 times. So we need to remove any four 2.

Constraints:
1 ≤ Number of nodes, data of nodes ≤ 105 

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

Node* removeDuplicates(Node* head) 
{
     // code here
     if(head == NULL || head->next == NULL)
          return head;

     Node* curr = head;
     while(curr != NULL && curr->next != NULL)
     {
          if(curr->data == curr->next->data)
          {
               Node* temp = curr->next;
               curr->next = temp->next;
               delete temp;
          }
          else
          {
               curr = curr->next;
          }
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

     Node* res = removeDuplicates(head);
     cout << "    Result:- ";
     while(res)
     {
          cout << res->data << "->";
          res = res->next;
     }
     cout << "NULL\n";

     freeList(head);

     return 0;
}

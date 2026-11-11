/*

   Given a singly linked list, remove all nodes that have a node with a greater value anywhere to their right in the list. Return the head of the modified linked list.

Examples:

Input: LinkedList = 12->15->10->11->5->6->2->3
Output: 15->11->6->3

Explanation: Since, 12, 10, 5 and 2 are the elements which have greater elements on the following nodes. So, after deleting them, the linked list would like be 15, 11, 6, 3.

Input: LinkedList = 10->20->30->40->50->60
Output: 60

Explanation: All the nodes except the last node has a greater value node on its right, so all the nodes except the last node must be removed.

Constraints:
1 ≤ size of linked list ≤ 106
1 ≤ element of linked list ≤ 106

 */

#include <iostream>
#include <stack>

using namespace std;

struct Node 
{
     public:
     int data;
     Node* next;
     Node(int x)
     {
          data = x;
          next = nullptr;
     }
};

Node *compute(Node *head) 
{
     // code here
     stack<Node*> st;
     if(head == nullptr)
          return head;

     Node* curr = head;
     while(curr != NULL)
     {
          while(!st.empty() && curr->data > st.top()->data)
               st.pop();
          st.push(curr);
          curr = curr->next;
     }

     Node* newNode = nullptr;
     while(!st.empty())
     {
          Node* node = st.top();
          st.pop();
          node->next = newNode;
          newNode = node;
     } 

     return newNode;
}

void printList(Node* head) 
{
     while (head != nullptr) 
     {
          cout << head->data;
          if (head->next != nullptr) cout << " -> ";
          head = head->next;
     }
     cout << " -> NULL" << endl;
}

int main() {
     // num1: 1 -> 2 -> 3 (represents 321)
     Node* num = new Node(1);
     num->next = new Node(2);
     num->next->next = new Node(3);
     num->next->next->next = new Node(3);

     Node* result = compute(num);
     printList(result); // Expected: 5 -> 7 -> 9 -> NULL

     return 0;
}

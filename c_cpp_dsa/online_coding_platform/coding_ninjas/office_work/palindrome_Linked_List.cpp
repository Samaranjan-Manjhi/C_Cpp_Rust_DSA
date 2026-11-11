/*

Palindrome Linked List 

 Problem statement

You are given a singly Linked List of integers. Your task is to return true if the given singly linked list is a palindrome otherwise returns false.
For example:
The given linked list is 1 -> 2 -> 3 -> 2-> 1-> NULL.
It is a palindrome linked list because the given linked list has the same order of elements when traversed forwards and backward​.

Follow Up:
Can you solve the problem in O(N) time complexity and O(1) space complexity iteratively?

Constraints :
1 <= T <= 10
0 <= L <= 10^5
1 <= data <= 10^9 and data != -1
Where L is the number of nodes in the Linked List.
Time Limit: 1 sec

Sample Input 1 :
2
1 2 3 4 5 6 -1
1 2 1 -1
Sample Output 1 :
false
true
Explanation for sample 1:
For the first test case, it is not a palindrome because Linked List doesn't have the same order of elements when traversed forwards and backwards.
For the second test case, it is a palindrome linked list because a Linked List has the same order of elements when traversed forwards and backwards.

Sample Input 2 :
2
1 -1
1 10 45 10 1 -1
Sample Output 2 :
true
true

*/

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class LinkedListNode
{
     public:
          T data;
          LinkedListNode<T> *next;

          LinkedListNode(T data)
          {
               this->data = data;
               this->next = NULL;
          }
};

bool isPalindrome(LinkedListNode<int> *head)
{
     vector<int> v;

     LinkedListNode<int> *temp = head;

     while (temp)
     {
          v.push_back(temp->data);
          temp = temp->next;
     }

     int n = v.size();

     for (int i = 0; i < n / 2; i++)
     {
          if (v[i] != v[n - 1 - i])
               return false;
     }

     return true;
}

int main()
{
     int n;
     cout << "Enter number of nodes: ";
     cin >> n;

     if (n == 0)
     {
          cout << "Palindrome\n";
          return 0;
     }

     cout << "Enter node values: ";

     int x;
     cin >> x;
     LinkedListNode<int> *head = new LinkedListNode<int>(x);
     LinkedListNode<int> *tail = head;

     for (int i = 1; i < n; i++)
     {
          cin >> x;
          tail->next = new LinkedListNode<int>(x);
          tail = tail->next;
     }

     if (isPalindrome(head))
          cout << "Palindrome\n";
     else
          cout << "Not Palindrome\n";

     return 0;
}

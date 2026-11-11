/*

   Problem statement

   You are given two non-negative numbers 'num1' and 'num2' represented in the form of linked lists.
   The digits in the linked lists are stored in reverse order, i.e. starting from least significant digit (LSD) to the most significant digit (MSD), and each of their nodes contains a single digit.
   Calculate the sum of the two numbers and return the head of the sum list.

Example :
Input:
'num1' : 1 -> 2 -> 3 -> NULL
'num2' : 4 -> 5 -> 6 -> NULL
Output: 5 -> 7 -> 9 -> NULL
Explanation: 'num1' represents the number 321 and 'num2' represents 654. Their sum is 975.

Sample Input 1 :
3
1 2 3
3
4 5 6
Sample Output 1 :
5 7 9
Explanation for Sample Input 1 :
'num1' represents the number 321 and 'num2' represents 654. Their sum is 975.

Sample Input 2 :
2
0 1
1
0
Sample Output 2 :
0 1
Explanation for Sample Input 2 :
'num1' represents 10 and 'num2' represents 0. Their sum is 10.

Sample Input 3 :
1
2
2
9 9
Sample Output 3 :
1 0 1
Explanation for Sample Input 3 :
'num1' represents 2 and 'num2' represents 99. Their sum is 101.
Expected Time Complexity :
The expected time complexity is O('m' + 'n').

Constraints :
1 <= 'm', 'n' <= 5 * 10^4
0 <= 'data' in any Linked List node <= 9
The numbers do not contain any leading zeros.
If the number is zero, then there is one node having 'data' = 0.
Time Limit: 1 sec

 */


#include <bits/stdc++.h>
using namespace std;

// Definition of a linked list node
struct ListNode 
{
     int data;
     ListNode* next;
     ListNode(int val) : data(val), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* num1, ListNode* num2) 
{
     ListNode* dummy = new ListNode(0); // dummy head
     ListNode* tail = dummy;
     int carry = 0;

     while (num1 != nullptr || num2 != nullptr || carry != 0) 
     {
          int val1 = (num1 != nullptr) ? num1->data : 0;
          int val2 = (num2 != nullptr) ? num2->data : 0;

          int sum = val1 + val2 + carry;
          int digit = sum % 10;
          carry = sum / 10;

          tail->next = new ListNode(digit);
          tail = tail->next;

          if (num1 != nullptr) num1 = num1->next;
          if (num2 != nullptr) num2 = num2->next;
     }
     return dummy->next; // return the real head
}

void printList(ListNode* head) 
{
     while (head != nullptr) 
     {
          cout << head->data;
          if (head->next != nullptr) cout << " -> ";
          head = head->next;
     }
     cout << " -> NULL" << endl;
}

int main() 
{
     // num1: 1 -> 2 -> 3 (represents 321)
     ListNode* num1 = new ListNode(1);
     num1->next = new ListNode(2);
     num1->next->next = new ListNode(3);

     // num2: 4 -> 5 -> 6 (represents 654)
     ListNode* num2 = new ListNode(4);
     num2->next = new ListNode(5);
     num2->next->next = new ListNode(6);

     ListNode* result = addTwoNumbers(num1, num2);
     printList(result); // Expected: 5 -> 7 -> 9 -> NULL

     return 0;
}

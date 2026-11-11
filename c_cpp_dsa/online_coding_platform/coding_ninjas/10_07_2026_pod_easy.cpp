/*

   Reverse First K elements of Queue 

   Problem statement

   You are given a QUEUE containing ‘N’ integers and an integer ‘K’. You need to reverse the order of the first ‘K’ elements of the queue, leaving the other elements in the same relative order.

   You can only use the standard operations of the QUEUE STL:
   1. enqueue(x) : Adds an item x to rear of the queue
   2. dequeue() : Removes an item from front of the queue
   3. size() : Returns number of elements in the queue.
   4. front() : Finds the front element.

   For Example:

   Let the given queue be { 1, 2, 3, 4, 5 } and K be 3.
   You need to reverse the first K integers of Queue which are 1, 2, and 3.
   Thus, the final response will be { 3, 2, 1, 4, 5 }.

Constraints:
1 <= T <= 10
1 <= N <= 10 ^ 5
0 <= K <= N
-10 ^ 9 <= queue elements <= 10 ^ 9
Time limit: 1 sec

Sample Input 1:

2
5 3
1 2 3 4 5
4 2
6 2 4 1
Sample Output 1:
3 2 1 4 5
2 6 4 1

Explanation:

For test case 1: Refer to the example explained above.
For test case 2: The queue after reversing the first 2 elements i.e., 6 and 2 will be { 2, 6, 4, 1 }.

Sample Input 2:
2
5 2
5 3 2 6 4
4 4
1 2 3 4
Sample Output 2:
3 5 2 6 4
4 3 2 1

 */


#include <iostream>
#include <queue>

using namespace std;

void revFrstK(queue<int>& q, int k)
{
     if(q.empty() || k == 0)  
          return;

     int x = q.front();
     q.pop();

     revFrstK(q, k-1);
     q.push(x);
}

queue<int> reverseElements(queue<int> q, int k)
{
     int n = q.size();

     queue<int> res;
     while(!q.empty())
     {
          res.push(q.front());
          q.pop();
     }

     if(k == 0)
          return res;

     revFrstK(res, k);

     for(int i=0;i<n-k;i++)
     {
          res.push(res.front());
          res.pop();
     }

     return res;
}

int main()
{
     int n;
     cout << "Enter Input Size: ";
     cin >> n;

     queue<int> q;
     for(int i=0;i<n;i++)
     {
          int val;
          cin >> val;
          q.push(val);
     }

     int k;
     cout << "Enter k value: ";
     cin >> k;

     queue<int> res = reverseElements(q, k);
     cout << "     After first k reverse Result:- ";
     while(!res.empty())
     {
          cout << res.front() << " ";
          res.pop();
     }
     cout << endl;

     return 0;
}

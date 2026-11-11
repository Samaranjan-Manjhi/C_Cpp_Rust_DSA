/*

   Problem statement

   You will be given ‘Q’ queries. You need to implement a queue using two stacks according to those queries. Each query will belong to one of these three types:
   1 ‘X’: Enqueue element ‘X’  into the end of the nth queue. Returns true after the element is enqueued.
2: Dequeue the element at the front of the nth queue. Returns -1 if the queue is empty, otherwise, returns the dequeued element.

Note:
Enqueue means adding an element to the end of the queue, while Dequeue means removing the element from the front of the queue.

Constraints:
1 <= Q <= 10^5 
1 <= P <= 2
1 <= X <= 10^5
Time limit: 1 sec

Sample Input 1:
7
1 2 
1 3 
2 
1 4 
1 6 
1 7 
2
Sample Output 1:
True 
True
2
True
True
True
3

Explanation of Sample Output 1:
For this input, we have the number of queries, 'Q' = 7.
Operations performed on the queue are as follows:
push(2): Push element ‘2’ into the queue. This returns true.
push(3): Push element ‘3’ into the queue. This returns true.
pop(): Pop the top element from the queue. This returns 2.
push(4): Push element ‘4’ into the queue. This returns true.
push(6): Push element ‘6’ into the queue. This returns true.
push(7): Push element ‘7’ into the queue. This returns true.
pop(): Pop the top element from the queue. This returns 3.

Sample Input 2:
7
1 11 
1 51 
1 26 
2 
1 6
2
2 
Sample Output 2:
True
True
True
11
True
51
26

Explanation for Sample Output 2:
For this input, we have the number of queries, Q = 7.
Operations performed on the queue are as follows:
push(11): Push element ‘11’ into the queue. This returns true.
push(51): Push element ‘51’ into the queue. This returns true.
push(26): Push element ‘26’ into the queue. This returns true.
pop(): Pop the top element from the queue. This returns 11.
push(6): Push element ‘6’ into the queue. This returns true.
         pop(): Pop the top element from the queue. This returns 51.
                pop(): Pop the top element from the queue. This returns 26.

                       */


#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

stack<int> stk1, stk2;

// Enqueues 'X' into the queue. Returns true after enqueuing.
bool enqueue(int X)
{
     // Write your code here.
     stk1.push(X);
     return true;
}

/*
   Dequeues top element from queue. Returns -1 if the queue is empty, 
   otherwise returns the popped element.
 */
int dequeue()
{
     // Write your code here.
     if(stk1.empty() && stk2.empty())
          return -1;

     if(stk2.empty())
     {
          while(!stk1.empty())
          {
               stk2.push(stk1.top());
               stk1.pop();
          }
     }

     int front = stk2.top();
     stk2.pop();
     return front;
}

int main()
{



return 0;
}

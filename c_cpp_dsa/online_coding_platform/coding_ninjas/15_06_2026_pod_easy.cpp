/*

   Problem statement

   You have been given a queue of integers. You need to rearrange the elements of the queue by interleaving the elements of the first half of the queue with the second half.
Note :
The given queue will always be of even length.

For example :
If N= 10
and Q = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
then the output will be
Q = [10, 60, 20, 70, 30, 80, 40, 90, 50, 100]

Constraints:
1 <= T <= 10^2
2 <= N <= 10^3
0 <= data <= 10^4 Where ‘T’ is the number of test cases, “data” is the value of the element of the queue.

Sample Input 1:
1
10
10 20 30 40 50 60 70 80 90 100
Sample Output 1:
10 60 20 70 30 80 40 90 50 100

Sample Input 2:
1
6
10 20 30 40 50 60 
Sample Output 2:
10 40 20 50 30 60 


 */


#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void interLeaveQueue(queue<int>& q) 
{
     int n = q.size();
     if (n % 2 != 0) 
          return;
     vector<int> v;
     while (!q.empty()) 
     {
          v.push_back(q.front());
          q.pop();
     }

     for (int i = 0; i < n / 2; i++) 
     {
          q.push(v[i]);
          q.push(v[i + n / 2]);
     }
}

int main() 
{
     queue<int> q;

     q.push(10);
     q.push(20);
     q.push(30);
     q.push(40);
     q.push(50);
     q.push(60);
     q.push(70);
     q.push(80);
     q.push(90);
     q.push(100);
     q.push(110);

     interLeaveQueue(q);
     while (!q.empty()) 
     {
          cout << q.front() << " ";
          q.pop();
     }
     cout << endl;
     return 0;
}

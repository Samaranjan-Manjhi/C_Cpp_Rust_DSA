/*

 Problem statement

You have been given a queue and an integer ‘K’. You need to reverse the order of the first ‘K’ elements of the queue.
Note :
The relative order of other elements should be maintained.

For example :
If Q = [ 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 ]
and ‘K’ = 4 
then the output will be
Q = [ 40, 30, 20, 10, 50, 60, 70, 80, 90, 100]

Constraints:
1 <= T <= 100
1 <= N <= 100
0 <= DATA <= 10 ^ 4
0 <= K <= N
Where ‘T’ is the number of test cases, ‘N’ is the size of the queue, “DATA” is the value of the element of the queue and ‘K’ is the number of elements to be reversed.
Time limit: 1 sec.

Sample Input 1:
1
10
10 20 30 40 50 60 70 80 90 100
4
Sample Output 1:
40 30 20 10 50 60 70 80 90 100

Sample Input 2:
1
10
10 20 30 40 50 60 70 80 90 100
3
Sample Output 2:
30 20 10 40 50 60 70 80 90 100 

*/

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void reverse(queue<int> &queue, int k)
{
     // Write your code here.
     stack<int> st;
     int i = 0;
     std::queue<int> temp;
     int n = queue.size();
     if(queue.empty())
          return ;
     while(i < k)
     {
          st.push(queue.front());
          queue.pop();
          i++;
     }
     while(!st.empty())
     {
          queue.push(st.top());
          st.pop();
     }
     int j = 0;
     while(j < (n-k))
     {
          temp.push(queue.front()); 
          queue.pop();     
          j++;
     }
     while(!temp.empty())
     {
          queue.push(temp.front());
          temp.pop();
     }
}

int main()
{
     int n;
     cout << "Enter Size of Queue: ";
     cin >> n;

     queue<int> q;

     for(int i=0;i<n;i++)
     {
          int val;
          cin >> val;
          q.push(val);
     }

     int k;
     cout << "Enter K value: ";
     cin >> k;

     reverse(q, k);
     cout << "After K reverse:- ";
     while(!q.empty())
     {
          cout << q.front() << " ";
          q.pop();
     }
     cout << endl;

     return 0;
}

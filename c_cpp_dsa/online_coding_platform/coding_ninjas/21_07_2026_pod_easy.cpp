/*

   Gary and multiplication

   Problem statement

   Gary has recently learned about priority queues and is quite excited about them. He has asked his teacher for an interesting problem. So, his teacher came up with a simple problem.
   The problem is that he now has an integer array 'ARR'. For every index i, he wants to find the product of the largest, second largest and the third largest integer in the range [0, i] given that array has 0 based indexing.
   You have to return the list as required.
Note: Two numbers can be the same value-wise but they should be distinct index-wise.

Example:
If the array is [2, 3, 3, 4], the answer should be:-
-1 
-1
18 (3 * 3 * 2)
36 (4 * 3 * 3) 

Constraints:
1 <= T <= 5
1 <= N <= 10^5 
1 <= X[i] <= 10^6 
Time limit: 1 sec

Sample input 1:
1
4  
2 3 1 4 
Sample output 1:
-1 -1 6 24

Explanation
-1 (no second largest as well as third largest element is present)
-1 (no third largest element is present)
6 (3 * 2 * 1)
24 (4 * 3 * 2)

Sample input 2:
1
6 
1 5 7 3 9 12
Sample output 2:
1 -1 35 105 315 756

 */


#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<long long> multiplication(vector<int> & arr)
{
     // Write your code here. 
     priority_queue<int, vector<int>, greater<int>> pq;
     int n = arr.size();
     vector<long long> res;

     for(int i=0;i<n;i++)
     {
          pq.push(arr[i]);

          if(pq.size() > 3)
          {
               pq.pop();
          }
          if(pq.size() < 3)
          {
               res.push_back(-1);
          }
          else
          {
               long long first = pq.top(); pq.pop();
               long long second = pq.top(); pq.pop();
               long long third = pq.top(); pq.pop();
               long long ans = first * second * third; 
               res.push_back(ans);
               pq.push(first);
               pq.push(second);
               pq.push(third);
          }
     }

     return res;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     vector<long long> res = multiplication(v);
     cout << "   Result:-  ";
     if(!res.empty())
     {
          for(long long x : res)
               cout << x << " ";
          cout << endl;
     }

     return 0;
}

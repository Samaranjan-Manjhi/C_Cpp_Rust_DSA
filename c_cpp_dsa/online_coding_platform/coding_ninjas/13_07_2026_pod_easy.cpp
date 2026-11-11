/*

   Product of the Last K Numbers 

   Problem statement

   Given a sequence of queries of insertion and getProduct, you need to create an array using queries of type-0 and answer queries of type-1.
   In each query, the input is of two types :
   0 X: insert element ‘X’ at the end array.
   1 K: find the product of the last 'K' elements in the array

Note:
For the query of type 1, you can assume that the array has at least k values. And at any time, the product of any contiguous sequence of numbers will fit into a single 32-bit integer without overflowing.

Constraints:
1 <= T <= 3
0 <= X <= 100
0 <= QUERIES <=5000
1 <= K <= 5000
Where X denotes the value to be stored in the array.
Time limit: 1 sec.

Sample Input 1:
1
10
0 3
0 0
0 2
0 5
0 4
1 2
1 3
1 4
0 8
1 2
Sample Output 1:
20 40 0 32

Explanation for Sample Input 1:

After the first 5 insertions, the array will be [3 0 2 5 4]
Product with k=2 is 5*4 = 20
Product with k=3 is 2*5*4 = 40
Product with k=4 is 0*2*5*4 = 0
Insert 8 : [ 3 0 2 5 4 8]
Product with k=2 is 4*8 = 32

Sample Input 2:
1
12
0 24
1 1
0 58
0 2
1 3
0 73
1 3
0 66
0 0
1 4
0 8
1 7
Sample Output 2:
24 2784 8468 0 0

 */


#include <iostream>
#include <vector>

using namespace std;

vector<int> solve( int q, vector<pair<int, int>> queries ) 
{
     // Write your code her
     vector<int> inp, res;
     for(int i=0;i<q;i++)
     {
          int left = queries[i].first;
          int right = queries[i].second;
          if(left == 0)
               inp.push_back(right);

          //cout << "Inpy Size:- " << inp.size() << "    right:- " << right << endl;
          if(left == 1)
          {
               if(!inp.empty())
               {
                    int temp = 1;
                    int n = inp.size();
                    for(int i=n-1;i>=n-right;i--)
                    {
                         temp *= inp[i];
                    }
                    res.push_back(temp);
               }
          }
     }

     return res;
}

int main()
{
     int q;
     cout << "Enter Queries Size: ";
     cin >> q;

     vector<pair<int, int>> v(q);
     for(int i=0;i<q;i++)
     {
          cin >> v[i].first >> v[i].second;
     }

     vector<int> res = solve(q, v);
     cout << "     Result:- " ;
     if(!res.empty())
     {
          for(int x : res)
               cout << x << " ";
          cout << endl;
     }

     return 0;
}

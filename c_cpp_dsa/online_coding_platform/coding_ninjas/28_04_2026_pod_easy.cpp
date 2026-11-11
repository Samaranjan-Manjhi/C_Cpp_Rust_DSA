/*

   Problem statement
   It is a day of celebration here at Coding Ninjas because our beloved Ninja Hu-chan is going to get his JatSu belt (the highest belt a ninja can get). He is just one step away from making his dream come true, but hold the line, Hu-chan’s master knows all his weaknesses and is going to do a final test of his skills before he is announced as the greatest ninja ever.
   Master is aware of Ninja Hu-chan’s rivalry with maths and therefore he gives him a mathematical problem to solve, being a good friend and well-wisher of our Ninja, can you help him solve the problem assigned and thus acclaim the title of the greatest ninja?

   The problem read as follows:
   You are given a number ‘NUM’, return the maximum distance between any two adjacent 1s in the binary representation of 'NUM'.

Note:
The two 1s are called adjacent if there isn’t another 1 between them. The distance between 2 bits is the absolute difference between their bit positions.

Constraints:
1 <= ‘T’ <= 10
1 <= ‘NUM’ <= 10^8
Where ‘T’ is the number of test cases and ‘NUM’ is the given number.
Time Limit: 1sec

Sample Input 1:
1
7
Sample Output 1:
1
Explanation For Sample Input 1:
In the first test case, the binary representation of 7 is “111”. The max distance between the first and second bit or the second and third bit is 1. Hence the answer is 1.

Sample Input 2:
2
5
11
Sample Output 2:
2
2
Explanation For Sample Input 2:
For test case 1, The binary representation of 5 is “101”. The max distance between the first and last bit is 2. 
Hence the answer is 2.
For test case 2, The binary representation of 11 is “1011”. The max distance between the first and third bit(1 based indexing) is 2, between the third and fourth bit, is 1. 
Hence the answer is 2.        

 */

#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

int binaryGap(int num) 
{
     // Write your code here.
     vector<int> res;
     int idx = 1;
     while(num > 0)
     {
          if(num & 1)
          {
               res.push_back(idx);
          }
          num >>= 1;
          idx++;
     }
     int ans = 0;
     for(int i=1;i<res.size();i++)
     {
          ans = max(ans, res[i]-res[i-1]);
     }
     return ans;
}

int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     int res = binaryGap(n);
     cout << "Result:- " << res << endl;
     return 0;
}

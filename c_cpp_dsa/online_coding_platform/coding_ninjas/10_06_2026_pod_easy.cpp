/*

   Problem statement

   Your friend Ninja has been learning about binary numbers lately. In order to understand binary numbers with perfection, Ninja asks you to generate a list of binary numbers from 1 to ‘N’, which he can use later for reference.
   For every integer Ninja gives, your task is to generate all the binary numbers from 1 to ‘N’.

Example:
Consider N = 5,
All the binary numbers from 1 to 5 are: 1, 10, 11, 100, 101.

Constraints:
1 <= T <= 10 
1 <= N <= 10 ^ 5
Time Limit: 1 sec

Sample Input 1:
2
2
6
Sample Output 1:
1 10
1 10 11 100 101 110
Explanation 1:
For the first test case when N = 2. 
We need all the binary numbers from 1 to 2:
1 -> 1
2 -> 10
Thus, the output is 1, 10.
For the second test case when N = 6
We need all the binary numbers from 1 to 6:
1 -> 1
2 -> 10
3 -> 11
4 -> 100
5 -> 101
6 -> 110
Thus, the output is 1, 10, 11, 100, 101, 110.

Sample Input 2:
2
8
4
Sample Output 2:
1 10 11 100 101 110 111 1000
1 10 11 100

 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string numToBin(int num)
{
     //cout << "Start numToBin \n";
     string ans = "";
     while(num > 0)
     {
          int d = num % 2;
          ans += to_string(d);
          num /= 2;
     }
     int n = ans.length();
     int l = 0, r = n-1;
     while(l < r)
     {
          swap(ans[l], ans[r]);
          l++;
          r--;
     }
     return ans;
}

vector<string> generateBinaryNumbers(int n)
{
     // Write your code here.
     //cout << "Start generateBinaryNumbers \n";
     vector<string> res;
     for(int i=1;i<=n;i++)
     {
          string temp = numToBin(i);
          res.push_back(temp);
     }
     return res;
}

int main()
{
     int n;
     cout << "Enter Input Value: ";
     cin >> n;

     vector<string> res = generateBinaryNumbers(n);
     if(!res.empty())
     {
          for(int i=0;i<res.size();i++)
               cout << res[i] << " ";
          cout << endl;
     }

     return 0;
}

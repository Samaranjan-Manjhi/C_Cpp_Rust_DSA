/*

   Given an integer n, return all the n digit numbers in increasing order, such that their digits are in strictly increasing order(from left to right).

Examples :

Input: n = 1
Output: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
Explanation: Single digit numbers are considered to be strictly increasing order.

Input: n = 2
Output: [12, 13, 14, 15, 16, 17, 18, 19, 23....79, 89]
Explanation: For n = 2, the correct sequence is 12 13 14 15 16 17 18 19 23 and so on up to 89.

Input: n = 15
Output: []
Explanation: No such number exist. 

Constraints:
1 ≤ n ≤ 105

 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void backtrack(string s1, int digit, int n, vector<int>& res)
{
     if (s1.length() == n)	
     {
          res.push_back(stoi(s1));
          return;
     }

     for (int i = digit + 1; i <= 9; i++) 
     {
          backtrack(s1 + to_string(i), i, n, res);
     }
}

vector<int> increasingNumbers(int n) 
{
     // code here
     vector<int> res;
     if (n > 9 || n <= 0)
          return res;

     if (n == 1) 
     {
          return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
     }

     backtrack("", 0, n, res);		
     return res;
}

int main()
{
     int n;
     cout << "Enter Input Number: ";
     cin >> n;

     vector<int> res = increasingNumbers(n);
     if(!res.empty())
     {
          for(int x : res)
               cout << x << " ";
          cout << endl;
     }

     return 0;
}

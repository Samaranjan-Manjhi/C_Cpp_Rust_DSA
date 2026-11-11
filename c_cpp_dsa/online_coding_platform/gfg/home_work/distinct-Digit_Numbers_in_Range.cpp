/*

   Distinct-Digit Numbers in Range

   Given two positive integers l and r, find all numbers in the range [l, r] whose digits are all distinct, with no digit repeated. return them in ascending order.

Examples:

Input: l = 10, r = 20
Output: [10, 12, 13, 14, 15, 16, 17, 18, 19, 20]
Explanation: Every number from 10 to 20 has all distinct digits, except 11, since its digit 1 repeats. so 11 is excluded from the result.

Input: l = 1, r = 9
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9]
Explanation: Every number from 1 to 9 is a single digit, so each one trivially has all distinct digits. none are excluded.

Constraints:
1 ≤ l ≤ r ≤ 105

 */


#include <iostream>
#include <vector>

using namespace std;

bool isUnique(int num)
{
     vector<bool> visited(10, false);
     while(num > 0)
     {
          int digit = num%10;
          if(visited[digit])
               return false;

          visited[digit] = true;
          num /= 10;
     }
     return true;
}

vector<int> uniqueNumbers(int l, int r) 
{
     // code here
     vector<int> res;
     for(int i=l;i<=r;i++)
     {
          if(isUnique(i))
               res.push_back(i);
     }

     return res;
}

int main()
{
     int l, r;
     cout << "Enter left and right range: ";
     cin >> l >> r;

     vector<int> res = uniqueNumbers(l, r);
     cout << "    Result:-  ";
     if(!res.empty())
     {
          for(int x : res)
               cout << x << " ";
          cout << endl;
     }

     return 0;
}

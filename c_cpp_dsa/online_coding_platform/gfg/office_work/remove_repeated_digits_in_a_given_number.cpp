/*

   Remove repeated digits in a given number

   Given an integer N represented in the form of a string, remove consecutive repeated digits from it.

   Example 1:
Input:
N = 1224
Output: 124
Explanation: Two consecutive occurrences of 
2 have been reduced to one.

Example 2:
Input: 
N = 1242
Output: 1242
Explanation: No digit is repeating 
consecutively in N.

Your Task:
You don't need to read input or print anything. Your task is to complete the function modify() which takes the integer N as input and returns the modified integer by removing all the consecutive duplicate occurrences in N.

Expected Time Complexity: O(LogN).
Expected Auxiliary Space: O(1).

Constraints:
1<=N<=10^18

 */

#include <iostream>

using namespace std;

long long int modify(long long int N) 
{
     // your code here
     long long int res = 0;
     long place = 1;
     long prev = -1;
     while(N > 0)
     {
          long curr = N%10;
          N /= 10;
          if(curr != prev)
          {
               res = res + (curr * place);
               place *= 10;
               prev = curr;
          }
     }

     return res;
}

int main()
{
     long long int n;
     cout << "Enter Input Number: ";
     cin >> n;

     long long int res = modify(n);
     cout << "    Result:- " << res << endl;

     return 0;
}

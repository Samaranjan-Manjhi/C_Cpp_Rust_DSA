/*

   Perfect Reversible String

   You are given a string ‘str’, the task is to check that reverses of all possible substrings of ‘str’ are present in ‘str’. If yes then the answer is 1, otherwise, the answer will be 0.

   Example 1:

Input: n = 2, str = "ab"
Output: 0
Explanation: All substrings are "a",
"b","ab" but reverse of "ab" is not 
present in str.

â€‹Example 2:

Input: n = 3, str = "aba"
Output: 1
Explanation: Reverse of all possible 
substring is present in str.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function isReversibleâ€‹() which takes the string str and n (the length of str) as inputs and returns the answer.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ n ≤ 2 * 105

 */


#include <iostream>
#include <string>

using namespace std;

int isReversible(string str, int n) 
{
     // complete the function here
     string s = str;
     int l = 0, r = s.size() - 1;
     while (l < r)
     {
          if (s[l] != s[r])
               return 0;
          l++;
          r--;
     }
     return 1;
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     cin >> str;

     int res = isReversible(str, str.length());
     cout << "    Result:- " << res << endl;

     return 0;
}

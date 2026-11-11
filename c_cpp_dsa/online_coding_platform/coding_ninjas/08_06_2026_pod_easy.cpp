/*

   Problem statement

   You are given a positive integer 'N'. You have to generate all possible sequences of balanced parentheses using 'N' pairs of parentheses.
   A sequence of brackets is called balanced if one can turn it into a valid math expression by adding characters ‘+’ and ‘1’. For example, sequences ‘(())()’, ‘()’ and ‘(()(()))’ are balanced, while ‘)(‘, ‘(()’ and ‘(()))(‘ are not.
   For example :
   For N = 1, there is only one sequence of balanced parentheses,  ‘()’.
   For N = 2, all sequences of balanced parentheses are ‘()()’, ‘(())’.

Constraints :
1 <= T <= 10
1 <= N <= 11

Sample Input 1:
3
1
2
3
Sample Output 1:
()
(()) ()()
((())) (()()) (())() ()(()) ()()()
Explanation For Sample Input 1:
In the 1st test case, there is only 1 possible sequence of balanced parentheses.
In the 2nd test case, there are 2 possible sequences of balanced parentheses.
In the 3rd test case, there are 5 possible sequences of balanced parentheses.

Sample Input 4:
1
4
Sample Output 4:
(((()))) ((()())) ((())()) ((()))() (()(())) (()()()) (()())() (())(()) (())()() ()((())) ()(()()) ()(())() ()()(()) ()()()() 

 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void generate(int n, string curr, int open, int close, vector<string>& ans) 
{
     if (open == n && close == n) 
     {
          ans.push_back(curr);
          return;
     }

     if (open < n) 
     {
          generate(n, curr + "(", open + 1, close, ans);
     }

     if (close < open) 
     {
          generate(n, curr + ")", open, close + 1, ans);
     }
}

vector<string> balancedParentheses(int n) 
{
     vector<string> ans;
     generate(n, "", 0, 0, ans);
     return ans;
}

int main()
{
     int n;
     cout << "Enter Input n Value: ";
     cin >> n;

     vector<string> res = balancedParentheses(n);
     for (string s : res) 
          cout << s << "\n";
     cout << endl;
     return 0;
}

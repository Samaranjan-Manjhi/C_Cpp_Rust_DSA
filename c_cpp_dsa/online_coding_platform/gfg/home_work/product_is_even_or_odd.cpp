/*

   Product is even or odd?

   You are given two long numbers N1 and N2 in a string. You need to find out if the product of these numbers generate an even number or an odd number, If it is an even number print 1 else print 0.

   Example 1:

Input: 
N1 = "12"
N2 = "15"
Output: 1
Explanation: 12 * 15 = 180 which is an 
even number.

â€‹Example 2:

Input: 
N1 = "123"
N2 = "457"
Output: 0
Explanation: 123*457 = 56211 which is an 
odd number.

Your Task:
You don't need to read input or print anything. Your task is to complete the function EvenOdd() which accepts two strings N1 and N2 as input parameter and returns 1 or 0 accordingly.

Expected Time Complexity: O(1).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N1, N2 ≤ 1099

 */

#include <iostream>
#include <string>

using namespace std;

int EvenOdd(string n1, string n2) 
{
     // code here.
     int s1 = n1[n1.size()-1] - '0';
     int s2 = n2[n2.size()-1] - '0';
     int prod = s1*s2;
     if(prod % 2 == 0)
          return 1;

     return 0;
}

int main()
{
     string s1;
     cout << "Enter Num1 String: ";
     cin >> s1;

     string s2;
     cout << "Enter Num2 String: ";
     cin >> s2;

     int res = EvenOdd(s1, s2);
     cout << "     Result:- " << res << endl;

     return 0;
}

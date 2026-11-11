/*

   Maximum Number in a String

   Given an alphanumeric string s consisting of lowercase letters (a–z), uppercase letters (A–Z), and digits (0–9).

   Extract all numeric substrings from s and return the maximum numeric value among them.

   If no numeric substring exists, return -1.

Examples:

Input: s = "100klh564abc365bg"
Output: 564
Explanation: Numeric values in string s are 100, 564 and 365. But 564 is maximum among them. So answer is 564.

Input: s = "abcdefg"
Output: -1
Explanation: Since there is no numeric value in the string. So answer is -1. 

Constraints:
1 ≤ |s| ≤ 104
-1 ≤ output value ≤ 106

 */


#include <iostream>
#include <string>

using namespace std;

int extractMaximum(string &s) 
{
     // code here
     int ans = -1; 
     int n = s.length();
     int temp = 0;
     bool isNum = false; 
     bool processingNum = false; 

     for (int i = 0; i < n; i++) 
     {
          if (s[i] >= '0' && s[i] <= '9') 
          {
               isNum = true;
               processingNum = true;
               temp = temp * 10 + (s[i] - '0');
          } 
          else 
          {
               if (processingNum) 
               {
                    ans = max(ans, temp);
                    temp = 0;
                    processingNum = false;
               }
          }
     }

     if (processingNum) 
     {
          ans = max(ans, temp);
     }

     if (!isNum) 
     {
          return -1;
     }

     return ans;
}

int main()
{
     string s;
     cout << "Enter Input String: ";
     getline(cin, s);

     int res = extractMaximum(s);
     cout << "     Result:- " << res << endl;

     return 0;
}

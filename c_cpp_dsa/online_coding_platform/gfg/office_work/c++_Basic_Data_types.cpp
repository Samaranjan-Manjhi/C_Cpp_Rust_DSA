/*

   C++ Basic Data types

   Given a String S. Find out which of the following basic C++ data types it represents and return it's size (in bytes).
   The possible data types are:
   1. Integer
   2. Float
   3. Double
   4. Character

   Example 1:

Input:
S=a
output:
1
Explanation:
The string clearly represents char 
and thus the size of char is displayed.

Example 2:

Input
S=98.45685456
Output: 
8
Explanation:
The string represents Double.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function BasicDataType() which takes String S as input parameter and displays the size (in bytes) of the datatype it represents. 

Expected Time Complexity:O(N)
Expected Auxillary Space:O(1)

Constraints:
1<=|S|<=10

 */

#include <iostream>

using namespace std;

int BasicDataType(string s) 
{
     // code here
     if(!isdigit(s[0]) and s[0] != '.')
          return sizeof(char);
     else if(s.find('.') == string::npos)
          return sizeof(int);
     else
          return (s.length() - s.find('.') - 1 ) < 6 ? sizeof(float) : sizeof(double);
}

int main()
{
     string s;
     cout << "Enter Input String: ";
     cin >> s;

     int res = BasicDataType(s);
     cout << "     Result:- " << res << endl;

     return 0;
}

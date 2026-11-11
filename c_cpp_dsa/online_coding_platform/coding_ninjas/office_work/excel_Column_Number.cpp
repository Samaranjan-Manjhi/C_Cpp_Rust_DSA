/*

   Excel Column Number

   Problem statement

   You have been given a column title as appears in an Excel sheet, return its corresponding column number.
   For example:

   A -> 1
   B -> 2
   C -> 3
   ...
   Z -> 26
   AA -> 27
   AB -> 28 
   ...

Constraints:
1 <= |S| <= 10
Input contains only uppercase English Alphabet letters
Time Limit : 1 sec

Output Format
The only line of output will print the column number corresponding to given column title 

Sample Input 1
AB
Sample Output 1
28

Sample Input 2
ZZZ
Sample Output 2
18278

 */


#include <iostream>
#include <string>

using namespace std;

long long excelColumnNumber(string input)
{
     // your code goes here
     long long ans = 0;
     int n = input.length();
     for(char ch : input)
     {
          int val = ch - 'A' + 1;
          ans = ans * 26 + val;
     }

     return ans;
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     cin >> str;

     long long ans = excelColumnNumber(str);
     cout << "     Result:- " << ans << endl;

     return 0;
}

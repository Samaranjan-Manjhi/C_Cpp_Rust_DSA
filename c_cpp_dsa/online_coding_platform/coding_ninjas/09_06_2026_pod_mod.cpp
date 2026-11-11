/*

   Problem statement

   You are given two strings A and B. Find the index of the first occurrence of A in B. If A is not present in B, then return -1.
   For Example:
   A = “bc”, B = “abcddbc”.
   String “A” is present at index 1, and 5(0-based index), but we will return 1 as it is the first occurrence of “A” in string “B”.
   Follow Up:
   Can you solve this in linear time and space complexity?

Constraints:
1 <= T <= 100
1 <= |A|, |B| <= 5 * 10^4 
Time limit: 1 second

Sample Input 1:
2
ninjas codingninjas
code codingninjas
Sample Output 1:
6
-1
Explanation For Sample Input 1:
For the first test case, “ninjas” is present at the 6th index of “codingninjas”.
For the second test case, “code” is not present in “codingninjas”.

Sample Input 2:
2
e add
en engagement
Sample output 2:
-1
0

 */

#include <iostream>
#include <string>

using namespace std;

void startNot(string& str)
{
     // In-built function
     /*if (!str.empty()) 
     { 
          str.erase(0, 1);    
     }*/
     int n = str.length();
     if(n == 0)
          return;
     for(int i=1;i<n;i++)
          str[i-1] = str[i];

     str.resize(n-1);
}

/* // time limit exceeded
int findIndexOf(string a, string b)
{
     //Write your code here
     int res = 0;
     int al = a.length(), bl = b.length();
     if(al > bl)
          return -1;
     string temp = "";
     for(int i=0;i<al;i++)
     {
          temp += b[i];
     }
     if(temp == a)
          return 0;

     cout << "temp:-- " << temp << endl;
     for(int i=al;i<bl;i++)
     {
          if(temp.length() >= al)
          {
               startNot(temp) ;
               temp += b[i];
               if(temp == a)
                    return i-al+1;
          }
     }
     return -1;
}
*/

int findIndexOf(string a, string b) 
{
     int al = a.length(), bl = b.length();
     if (al > bl) 
          return -1;

     for (int i = 0; i <= bl - al; i++) 
     {
          int j = 0;
          while (j < al && b[i + j] == a[j]) 
               j++;
          if (j == al) 
               return i;
     }
     return -1;
}

int main()
{
     string s1;
     cout << "Enter Search Input string 1 : ";
     cin >> s1;

     string s2;
     cout << "Enter Main Input string 2 : ";
     cin >> s2;

     int res = findIndexOf(s1, s2);
     cout << "Result:-  " << res << endl;

     return 0;
}

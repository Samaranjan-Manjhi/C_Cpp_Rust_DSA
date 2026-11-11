/*

   Problem statement

   You are given the text ‘IPAddress’. Your task is to check if the given text ‘IPAddress’ is a valid ‘IPv4’ or not.

   Conditions for a valid ‘IPv4’ are:
   1. Text form of ‘IPAddress’ must be ‘a.b.c.d’
   2. The values of a,b,c and d can vary from ‘0’ to ‘255’ and both ‘0’ and ‘255’ are inclusive.

Constraints:
1 <= T <= 10^4
1 <= length of given text <= 50
Time limit: 1 sec

Sample Input 1:
4
123.111.12.k
122.0.330.0
1.1.1.250
1.0.0.0.1
Sample Output 1:
False
False
True
False

Explanation of sample input 1:
Test Case 1:
Given text ‘IPAddress = 123.111.12.k’, it is satisfying the first condition that given ‘IPAddress’ must be ‘a.b.c.d’ formed but it not satisfying the second condition that d must in a range of ‘0’ to ‘255’ but the value of ‘d’ is ‘k’.
Hence return ‘False’.
Test Case 2:
Given text ‘IPAddress = 122.0.330.0’, it is satisfying the first condition that given ‘IPAddress’ must be ‘a.b.c.d’ formed but it not satisfying the second condition that c must in a range of ‘0’ to ‘255’ but the value of ‘c’ is ‘330’ and it is out of range.
Hence return ‘False’.
Test Case 3:
Given text ‘IPAddress = 1.1.1.250’, it is satisfying the first condition that given ‘IPAddress’ must be ‘a.b.c.d’ formed as well as it satisfying the second condition that a,b,c, and d must in range of ‘0’ to ‘250’.
Hence return ‘True’.
Test Case 4:
Given text ‘IPAddress = 1.0.0.0.1’, it is not satisfying the first condition for valid ‘IPv4’, that text ‘IPAddress’ must be in form of ‘a.b.c.d’ but given text is a form of ‘a.b.c.d.e’
Hence return ‘False’.

Sample Input 2:
2
1.90.21.1
1.1
Sample Output 2:
True
False

 */

#include <iostream>
#include <string>

using namespace std;

bool isValidIPv4(string ipAddress)
{
     // Write your code here.
     int dec_cnt = 0;
     for(char ch : ipAddress)
     {
          if(ch == '.')
               dec_cnt++;
     }
     if(dec_cnt > 3 || dec_cnt < 3)
          return false;

     for(char ch : ipAddress)
     {
          if(ch == '.')
               continue;
          else if(!(ch >= '0' && ch <= '9'))
               return false;
     }

     int a = 0, b = 0, c = 0, d = 0;
     int n = ipAddress.length();
     int part = 0;
     for(int i=0;i<n;i++)
     {
          if(ipAddress[i] == '.')
          {
               part++;
               continue;
          }
          if(part == 0)
               a = a * 10 + (ipAddress[i] - '0');
          else if(part == 1)
               b = b * 10 + (ipAddress[i] - '0'); 
          else if(part == 2)
               c = c * 10 + (ipAddress[i] - '0');
          else
               d = d * 10 + (ipAddress[i] - '0');
     }

     if(!((a >= 0 && a <= 255) && (b >= 0 && b <= 255) && (c >= 0 && c <= 255) && (d >= 0 && d <= 255)))
          return false;
     return true;
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     getline(cin, str);

     bool res = isValidIPv4(str);
     if(res)
          cout << "   Yes\n";
     else
          cout << "   No\n";

     return 0;
}

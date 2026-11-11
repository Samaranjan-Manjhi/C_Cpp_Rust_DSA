/*

   Encode the Message 

   Problem statement

   You have been given a text message. You have to return the Run-length Encoding of the given message.

   Run-length encoding is a fast and simple method of encoding strings. The basic idea is to represent repeated successive characters as the character and a single count. For example, the string "aaaabbbccdaa" would be encoded as "a4b3c2d1a2".

Constraints :
1 <= T <= 10
1 <= N <= 100000
Where 'N' is the length of the message string.
Time Limit: 1 sec

Sample Input 1 :
3
aabbc
abcd
abbdcaas
Sample Output 1 :
a2b2c1
a1b1c1d1
a1b2d1c1a2s1

Explaination for Sample Input 1:

Test Case 1: As 2 consecutive 'a', 2 consecutive 'b', and 1 'c' are present in the given string so output is "a2b2c1".
Test Case 2: As 1 consecutive 'a', 1 consecutive 'b', 1 consecutive 'c' and 1 consecutive 'd' are present in the given string so output is "a1b1c1d1".
Test Case 3: As 1 consecutive 'a', 2 consecutive 'b', 1 consecutive 'd', 1consecutive 'c', 2 consecutive 'a' and 1 consecutive 's' are present in the given string so output is "a1b2d1c1a2s1".

Sample Input 2:
2
sadasd
adsad
Sample Output 2:
s1a1d1a1s1d1
a1d1s1a1d1

 */


#include <iostream>
#include <stack>
#include <string>

using namespace std;

string encode(string &message)
{
     //   Write your code here.
     stack<char> st;
     string res = "";
     int cnt = 1;
     char temp;
     for(char c : message)
     {
          temp = c;
          if(st.empty())
               st.push(c);
          else
          {
               if(c == st.top())
               {
                    cnt++;
               }
               else
               {
                    res += st.top();
                    res += to_string(cnt);
                    st.push(c);
                    cnt = 1;
               }
          }
     }

     res += temp;
     res += to_string(cnt);
     //cout << "res:- " << res << endl;
     return res;
}

int main()
{
     string s;
     cout << "Enter Input String: ";
     cin >> s;

     string res = encode(s);
     cout << "    Result:- " << res << endl;

     return 0;
}

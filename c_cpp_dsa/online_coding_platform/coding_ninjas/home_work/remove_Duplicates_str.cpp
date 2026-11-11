/*

   Remove Duplicates 

   Problem statement

   Given a string S, remove consecutive duplicates from it recursively.
Constraints :

1 <= |S| <= 10^3
where |S| represents the length of string

Sample Input 1 :
aabccba
Sample Output 1 :
abcba

Sample Input 2 :
xxxyyyzwwzzz
Sample Output 2 :
xyzwz

 */

#include <iostream>
#include <string>
#include <stack>
#include <cstring>

using namespace std;

void removeConsecutiveDuplicates(char *input) 
{
     /* Don't write main().
      * Don't read input, it is passed as function argument.    
      * Change in the given string itself.
      * No need to return or print anything
      * Taking input and printing output is handled automatically.
      */
     stack<char> st;
     for(int i=0;i<strlen(input);i++)
     {
          char c = input[i];
          if(st.empty())
               st.push(c);
          else if(st.top() != c)
               st.push(c);     
     }
     string res = "";
     while(!st.empty())
     {
          res += st.top();
          st.pop();
     }
     int l = 0, r = res.length()-1;
     while(l < r)
     {
          swap(res[l], res[r]);
          l++;
          r--;
     }

     strcpy(input, res.c_str());
}

int main()
{
     string s;
     cout << "Enter Input String: ";
     cin >> s;

     int n = s.length();
     char input[n+1];
     strcpy(input, s.c_str());

     removeConsecutiveDuplicates(input);
     cout << "     Result:- " << input << endl;

     return 0;
}

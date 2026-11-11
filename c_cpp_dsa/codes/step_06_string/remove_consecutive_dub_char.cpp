/*

   Remove consecutive duplicates from string.
   "aabbccdde" -> "abcde"
   Asked at: Zoho, Paytm, Swiggy

 */

#include <iostream>
#include <string>

using namespace std;

string remove_consecutive_dup_char(const string& s)
{
     string ans = "";
     ans += s[0];
     int n = s.length();
     for(int i=1;i<n;i++)
     {
          if(s[i] != s[i-1])
               ans += s[i];
     }
     return ans;
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     cin >> str;

     string res = remove_consecutive_dup_char(str);
     cout << "Result:- " << res << endl;

     return 0;
}

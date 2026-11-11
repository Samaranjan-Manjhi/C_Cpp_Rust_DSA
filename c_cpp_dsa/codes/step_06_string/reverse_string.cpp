/*

   Reverse a string.
Methods: two-pointer, using std::reverse, recursion.
Asked at: TCS, Wipro, Infosys, Capgemini

 */

#include <iostream>
#include <string.h>
#include <algorithm> 

using namespace std;

// Using 2 pointer
string reverse_String(string& str)
{
     int l = 0;
     int r = str.length()-1;
     string res = str;
     while(l < r)
     {
          swap(res[l], res[r]);
          l++;
          r--;
     }
     return res;
}

// Using std::reverse
string rev_str(string& str)
{
     string res = str;
     std::reverse(res.begin(), res.end());
     return res;
}

// Using recursive
string str_rev(string& str, int idx)
{
     string res = str;
     if(idx < 0)
          return "";
     return res[idx] + str_rev(res, idx-1);
}

int main()
{
     string s;
     cout << "Enter String to reverse: ";
     getline(cin, s);

     //Using 2 Pointer
     string res = reverse_String(s);
     cout << "Using 2-Pointer Result:->  " << res << endl;

     //Using std::reverse
     string res2 = rev_str(s);
     cout << "Using std::reverse Result:->  " << res2 << endl;

     //Using recursion
     string res3 = str_rev(s, s.length()-1);
     cout << "Using recursion Result:->  " << res3 << endl;

     return 0;
}

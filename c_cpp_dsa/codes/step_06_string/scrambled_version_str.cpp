/*

   Check if string B is a scrambled version of string A (character rotation).
   "Shift all characters by same amount mod 26"
   Asked at: TCS, Capgemini

 */

#include <iostream>
#include <string>

using namespace std;

bool is_scrambled_ver(const string& s1, const string& s2)
{
     if (s1.length() != s2.length()) return false;
     int n = s1.length();
     int shift = (s2[0] - s1[0] + 26) % 26;
     for (int i = 1; i < n; i++)
     {
          int curr_shift = (s2[i] - s1[i] + 26) % 26;
          if (curr_shift != shift)
               return false;
     }
     return true;
}


int get_shift_value(const string& s1, const string& s2)
{
     if (s1.length() != s2.length()) return -1;
     int n = s1.length();
     int shift = (s2[0] - s1[0] + 26) % 26;
     for (int i = 1; i < n; i++)
     {
          int curr_shift = (s2[i] - s1[i] + 26) % 26;
          if (curr_shift != shift)
               return -1;
     }
     return shift;
}

int main()
{
     string s1;
     cout << "Enter Input Original String: ";
     cin >> s1;

     string s2;
     cout << "Enter Input Scramble String: ";
     cin >> s2;


     bool res = is_scrambled_ver(s1, s2);
     if(res)
          cout << "Yes\n";
     else
          cout << "No\n";

     cout << "Result:- " << get_shift_value(s1, s2) << endl;

     return 0;
}

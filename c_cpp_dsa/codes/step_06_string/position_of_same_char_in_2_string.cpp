/*

   Given two strings, find the number of positions where
   they have the same character.
   Asked at: TCS, Wipro

 */

#include <iostream>
#include <string>

using namespace std;

int position_of_same_char_in_2_string(const string& str1, const string& str2)
{
     int cnt = 0;
     int n = str1.length(), m = str2.length();
     for(int i=0;i<min(n, m);i++)
     {
          if(str1[i] == str2[i])
               cnt++;
     }

     return cnt;
}

int main()
{
     string s1;
     cout << "Enter Input String1: ";
     cin >> s1;

     string s2;
     cout << "Enter Input String2: ";
     cin >> s2;

     int pos = position_of_same_char_in_2_string(s1, s2);
     if(pos != -1)
          cout << "Position where have common character in both strings:- " << pos << endl;
     else
          cout << "No Common element.\n";

     return 0;
}

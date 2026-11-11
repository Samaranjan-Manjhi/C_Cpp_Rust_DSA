/*

   Count occurrences of a given character in a string.
   Asked at: TCS, Wipro

 */

#include <iostream>
#include <string>

using namespace std;

int occurrences_Count_of_char_in_string(const string& s, char c)
{
     int cnt = 0;
     if(s.length() == 0)
          return cnt;
     for(char ch : s)
     {
          if(ch == c)
               cnt++;
     }
     return cnt;
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     getline(cin, str);

     char ch;
     cout << "Enter character to find occurrance: ";
     cin >> ch;

     int res = occurrences_Count_of_char_in_string(str, ch);
     cout << "Result:- " << res << endl;

     return 0;
}

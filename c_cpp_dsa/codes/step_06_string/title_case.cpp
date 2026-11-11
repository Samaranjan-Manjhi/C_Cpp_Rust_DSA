/*

   Convert a sentence to title case (first letter of each word uppercase).
   Asked at: TCS, Wipro, Infosys

 */

#include <iostream>
#include <string>

using namespace std;

string sentence_to_title_case(string& s)
{
     int n = s.length();
     string res = "";
     for(int i=0;i<n;i++)
     {
          if( i == 0 || s[i-1] == ' ')
          {
               if(s[i] >= 'a' && s[i] <= 'z')
                    //res += s[i] - 'a' + 'A';               
                    s[i] = s[i] - 'a' + 'A';               
               //else
                    //res += s[i];
          }
          //else
               //res += s[i];
     }
     return s;
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     getline(cin, str);

     string res = sentence_to_title_case(str);
     cout << "Result:-  " << res << endl;

     return 0;
}

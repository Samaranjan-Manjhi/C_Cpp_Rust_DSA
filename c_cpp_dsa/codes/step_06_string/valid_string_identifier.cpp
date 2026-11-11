/*

   Check if a string is a valid identifier.
   (Starts with letter or _, followed by letters, digits, _)
   Asked at: TCS, Wipro, Zoho

 */

#include <iostream>
#include <string>

using namespace std;

bool valid_string_identifier(string& s)
{
     int n = s.length();
     if(n == 0) return false;
     if(!(s[0] == '_' || (s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z')))
          return false;

     for(int i=1;i<n;i++)
     {
          if(!(s[i] == '_' || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')))
               return false;
     }
     return true;
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     getline(cin, str);

     bool res = valid_string_identifier(str);
     if(res)
          cout << "String is Valid identifier.\n";
     else
          cout << "String is not Valid identifier.\n";

     return 0;
}

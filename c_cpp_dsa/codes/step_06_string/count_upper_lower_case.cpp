/*

   Count the number of uppercase and lowercase letters in a string.
   Asked at: TCS, Wipro, Capgemini

 */

#include <iostream>
#include <string>

using namespace std;

pair<int, int> upper_lower_case(const string& s)
{
     int upper = 0, lower = 0;
     for(char ch : s)
     {
          if(ch >= 'A' && ch <= 'Z')
               upper++;
          else if(ch >= 'a' && ch <= 'z')
               lower++;
          else
               continue;
     }
     return {upper, lower};
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     getline(cin, str);

     pair<int, int> res = upper_lower_case(str);
     cout << "Count of Uppercase letters:-  " << res.first << endl;
     cout << "Count of Lowercase letters:-  " << res.second << endl;

     return 0;
}

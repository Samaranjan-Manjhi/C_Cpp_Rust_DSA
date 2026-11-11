/*

   Check if string contains only digits.
   Asked at: TCS, Wipro, Capgemini

 */

#include <iostream>
#include <string>

using namespace std;

bool contain_only_digits(const string& s)
{
     for(char ch : s)
     {
          if(!(ch >= '0' && ch <= '9'))
               return false;
     }

     return true;
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     getline(cin, str);

     bool res = contain_only_digits(str);
     if(res)   
          cout << "Yes\n";
     else
          cout << "No\n";

     return 0;
}

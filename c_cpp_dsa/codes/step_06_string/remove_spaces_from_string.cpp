/*

   Remove all spaces from a string.
   Asked at: TCS, Infosys

 */

#include <iostream>
#include <string>

using namespace std;

/*
   string remove_space_from_str(string& str)
   {
   string ans = "";
   for(char ch : str)
   {
   if(ch != ' ')
   ans += ch;
   }
   return ans;
   }
 */

// More optimize
/*
   string remove_space_from_str(string& str)
   {
   string ans;
   ans.reserve(str.size());
   for(char ch : str)
   {
   if(ch != ' ')
   ans += ch;
   }
   return ans;
   }
 */

string remove_space_from_str(string& str)
{
     int j = 0;
     for(int i=0;i<str.size();i++)
     {
          if(str[i] != ' ')
          {
               str[j] = str[i];
               j++;
          }
     }     
     str.resize(j);
     return str;
}

int main()
{
     string s;
     cout << "Enter String: ";
     getline(cin, s);

     string res = remove_space_from_str(s);
     cout << "Result:- " << res << endl;

     return 0;
}

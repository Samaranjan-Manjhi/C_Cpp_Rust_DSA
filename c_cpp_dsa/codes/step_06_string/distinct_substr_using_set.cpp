/*

Print all distinct substrings of a string using a set.
             Asked at: Amazon, Zoho

*/

#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string> all_distinct_substrings_of_str(const string& s)
{
     set<string> st;
     int n = s.length();
     if(n == 0)
          return st;

     for(int i=0;i<n;i++)
     {
          string temp = "";
          int j = i;
          while(j < n)
          {
               temp += s[j];
               st.insert(temp);
               j++;
          } 
          //st.insert(temp);
     }

     return st;
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     getline(cin, str);
     set<string> res = all_distinct_substrings_of_str(str);
     if(!res.empty())
     {
          for(auto& str : res)
               cout << str << " ";
          cout << endl;
     }

     return 0;
}

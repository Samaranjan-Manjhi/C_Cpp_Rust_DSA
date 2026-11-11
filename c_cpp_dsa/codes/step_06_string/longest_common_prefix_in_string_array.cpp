/*

   Find the longest common prefix among an array of strings.
   Vertical scanning approach.
   Asked at: Amazon, Flipkart

 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longest_common_prefix_strings_array(vector<string>& v)
{
     string ans = "";
     int n = v.size();
     if(n == 0)
          return ans;
     for(int i=0;i<v[0].size();i++)
     {
          char ch = v[0][i];
          bool match = true;

          for(int j=1;j<n;j++)
          {
               if(i >= v[j].size() || v[j][i] != ch)
               {
                    match = false;
                    break;
               }
          }

          if(match)
               ans += ch;
          else
               break;
     }
     return ans;
}

int main()
{
     int n;
     cout << "Enter Size of Vector: ";
     cin >> n;

     vector<string> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     string res = longest_common_prefix_strings_array(v);
     cout << "longest common prefix among an array of strings:-  " << res << endl;

     return 0;
}

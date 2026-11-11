#include <iostream>
#include <cstring>
using namespace std;

bool takeover(string& s1, string& s2)
{
     int cnt = 0;
     for(int i=0;i<s1.size();i++)
     {
          if(s1[i] != s2[i])
          {
               cout << s1[i] << "   " << s2[i] << endl;
               cnt++;
          }
     }
     if(cnt > 2)
          return false;
     return true;
}

int main()
{
     string str = "wrrd";
     string str1 = "wook";
     bool res = takeover(str, str1);
     if(res)
          cout << "Yes" << endl;
     else
          cout << "No" << endl;
     return 0;
}

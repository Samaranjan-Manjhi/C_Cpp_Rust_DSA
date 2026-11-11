#include <iostream>
#include <string.h>
using namespace std;
int main()
{
     int n;
     cout << "Enter a Number: ";
     cin >> n;
     string s = to_string(n);
     int i = 0, k = 1, j = s.length()-1;
     int cnt = 1;
     {
          while(i < j)
          {
               cout << "s[i] " << s[i] << "     " << "s[j] " << s[j] << endl;
               if(s[i] < s[j])
               {
                    swap(s[i], s[j]);
                    goto final;
               }
               else
                    i++;
          }
     }
final:
     cout << "s :- " << s << endl;
     return 0;
}

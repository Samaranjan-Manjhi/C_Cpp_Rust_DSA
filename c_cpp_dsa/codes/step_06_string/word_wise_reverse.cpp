#include <iostream>
#include <string.h>

using namespace std;
/*
void doSwap(string& stri)
{
     int n = stri.length()-1;
     int m = 0;
     while(m < n)
     {
          swap(stri[m], stri[n]);
          m++;
          n--;
     }
}
string reverseString(string &str){
     // Write your code here.
     string s = "";
     string w = "";
     int n = str.length()-1;
     for(int i=n;i>=0;i--)
     {
          if(str[i] != ' ')
               w += str[i];
          else if(str[i] == ' ')
          {
               doSwap(w);
               s += w + " ";
               w = "";
          }
     }	
     doSwap(w);
     s += w;
     return s;
}
*/
void doSwap(string& stri)
{
    int n = stri.length() - 1;
    int m = 0;
    while(m < n)
    {
        swap(stri[m], stri[n]);
        m++;
        n--;
    }
}

string reverseString(string &str)
{
    string s = "";
    string w = "";

    for(int i = str.length()-1; i >= 0; i--)
    {
        if(str[i] != ' ')
        {
            w += str[i];
        }
        else
        {
            if(!w.empty())
            {
                doSwap(w);
                if(!s.empty())
                    s += " ";
                s += w;
                w = "";
            }
        }
    }
    if(!w.empty())
    {
        doSwap(w);
        if(!s.empty())
            s += " ";
        s += w;
    }
    return s;
}

int main()
{
     string s;
     cout << "Enter String: ";
     getline(cin, s);

     string res = reverseString(s);
     cout << "Results:-  " << res << endl;
     return 0;
}


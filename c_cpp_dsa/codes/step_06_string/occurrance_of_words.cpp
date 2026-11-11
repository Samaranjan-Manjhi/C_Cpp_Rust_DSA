/*

   Count occurrences of a word in a sentence (case-insensitive).
   Asked at: TCS, Wipro, Zoho

 */

#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> Word_Occurrences_Count(const string& s)
{
     map<string, int> mp;
     int n = s.length();
     string word = "";
     for(int i=0;i<n;i++)
     {
          if(s[i] == ' ')
          {
               if(!word.empty())
               {
                    //cout << "word:- " << word << endl;
                    mp[word]++;
                    word = "";
               }
          }
          else
          {
               if((s[i] >= 65 && s[i] <= 90) || (s[i] >= 92 && s[i] <= 122) || (s[i] >= '0' && s[i] <= '9'))
               {
                    if(s[i] >= 65 && s[i] <= 90)
                         word += s[i]+32;
                    else
                         word += s[i];
               }
               else
                    continue;
          }
     }
     if(!word.empty())
     {
          //cout << "word:- " << word << endl;
          mp[word]++;
     }
     return mp;
}

int main()
{
     string str;
     cout << "Enter Input Sentense: ";
     getline(cin, str);

     map<string, int> res = Word_Occurrences_Count(str);
     if(!res.empty())
     {
          for(auto& s : res)
          {
               cout << "   " << s.first << "    &   " << s.second << endl; 
          }
     }

     return 0;
}

/*

   Reverse only the words in a sentence, not the characters.
   "hello world" -> "world hello"
   Asked at: Amazon, Microsoft, TCS, Zoho

 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> reverse_only_words_not_char(const string& s)
{
     vector<string> res;
     int n = s.length();
     if(n == 0)
          return res;
     string temp = "";
     bool isWord = false;
     for(char ch : s)
     {
          if(ch == ' ')
          {
               isWord = true;
               res.push_back(temp);
               temp = "";
          }
          else
          {
               temp += ch;
          }
     }

     if(isWord)
          res.push_back(temp);     

     int v = res.size();
     int l = 0, r = v-1;
     while(l <= r)
     {
          swap(res[l], res[r]);
          l++;
          r--;
     }
     return res;
}

void inPlaceSwap(string& s, int l, int r)
{
     while(l <= r)
     {
          swap(s[l], s[r]);
          l++;
          r--;
     }
}

void reverse_only_words_not_char(string& s)
{
     int n = s.length();
     if(n == 0)
          return;
     inPlaceSwap(s, 0, n-1);
     int start = 0;
     for(int i=0;i<n;i++)
     {
          if(s[i] == ' ')
          {
               inPlaceSwap(s, start, i-1);
               start = i+1;
          }
     }
     inPlaceSwap(s, start, n-1);
}

int main()
{
     string str;
     cout << "Enter Input Sentence: ";
     getline(cin, str);

     /*
        vector<string> res = reverse_only_words_not_char(str); 
        if(!res.empty())
        {
        for(string st : res)
        cout << st << " ";
        cout << endl;
        }
      */

     reverse_only_words_not_char(str);
     cout << "Reverse:- " << str << endl;
     return 0;
}

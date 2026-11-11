/*

   Find the most frequent character in a string.
   Asked at: TCS, Amazon, Zoho

 */

#include <iostream>
#include <unordered_map>

using namespace std;

/*
char most_frequent_char(string& s)
{
     unordered_map<char, int> umap;
     for(char ch : s)
     {
          umap[ch]++;
     }
     int maxi = 0;
     char res = '\0';
     for(auto ch : umap)
     {
          //cout << "ch.first:- " << ch.first << "   & ch.second:- " << ch.second << endl;
          if(ch.second > maxi)
          {
               maxi = ch.second;
               res = ch.first;
          }
     }
     //cout << "maxi:- " << maxi << endl;
     return res;
}
*/
char most_frequent_char(const string& s) 
{
     int freq[256] = {0}; 

     for (char ch : s) 
     {
          freq[(unsigned char)ch]++;
     }

     char result = '\0';
     int maxi = 0;

     for (int i = 0; i < 256; i++) 
     {
          if (freq[i] > maxi) 
          {
               maxi = freq[i];
               result = (char)i;
          }
     }

     return result;
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     cin >> str;

     char res = most_frequent_char(str);
     cout << "Result:- " << res << endl;

     return 0;
}

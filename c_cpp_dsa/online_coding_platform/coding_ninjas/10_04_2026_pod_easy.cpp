/*
   Given a string ‘STR’ consisting of lower case English letters, the task is to find the first non-repeating character in the string and return it. If it doesn’t exist, return ‘#’.
 */
#include <iostream>
#include <map>
#include <cstring>
using namespace std;

int main()
{
     //string str = "bbabcbcb"; // a
     //string str = "babaabea"; // e
     //string str = "cbbd"; // c
     //string str = "bebeeed"; // d
     string str = "abcd"; // a
     map<char, int> mp;
     for(char ch : str)
     {
          mp[ch]++;
     }
     for(char ch:str)
     {
          if(mp[ch] == 1)
               cout << ch << endl;
          else
               cout << "#" << endl;
     }
     return 0;
}

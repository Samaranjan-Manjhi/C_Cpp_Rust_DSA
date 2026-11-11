/*

   Check if two strings are anagrams.
   Method 1: sort both. Method 2: frequency array of 26. O(N).
   Asked at: Amazon, Microsoft, Zoho, Flipkart

 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Method 1: sort both.
bool strings_anagrams(const string& st1, const string& st2)
{
     string s1 = st1;
     string s2 = st2;
     sort(s1.begin(), s1.end());
     sort(s2.begin(), s2.end());
     if(s1 != s2)
          return false;
     return true;
}

// Method 2: frequency array of 26. O(N).
bool strings_anagrams_freq(const string& s1, const string& s2)
{
     if(s1.length() != s2.length())
          return false;

     int freq[26] = {0};

     for(char ch : s1)
          freq[ch - 'a']++;

     for(char ch : s2)
          freq[ch - 'a']--;

     for(int i=0;i<26;i++)
     {
          if(freq[i] != 0)
               return false;
     }

     return true;
}

int main()
{
     string str1;
     cout << "Enter input String 1: ";
     getline(cin, str1);

     string str2;
     cout << "Enter input String 2: ";
     getline(cin, str2);

     // Method 1: Sorting
     //bool isAnagrams = strings_anagrams(str1, str2);
     // Method 2: Using frequency
     bool isAnagrams = strings_anagrams_freq(str1, str2);
     if(isAnagrams)
          cout << "Both strings are Anagrams.\n"; 
     else
          cout << "Both strings are not Anagrams.\n";

     return 0;
}

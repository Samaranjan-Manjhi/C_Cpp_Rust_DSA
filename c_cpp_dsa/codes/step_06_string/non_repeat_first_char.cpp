/*

   First non-repeating character in a string.
   (Frequency array + linear scan)
   Asked at: Amazon, Microsoft, Adobe, Zoho, Flipkart

 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Using unordered_map
char first_non_repeating_char(string& s)
{
     unordered_map<char, int> freq;
     char ans;
     for(char ch : s)
     {
          freq[ch]++;
     }
     for(char ch : s)
     {
          if(freq[ch] == 1)
               return ch;
     }
     return '\0';
}

// Using Frequency array
char first_non_repeating_char1(string& s)
{
     int freq[26] = {0};
     char ans;
     for(char ch : s)
     {
          freq[ch]++;
     }
     for(char ch : s)
     {    
          if(freq[ch] == 1)
               return ch;
     }
     return '\0';
}

// Using Linear scan
char first_non_repeating_char2(string& s)
{
     int n = s.length();
     for(int i=0;i<n;i++)
     {
          bool unique = true;
          for(int j=0;j<n;i++)
          {
               if(i != j && s[i] == s[j])
               {
                    unique = false;
                    break;
               }
          }

          if(unique)
               return s[i];
     }
     return '\0';
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     getline(cin, str);

     char res = first_non_repeating_char(str);
     cout << "Using unordered_map Result:--   " << res << endl;

     char res1 = first_non_repeating_char1(str);
     cout << "Using frequency array Result:--   " << res << endl;

     char res2 = first_non_repeating_char2(str);
     cout << "Using linear scan Result:--   " << res << endl;

     return 0;
}

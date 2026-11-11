/*

   Check if a string has all unique characters.
   Method 1: O(N^2) brute force.
   Method 2: O(N) with bitmask (only lowercase letters — 26-bit int).
   Asked at: Amazon, Microsoft, Adobe

 */

#include <iostream>
#include <string>

using namespace std;

bool all_unique_char_in_str(const string& s)
{
     bool seen[26] = {false};
     for(char ch : s)
     {
          if(ch < 'a' || ch > 'z')
               continue;

          int idx = ch - 'a';
          if(seen[idx])
          {
               return false;
          }
          else
          {
               seen[idx] = true;
          }
     }
     return true;
}

// Using Bitmask
bool all_unique_char_in_str1(const string& s)
{
    int mask = 0;  // 26-bit storage
    for(char ch : s)
    {
        int pos = ch - 'a';
        // check if bit is already set
        if(mask & (1 << pos))
        {
            return false; // duplicate found
        }

        // set the bit
        mask = mask | (1 << pos);
    }
    return true;
}

// Using brute force
bool all_unique_char_in_str2(const string& s)
{
     int n = s.length();
     for(int i=0;i<n;i++)
     {
          for(int j=i+1;j<n;j++)
          {
               if(s[i] == s[j])
                    return false;
          }
     }
     return true;
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     getline(cin, str);

     bool res = all_unique_char_in_str(str);
     bool res1 = all_unique_char_in_str1(str);
     bool res2 = all_unique_char_in_str2(str);
     if(res && res1 && res2)
          cout << "All unique char in string.\n";
     else
          cout << "Not all unique char in string.\n";

     return 0;
}

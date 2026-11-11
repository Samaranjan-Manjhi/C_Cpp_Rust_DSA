/*

Find all starting indices of anagrams of pattern P in string S.
             Use sliding window + frequency array comparison.
             Asked at: Amazon, Microsoft, Flipkart

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void removeFirstChar(string& s)
{
     int n = s.length();
     for(int i=1;i<n;i++)
     {
          s[i-1] = s[i];
     }
     s.resize(n-1);
}

vector<int> idx_of_anagram(const string& s, const string& p)
{
     vector<int> res;
     string tempPat = p;
     sort(tempPat.begin(), tempPat.end());
     int n = s.length();
     int m = p.length();
     if(m > n)
          return res;
     string compa = "";
     for(int i=0;i<m;i++)
     {
          compa += s[i];
     }
     string temp_compa = compa;
     sort(temp_compa.begin(), temp_compa.end());
     if(temp_compa == tempPat)
          res.push_back(0);

     for(int i=m;i<n;i++)
     {
          if(compa.length() >= m)
          {
               removeFirstChar(compa);
               compa += s[i];
               temp_compa = compa;
               //cout << "compa in main loop: " << compa <<   "   "  << tempPat << endl;
               sort(temp_compa.begin(), temp_compa.end());
               if(temp_compa == tempPat)
                    res.push_back(i-m+1);
          }
     }
     return res;
}

// ChatGPT Code
vector<int> findAnagrams(const string& s, const string& p) 
{
     vector<int> res;
     int n = s.size();
     int m = p.size();

     if(m > n) 
          return res; 
     int patFreq[128] = {0};
     int winFreq[128] = {0};
     for(char ch : p) 
          patFreq[ch]++;
     for(int i = 0; i < m; i++) 
          winFreq[s[i]]++;
     bool match = true;
     for(int i = 0; i < 128; i++) 
     {
          if(winFreq[i] != patFreq[i]) 
          {
               match = false;
               break;
          }
     }
     if(match) 
          res.push_back(0);

     for(int i = m; i < n; i++) 
     {
          winFreq[s[i - m]]--;
          winFreq[s[i]]++;
          match = true;
          for(int j = 0; j < 128; j++) 
          {
               if(winFreq[j] != patFreq[j]) 
               {
                    match = false;
                    break;
               }
          }
          if(match) 
               res.push_back(i - m + 1);
     }
     return res;
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     getline(cin, str);

     string pat;
     cout << "Enter Input Pattern: ";
     cin >> pat;

     vector<int> res = idx_of_anagram(str, pat);
     if(!res.empty())
     {
          for(int x : res)
               cout << x << " ";
          cout << endl;
     }

     return 0;
}

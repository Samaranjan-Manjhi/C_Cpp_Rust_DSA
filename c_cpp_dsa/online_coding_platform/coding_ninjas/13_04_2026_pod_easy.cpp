/*
   ### Asked in Adobe & Optum
   Problem statement
   You are given a certain format of books and their authors.
   For example -
   NameOfAuthor1 Book1 Book2
   NameOfAuthor2 Book1

   Your task is to print the given information in the following manner:
   1. NameOfAuthor1
     A. Book1
     B. Book2

   2. NameOfAuthor2
     A. Book1

   You are given a 2D array of strings ‘S’ where each vector is the information about the i-th author, the first index of this vector is the ‘NameOfAuthor’ and the other indexes are the ‘Books’ written by the author. You are supposed to print the Authors and their books in the above mentioned format.

 */

#include <iostream>
#include <vector>
using namespace std;

vector<string> arrangeAuthors(vector<vector<string>> &s)
{
     vector<string> res;
     for(int i = 0; i < s.size(); i++)
     {
          res.push_back(to_string(i + 1) + ". " + s[i][0]);
          char ch = 'A';
          for(int j = 1; j < s[i].size(); j++)
          {
               string line = "    ";
               line += ch++;
               line += ". ";
               line += s[i][j];
               res.push_back(line);
          }
     }
     return res;
}

int main()
{
     int t;
     cin >> t;
     while(t--)
     {
          int n;
          cin >> n;
          vector<vector<string>> s;
          for(int i = 0; i < n; i++)
          {
               int k;
               cin >> k;
               vector<string> temp;
               for(int j = 0; j <= k; j++) 
               {
                    string str;
                    cin >> str;
                    temp.push_back(str);
               }
               s.push_back(temp);
          }
          vector<string> res = arrangeAuthors(s);
          for(string line : res)
          {
               cout << line << endl;
          }
     }
     return 0;
}

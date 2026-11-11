/*

Array Subset

Given two arrays a[] and b[], your task is to determine whether b[] is a subset of a[].

Examples:

Input: a[] = [11, 7, 1, 13, 21, 3, 7, 3], b[] = [11, 3, 7, 1, 7]
Output: true
Explanation: b[] is a subset of a[]

Input: a[] = [1, 2, 3, 4, 4, 5, 6], b[] = [1, 2, 4]
Output: true
Explanation: b[] is a subset of a[]

Input: a[] = [10, 5, 2, 23, 19], b[] = [19, 5, 3]
Output: false
Explanation: b[] is not a subset of a[]

Constraints:
1 <= a.size(), b.size() <= 10^5
1 <= a[i], b[j] <= 10^6

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
bool isSubset(vector<int> &a, vector<int> &b) 
{
     sort(a.begin(), a.end());
     sort(b.begin(), b.end());

     int i = 0, j = 0;
     while (i < a.size() && j < b.size()) 
     {
          if (a[i] == b[j]) 
          {
               i++;
               j++;
          } 
          else if (a[i] < b[j]) 
          {
               i++;
          } 
          else 
          {
               // a[i] > b[j], so b[j] is missing in a
               return false;
          }
     }
     return (j == b.size());
}
*/

bool isSubset(vector<int> &a, vector<int> &b) 
{
     // Your code here
     unordered_map<int, int> ma;
     for(int x : a)
          ma[x]++;

     for(int x : b)
     {
          if(ma[x] == 0)
               return false;
          ma[x]--;
     }

     return true;
}

int main()
{
     int a;
     cout << "Enter Vector1 Size: ";
     cin >> a;

     vector<int> va(a);
     for(int i=0;i<a;i++)
          cin >> va[i];

     int b;
     cout << "Enter Vector2 Size: ";
     cin >> b;

     vector<int> vb(b);
     for(int i=0;i<b;i++)
          cin >> vb[i];

     bool res = isSubset(va, vb);
     if(res)
          cout << "     Yes\n";
     else
          cout << "     Nope\n";

     return 0;
}

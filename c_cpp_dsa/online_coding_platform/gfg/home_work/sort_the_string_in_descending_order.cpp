/*

Sort the string in descending order

Given a string s containing only lowercase alphabets, the task is to sort it in lexicographically-descending order.
Note : A string is in lexicographically descending order if characters are arranged from larger to smaller based on dictionary order (i.e., 'z' comes before 'a').

Examples:

Input: s = "geeks"
Output: "skgee"
Explanation: It's the lexicographically descending order.

Input: s = "for"
Output: "rof"
Explanation: "rof" is in lexicographically-descending order.

Constraints:
1 ≤ |s| ≤ 105

*/


#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string ReverseSort(string str) 
{
     // complete the function here
     sort(str.begin(), str.end());
     int n = str.length();
     string res = str;
     int l = 0, r = n-1;
     while(l < r)
     {
          swap(res[l], res[r]);
          l++;
          r--;
     }

     return res;
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     cin >> str;

     string res = ReverseSort(str);
     cout << "    Result:- " << res << endl;

     return 0;
}

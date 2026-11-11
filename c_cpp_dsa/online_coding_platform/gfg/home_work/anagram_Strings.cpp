/*

   Anagram Strings

   Given two strings S1 and S2 . Return "1" if both strings are anagrams otherwise return "0" .
Note: An anagram of a string is another string with exactly the same quantity of each character in it, in any order.

Example 1:

Input: S1 = "cdbkdub" , S2 = "dsbkcsdn"
Output: 0 
Explanation: Length of S1 is not same
as length of S2.

Example 2:

Input: S1 = "geeks" , S2 = "skgee"
Output: 1
Explanation: S1 has the same quantity 
of each character in it as S2.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function areAnagram() which takes S1 and S2 as input and returns "1" if both strings are anagrams otherwise returns "0".

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(K) ,Where K= Contstant

Constraints:
1 <= |S1| <= 1000
1 <= |S2| <= 1000 

 */


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int areAnagram(string S1, string S2) 
{
     // code here
     if(S1.length() != S2.length())
          return 0;

     sort(S1.begin(), S1.end());
     sort(S2.begin(), S2.end());

     for(int i=0;i<S1.size();i++)
     {
          if(S1[i] != S2[i])
               return 0;
     }        

     return 1;
}

int main()
{
     string str;
     cout << "Enter Input String1: ";
     cin >> str;

     string str1;
     cout << "Enter Input String2: ";
     cin >> str1;

     int res = areAnagram(str, str1);
     cout << "     Result:- " << res << endl;

     return 0;
}

/*

   Find All Anagrams in a String

   Problem statement

   You have been given a string STR and a non-empty string PTR. Your task is to find all the starting indices of PTR’s anagram in STR.
   An anagram of a string is another string which contains the same characters and is obtained by rearranging the characters.
   For example: ‘SILENT’ and ‘LISTEN’ are anagrams of each other. ‘ABA’ and ‘ABB’ are not anagram because we can’t convert ‘ABA’ to ‘ABB’ by rearranging the characters of particular strings.

Note:
1. Both STR and PTR consist of English uppercase letters.
2. Length of string 'STR' will always be greater than or equal to the length of string ‘PTR’.
3. In case, there is no anagram substring, then return an empty sequence.
4. In case of more than one anagrams, return the indices in increasing order.

Constraints:
1 <= T <= 100
1 <= N <= 10^5
1 <= M <= N
Time limit: 1 second

Sample Input 1 :
2
10 3
CBAEBABACD
ABC
5 2
ABADE
BA
Sample Output 1 :
0 6
0 1

Explanation For Sample Output 1:

Test Case 1:
'STR' is ‘CBAEBABACD’ and ‘PTR’ is ‘ABC’.
0-2 in 'STR' index 0,1,2 are ‘CBA’, and it is an anagram with ‘ABC’.
1-3 in 'STR' index 1,2,3 are ‘BAE’, and it is not anagram with ‘ABC’.
2-4 in 'STR' index 2,3,4 are ‘AEB’, and it is not anagram with ‘ABC’.
3-5 in 'STR' index 3,4,5 are ‘EBA’, and it is not anagram with ‘ABC’.
4-6 in 'STR' index 4,5,6 are ‘BAB’, and it is not anagram with ‘ABC’.
5-7 in 'STR' index 5,6,7 are ‘ABA’, and it is not anagram with ‘ABC’.
6-8 in 'STR' index 6,7,8 are ‘BAC’, and it is an anagram with ‘ABC’.
7-9 in 'STR' index 7,8,9 are ‘ACD’, and it is not anagram with ‘ABC’.
Hence, there are only two substrings in the given string 'STR'  that are anagram with given string  ‘PTR’ which are ‘CBA’, and ‘BAC’ and starting indices of respective anagram substrings are 0 and 6.

Test case 2:
'STR' is ‘ABADE’ and ‘PTR’ is ‘BA’.
In the given string ‘ABADE’ the substring of length 2 starting with index 0 is ‘AB’ which is an anagram with the string ‘BA’ and a substring of length 2 starting with index 1 is ‘BA’ which is also an anagram with the string ‘BA’. Because 0 and 1 are starting indices of the substrings, we print 0 and 1.

Sample Input 2:
2
10 4
BACDGABCDA
ABCD
7 1
ABABABA
A
Sample Output 2:
0 5 6
0 2 4 6

 */


#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> findAnagramsIndices(string str, string ptr, int n, int m)
{
     // Write you code here.
     vector<int> res;
     if(n < m)
          return res;
     vector<int> pt(26, 0), win(26, 0);

     for(int i=0;i<m;i++)
     {
          pt[ptr[i] - 'A']++;
          win[str[i] - 'A']++;
     }

     if(pt == win)
          res.push_back(0);

     for(int right=m;right<n;right++)
     {
          char inc = str[right];
          char out = str[right - m];
          win[inc - 'A']++;
          win[out - 'A']--;
          if(win == pt)
          {
               int left = right-m+1;
               res.push_back(left);
          }
     }

     return res;
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     cin >> str;

     string ptr;
     cout << "Enter Pattern String: ";
     cin >> ptr;

     vector<int> res = findAnagramsIndices(str, ptr, str.length(), ptr.length());
     cout << "   Result:-  "; 
     if(!res.empty())
     {
          for(int x : res)
               cout << x << " ";
          cout << endl;
     }

     return 0;
}

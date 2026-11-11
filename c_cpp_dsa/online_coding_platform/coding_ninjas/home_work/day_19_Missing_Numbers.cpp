/*

   Day 19 : Missing Numbers 

   Problem statement

   You are given an array 'ARR' of distinct positive integers. You need to find all numbers that are in the range of the elements of the array, but not in the array. The missing elements should be printed in sorted order.
Example:
If the given array is [4, 2, 9] then you should print "3 5 6 7 8". As all these elements lie in the range but not present in the array.

Constraints:
1 <= T <= 10
1 <= N <= 10^5
0 <= 'ARR[i]' <= 150000
Where 'ARR[i]' denotes the array element.
Time Limit: 1 sec

Sample Input 1:
2
4
1 2 4 6
3
1 2 3
Sample Output 1:
3 5
[Blank]    
Explanation for Sample Output 1:
In test case 1, As only 3 and 5 are not in the array and both lie in the range of the array. Thus answer would be "3 5" i.e sorted order.
In test case 2, Since all the elements are present from 1 to 3, the empty list is returned as a answer.

Sample Input 2:
2
3
7 4 9
4
3 6 7 4
Sample Output 2:
3 5 6 8
5
Explanation for Sample Output 2:
In test case 1, As only 3, 5, 6 and 8 are not in the array and lie in the range of the array. Thus answer would be "3 5 6 8" i.e sorted order.
In test case 2, As only 5 is not in the array and lie in the range of the array. Thus answer would be "5".

 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> missingNumbers(vector<int> &arr, int n) 
{
     // Write your code here.
     vector<int> res;

     sort(arr.begin(), arr.end());

     for(int i = arr.front(); i <= arr.back(); i++)
     {
          if(!binary_search(arr.begin(), arr.end(), i))
               res.push_back(i);
     }

     return res; 
}

int main()
{
     int  n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     vector<int> res = missingNumbers(v, n);
     if(!res.empty())
     {
          for(int x : res)
               cout << x << " ";
          cout << endl;
     }
     else
          cout << "[Blank]\n";

     return 0;
}

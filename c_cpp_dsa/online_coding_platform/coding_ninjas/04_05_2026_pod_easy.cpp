/*

   Problem statement

   Ninja loves cooking, and he decided to make the pizza for his friend. His friend loves eating cheese with the pizza; hence Ninja decided to fill the pizza with the cheese.
   For our convenience, let's consider the rectangular pizza slices only, and to increase the amount of cheese, the Ninja decided to cut some slices in pizza. Each slice can be cut only once, and the resulting pieces must also be rectangular.
   Ninja decided to cut it in at most 'K' slices so that no one gets suspicious.
   Given 'N' number of slices have, 'K' maximum number of slices Ninja can cut and two arrays ‘L’ and ‘B’ stating the length and breadth of each slice, your task is to help Ninja find out the maximum extra cheese needed to fill the newly formed boundaries in pizza.
EXAMPLE:

Input: 'N' = 2, 'K' = 1
'L' = [4, 2]
'B' = [6, 8]
Output: 16
To maximize the cheese usage, Ninja can cut a second cake parallel to the side of length 8. So extra cheese needed will be 16.

Constraints :
1 <= 'T' <= 10
1 <= 'N' <= 10^4
0 <= 'K' <= N
1 <= 'L[i]', 'B[i]' <= 10^4
Time Limit: 1sec

Sample Input 1 :
2
2 1
4 2
6 8
1 1
4 6
Sample Output 1 :
16
12

Explanation Of Sample Input 1 :
For the first test case, to maximize the cheese usage, Ninja can cut a second slice parallel to the side of length 8. So extra cheese needed will be 16.
For the second test case, Ninja can cut the slice parallel to side 6 to get the extra cheese = (40) - (28) = 12

Sample Input 2 :
2
3 2
1 2
3 2
1 3
5 3
2 3
4 5
2 3
2 3
1 2
Sample Output 2 :
12
22

 */


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxExtraCheese(int n, int k, vector<int> l, vector<int> b) 
{
     // Write your code here.
     // Vector to store the extra cheese values (difference in areas after cuts)
     vector<float> extraCheese;
     for(int i = 0; i < n; i++)
     {
          // Original area of the slice
          float originalArea = l[i] * b[i];
          // Area after cutting along the length (halving the length)
          float areaAfterCuttingLength = (l[i] / 2.0) * b[i];
          // Area after cutting along the breadth (halving the breadth)
          float areaAfterCuttingBreadth = l[i] * (b[i] / 2.0);
          // Extra cheese created by each cut
          float extraFromLength = originalArea - areaAfterCuttingLength;
          float extraFromBreadth = originalArea - areaAfterCuttingBreadth;
          // We want the maximum extra cheese from the two cut options
          extraCheese.push_back(max(extraFromLength, extraFromBreadth));
     }
     sort(extraCheese.rbegin(), extraCheese.rend());
     // Sum the top 'k' extra cheese values
     float totalExtraCheese = 0;
     for(int i = 0; i < min(k, n); i++) // Ensure not to exceed available slices
     {
          totalExtraCheese += extraCheese[i];
     }

     return totalExtraCheese; 
}

int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;

     int k;
     cout << "Enter maximum Cuts: ";
     cin >> k;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     vector<int> v1(n);
     for(int i=0;i<n;i++)
          cin >> v1[i];

     int res = maxExtraCheese(n, k, v, v1);
     cout << "Result:- " << res << endl;

     return 0;
}

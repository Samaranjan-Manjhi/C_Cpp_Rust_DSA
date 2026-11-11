/*

   Fish Eater

   Problem statement

   There is a river which flows in one direction. One day, the river has 'N' number of fishes. You are given an array 'FISHES' of integers representing the size of 'N' fishes. The fishes are present in the river from left to right(0th index represents the size of the leftmost fish). As the river flows from left to right so the fishes also swim from left to right. The fishes are of different sizes and have different speeds. The larger fishes are faster than the smaller fishes. Also, larger fishes can eat smaller fishes but can’t eat fishes of the same size.

   Can you find the number of fishes that survive at the end of the day?

Example:
Let the size of fishes present in the river from left to right be{ 4, 2, 3, 1, 5 }.
1. As fish 4 is faster and bigger than fish 2, so fish 4 will eat fish 2.
Remaining fishes: { 4, 3, 1, 5 }
2. As fish 3 is faster and bigger than fish 1, so fish 3 will eat fish 1.
Remaining fishes: { 4, 3, 5 }
3. As fish 4 is faster and bigger than fish 3, so fish 4 will eat fish 3.
Remaining fishes: { 4, 5 }
Now fish 5 cannot eat fish 4, as fish 5 is faster than fish 4 and they swim from left to right. Thus, fish 4 will never reach fish 5.

Finally, we are left with only 2 fishes.

Constraints:
1 <= T <= 10
1 <= N <= 10^4
1 <= FISHES[i] <= 10^9
Where 'FISHS[i]' denotes the size of the ith fish in the river.
Time limit: 1 sec

Sample Input 1:
2
5
4 2 3 1 5
3
8 1 3
Sample Output 1:
2
1

Explanation of Sample Output 1:

In test case 1, Refer to the example in problem description.

In test case 2,
Fishes: { 8, 1, 3 }
As fish 8 is faster and bigger than fish 1, so fish 8 will eat fish 1.
Remaining fishes: { 8, 3 }
As fish 8 is faster and bigger than fish 3, so fish 8 will eat fish 3.
Remaining fishes: { 8 }
Here, only 1 fish is left at last.

Sample Input 2:
2
4
1 2 3 4
4
4 4 2 4
Sample Output 2:
4
3

Explanation of Sample Output 2:

In test case 1, As eachfish on the left side is smaller than fish on its right side and thus no fish can eat any other fish and the number of surviving fishes will be 4.

In test case 2,
Fishes: { 4, 4, 2, 4}
As fish with equal size cannot eat each other as having the same speed, All the Fishes with size 4 will survive.
Fish 2 with size 4 will eat the fish 3 with size 2.
Remaining fishes: { 4, 4, 4 }
Here, 3 fishes is left at last.

*/


#include <iostream>
#include <vector>

using namespace std;

int fishEater(vector<int> &fishes) 
{
     // Write your code here.
     int n = fishes.size();
     if(n == 0)
          return 0;

     vector<int> res;
     res.push_back(fishes[0]);
     int maxi = fishes[0];
     for(int i=1;i<n;i++)
     {
          if(maxi <= fishes[i])
          {
               maxi = fishes[i];
               res.push_back(fishes[i]);
          }
     }
     return res.size();
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int res = fishEater(v);
     cout << "    Result:- " << res << endl;

     return 0;
}

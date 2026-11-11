/*

Last Coin in a Game of Alternates

Given an array integer arr[] , representing the values of coins arranged in a row.
    Two players play a game by picking coins alternately.
    At each turn, a player can pick a coin from either the beginning or the end of the array. Both players follow a greedy strategy, i.e., they always pick the coin with the maximum value among the two available ends.
    The game continues until only one coin remains.
Find the value of the last remaining coin.

Examples:

Input : arr[] = [5, 3, 1, 6, 9]
Output : 1
Explanation:
Players always pick the larger coin from the two ends.
Pick 9, remaining array: [5, 3, 1, 6]
Pick 6, remaining array: [5, 3, 1]
Pick 5, remaining array: [3, 1]
Pick 3, remaining array: [1]
Final Output: 1

Input : arr[] = [5, 9, 2, 5]
Output : 2
Explanation:
Players always pick the larger coin from the two ends.
Pick 5, remaining array: [9, 2, 5]
Pick 9, remaining array: [2, 5]
Pick 5, remaining array: [2]
Final Output: 2

Input : arr[] = [11]
Output : 11
Explanation:
Only one coin is present in the array, so no moves are made.
Final Output: 11

Constraints :
1 ≤ arr.size() ≤ 10^5
1 ≤ arr[i] ≤ 10^6

*/

#include <iostream>
#include <vector>

using namespace std;

int coin(vector<int>& arr)
{
     while(arr.size() > 1)
     {
          if(arr.front() > arr.back())
          {
               arr.erase(arr.begin());
          }
          else
          {
               arr.pop_back();
          }
     }
     return arr.front();
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int res = coin(v);
     cout << "    Result:- " << res << endl;

     return 0;
}

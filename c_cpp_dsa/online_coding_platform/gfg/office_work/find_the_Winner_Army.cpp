/*

Find the Winner Army

Two armies, A and B, have the same number of soldiers. The power of their soldiers is given by arr1[] and arr2[], where the ith soldier of Army A fights only the ith soldier of Army B.

    If arr1[i] > arr2[i], Army A wins the battle.
    If arr1[i] < arr2[i], Army B wins the battle.
    If arr1[i] == arr2[i], both soldiers are eliminated.

Return "A" if Army A wins more battles, "B" if Army B wins more battles, otherwise return "DRAW"

Examples:

Input: arr1[] = [2, 2], arr2[] = [5, 5]
Output: "B"
Explanation: 
Battle 1: 2 < 5, so Army B wins.
Battle 2: 2 < 5, so Army B wins.
Army B wins 2 battles, while Army A wins 0 battles. Therefore, the winner is "B".

Input: arr1[] = [9], arr2[] = [8]  
Output: "A"
Explanation: 
Battle 1: 9 > 8, so Army A wins.
Army A wins 1 battle, while Army B wins 0 battles. Therefore, the winner is "A".

Constraints:
1 ≤ arr1.size() ≤ 10^6
0 ≤ arr1[i],arr2[i] ≤ 10^5

*/

#include <iostream>
#include <vector>

using namespace std;

string countryAtWar(vector<int>& arr1, vector<int>& arr2) 
{
     // code here
     int a = 0, b = 0;
     for(int i=0;i<arr1.size();i++)
     {
          if(arr1[i] > arr2[i])
               a++;
          else if(arr1[i] < arr2[i])
               b++;
     }
     if(a > b)
          return "A";
     else if(a < b)
          return "B";

     return "DRAW";
}

int main()
{
     int a;
     cout << "Enter Vector1 Size: ";
     cin >> a;

     vector<int> v1(a);
     for(int i=0;i<a;i++)
          cin >> v1[i];

     int b;
     cout << "Enter Vector2 Size: ";
     cin >> b;

     vector<int> v2(b);
     for(int i=0;i<b;i++)
          cin >> v2[i];

     string res = countryAtWar(v1, v2);
     cout << "    Result:- " << res << endl;

     return 0;
}

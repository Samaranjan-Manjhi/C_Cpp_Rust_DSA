/*

Ladoo problem

Bheem has one ladoo available for each day. The i-th friend wants a ladoo on day arr[i]. A ladoo can be given to at most one friend on a particular day.
If Bheem cannot give a ladoo to a friend on their requested day, he loses that friendship.
Find the maximum number of friends Bheem can have at the end.

Examples:

Input: arr[] = [3, 3, 1, 2, 4]
Output: 4 
Explanation: He will lose either his 1st or 2nd friend and therefore will be left with 4 friends.

Input: arr[] = [1, 2]
Output: 2
Explanation: He can give a ladoo to each of his friends, and will have 2 friends by the end.

Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105

*/


#include <iostream>
#include <vector>

using namespace std;

int divideLadoo(vector<int>& arr) 
{
     // code here
        
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     

     return 0;
}

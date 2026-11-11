/*

   Repeated Removal of Kth

   Given two integers n and k, consider the integers from 1 to n. In each operation, keep every kth remaining integer and remove all others. Repeat this process until the number of remaining integers becomes less than k. Return the smallest integer among the remaining integers.

Examples:

Input: n = 30, k = 3
Output: 27
Explanation: After the first operation, the remaining integers are: 3 6 9 12 15 18 21 24 27 30. Similarly, after the second operation: 9 18 27, and after the third operation: 27. Therefore, the smallest remaining integer is 27.

Input: n = 18, k = 3
Output: 9
Explanation: After the first operation, the remaining integers are: 3 6 9 12 15 18. Similarly, after the second operation: 9 18. Since the number of remaining integers is now less than k, the process stops. Therefore, the smallest remaining integer is 9.

Constraints
1 ≤ n ≤ 10^5
2 ≤ k ≤ 10

 */

#include <iostream>
#include <vector>

using namespace std;

int getCandidate(int n, int k) 
{
     // code here
     vector<int> main, temp;
     for(int i=1;i<=n;i++)
          main.push_back(i);

     //int n = main.size();
     while(main.size() >= k)
     {
          temp.clear();
          for(int i=k-1;i<main.size();i+=k)
          {
               temp.push_back(main[i]);
          }
          main = temp;
     }

     return main[0];
}

int main()
{
     int n;
     cout << "Enter n Value: ";
     cin >> n;

     int k;
     cout << "Enter k Value: ";
     cin >> k;

     int res = getCandidate(n, k);
     cout << "    Result:- " << res << endl;

     return 0;
}

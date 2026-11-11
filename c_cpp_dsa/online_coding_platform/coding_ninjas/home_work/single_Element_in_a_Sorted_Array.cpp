/*

   Single Element in a Sorted Array 

   Problem statement
   You are given a sorted array ‘arr’ of ‘n’ numbers such that every number occurred twice in the array except one, which appears only once.
   Return the number that appears once.

Example:
Input: 'arr' = [1,1,2,2,4,5,5]
Output: 4 

Explanation: 
Number 4 only appears once the array.

Note :
Exactly one number in the array 'arr' appears once.

Sample Input 1 :
5 
1 1 3 5 5 
Sample Output 1 :
3 

Explanation of Sample Input 1 :
Given array is [1, 1, 3, 5, 5]    
Here, 3 occurs once in the array. So, the answer is 3.

Sample Input 2 :
5
1 1 4 4 15
Sample Output 2 :
15

Explanation of Sample Input 2 :
The array is [1, 1, 4, 4, 15].    
Here, 15 occurs once in the array. So, the answer is 15.

Expected Time Complexity:
Try to solve this in O(log(n)).

Constraints :
1 <= n <= 10^5
0 <= arr[i] <= 10^9
Time Limit: 1 sec

 */


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int singleNonDuplicate(vector<int>& arr)
{
     // Write your code here
     unordered_map<int, int> mp;
     for(int x : arr)
          mp[x]++;

     for(auto& m : mp)
     {
          if(m.second == 1)   
               return m.first;
     }

     return -1;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int res = singleNonDuplicate(v);
     cout << "    Result:- " << res << endl;

     return 0;
}

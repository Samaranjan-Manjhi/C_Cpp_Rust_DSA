/*

Find The Repeating And Missing Number 

 Problem statement

You are given an array 'nums' consisting of first N positive integers. But from the N integers, one of the integers occurs twice in the array, and one of the integers is missing. You need to determine the repeating and the missing integer.
Example:
Let the array be [1, 2, 3, 4, 4, 5]. In the given array ‘4’ occurs twice and the number ‘6’ is missing.

Constraints:
1 <= T <= 100 
2 <= N <= 10^4
1 <= nums[i] <= N
Time Limit: 1 sec

Sample Input 1:
2
5
1 4 2 5 2
2
2 2    
Sample Output 1:
2 3
2 1
Explanation For Sample Input 1:
For the first test case we have, array: [1, 4, 2, 5, 2] and N = 5.
In the given array ‘2’ occurs twice and the number ‘3’ is missing. Hence, we output 2 and 3 for the repeating and the missing number, respectively.
For the second test case we have, array: [2, 2] and N = 2.
In the given array ‘2’ occurs twice and the number ‘1’ is missing. Hence, we output 2 and 1 for the repeating and the missing number, respectively.

Sample Input 2:
3
4
1 2 2 3
10
1 3 4 5 5 6 7 8 9 10
3
1 2 2
Sample Output 2:
2 4 
2 5 
2 3

*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> findRepeatingAndMissingNumbers(vector<int> nums)
{
     // Write your code here.
     int n = nums.size();
     vector<int> freq(n+1, 0);
     for(int x : nums)
     {
          freq[x]++;
     }

     vector<int> ans;
     int rep = -1, mis = -1;
     for(int i=1;i<=n;i++)
     {
          if(freq[i] == 0)
               mis = i;
          if(freq[i] == 2)
               rep = i;
     }
     ans.push_back(rep);
     ans.push_back(mis);
     return ans;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     vector<int> res = findRepeatingAndMissingNumbers(v);
     cout << "    Result:- ";
     if(!res.empty())
     {
          for(int x : res)
               cout << x << " ";
          cout << endl;
     }

     return 0;
}

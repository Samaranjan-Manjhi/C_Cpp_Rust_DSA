/*

   Rahul And Minimum Subarray

   Problem statement
   Rahul is a programming enthusiast. He is currently learning about arrays/lists. One day his teacher asked him to solve a very difficult problem. The problem was to find the length of the smallest subarray(subarray is a contiguous part of an array/list) in a given array/list ‘ARR’ of size ‘N’ with its sum greater than a given value. If there is no such subarray return 0.

Example: Given an ‘ARR’: [1, 2, 21, 7, 6, 12] and a number ‘X’: 23. The length of the smallest subarray is 2 as the subarray is [21, 7].

Note: Here are multiple subarrays whose sum is greater than ‘X’ such as [1, 2, 21] or [7, 6, 12] but we have to choose the minimum length subarray.

Constraints:
1 <= T <= 10^2
1 <= N <= 10^3
1 <= X <= 10^9
0 <= A[i] <= 10^9

Time Limit: 1 sec
Sample Input 1:
2
5 11
9 1 5 3 9
4 8
5 1 2 1
Sample Output 1:
2
4
Explanation For Sample Input 1:
In the first test case, the length of the minimum subarray is 2. The subarray is [3, 9] as the sum is 12 which is greater than the given value 11.

In the second test case, the length of the minimum subarray is 4. The subarray is [5,1, 2, 1] as the sum is 9 which is greater than the given value 8.
Sample Input 2:
2
7  32
27 1 2 4 15 12 8
6 10
9 1 2 11 4 1
Sample Output 2:
3
1
Explanation For Sample Input 2:
In the first test case, the length of the minimum subarray is 3. The subarray is [15,12, 8] as the sum is 35 which is greater than the given value 32.

In the second test case, the length of the minimum subarray is 1. The subarray is [11] as the sum is 11 which is greater than the given value 10.

*/


#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minSubArrayLen(vector<int>& arr, int target, int n) 
{
	int minLen = INT_MAX;
	int curr_sum = 0;
	int left = 0;

	for(int right = 0; right < n; right++) 
	{
		curr_sum += arr[right];

		while(curr_sum > target) 
		{
			int currLen = right - left + 1;
			minLen = min(currLen, minLen);

			curr_sum -= arr[left];
			left += 1;
		}
	}

	if(minLen == INT_MAX)
		return 0;

	return minLen;
}

int main() 
{
	int n, target;

	cout << "Enter the size of the array: ";
	cin >> n;

	vector<int> arr(n);
	cout << "Enter the elements of the array: ";
	for(int i = 0; i < n; i++) 
	{
		cin >> arr[i];
	}

	cout << "Enter the target value: ";
	cin >> target;

	int result = minSubArrayLen(arr, target, n);
	cout << "The length of the smallest subarray is: " << result << endl;

	return 0;
}

/*
 
 Max Sum Subarray of Size at least K

 Given an array arr[] and an integer k, find the maximum sum among all contiguous subarrays having a length greater than or equal to k.

Examples:
Input: arr[] = [1, -2, 2, -3], k = 3
Output: 1
Explanation: The sub-array of length at least 3 that produces greatest sum is [1, -2, 2]

Input: arr[] = [1, 1, 1, 1, 1, 1], k = 2
Output: 6
Explanation: The sub-array of length at least 2 that produces greatest sum is [1, 1, 1, 1, 1, 1]

Input: arr[] = [-4, -2, 1, -3], k = 2
Output: -1
Explanation: The sub-array of length at least 2 that produces greatest sum is [-2, 1]

Constraints:

1 ≤ arr.size() ≤ 10^5
-104 ≤ arr[i] ≤ 10^4
1 ≤ k ≤ arr.size()
 
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
	public:
		int maxSumWithK(vector<int>& arr, int k)
		{
			int n = arr.size();
			vector<int> maxSum(n, 0);
			int curr_sum = arr[0];
			maxSum[0] = arr[0];

			for (int i = 1; i < n; i++)
			{
				curr_sum = max(arr[i], curr_sum + arr[i]);
				maxSum[i] = curr_sum;
			}

			int exactKSum = 0;
			for (int i = 0; i < k; i++)
			{
				exactKSum += arr[i];
			}

			int ans = exactKSum;

			for (int i = k; i < n; i++)
			{
				exactKSum = exactKSum + arr[i] - arr[i - k];
				ans = max(ans, exactKSum);
				ans = max(ans, exactKSum + maxSum[i - k]);
			}

			return ans;
		}
};

int main() 
{
	int n, k;

	cout << "Enter the number of elements in the array: ";
	cin >> n;

	vector<int> arr(n);
	cout << "Enter " << n << " elements: ";
	for (int i = 0; i < n; i++) 
	{
		cin >> arr[i];
	}

	cout << "Enter the value of k: ";
	cin >> k;

	if (k > n || k <= 0) 
	{
		cout << "Invalid value of k! It must be between 1 and " << n << "." << endl;
		return 1;
	}

	Solution ob;
	int result = ob.maxSumWithK(arr, k);

	cout << "Maximum sum with at least " << k << " elements is: " << result << endl;

	return 0;
}

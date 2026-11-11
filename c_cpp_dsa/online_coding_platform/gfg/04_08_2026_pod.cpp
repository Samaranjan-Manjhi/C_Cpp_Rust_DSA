/*
 
 Pairs with Less Than K Diff

 Given an array arr[] of positive integers and an integer k, find the total number of pairs of elements that have an absolute difference strictly less than k.
Note:  Pair (i, j) is considered the same as (j, i).

Examples:

Input : arr[] = [1, 10, 4, 2], k = 3
Output : 2
Explanation: We have an array arr[] = [1, 10, 4, 2] and k = 3 We can make only two pairs with a difference of less than 3. (1, 2) and (4, 2). So, the answer is 2.

Input : arr[] = [2, 3, 4], k = 5
Output : 3
Explanation:  For the given array arr[] = [2, 3, 4] and k = 5, there are 3 valid pairs where the absolute difference between the pair's elements is less than 5. These pairs are (2, 3), (2, 4), and (3, 4). Hence, the output is 3.

Constraints:
1 ≤ arr.size() ≤ 10^5
0 ≤ k ≤ 10^5
1 ≤ arr[i] ≤ 10^5
 
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countPairs(vector<int>& arr, int k)
{
	// code here
	/* // TLE
	   int m = arr.size();
	   int cnt = 0;
	   for (int i = 0; i<m; i++)
	   {
	   for (int j = i + 1; j<m; j++)
	   {
	   if (abs(arr[i] - arr[j]) < k)
	   cnt++;
	   }
	   }

	   return cnt;
	   */

	int m = arr.size();
	int cnt = 0;

	sort(arr.begin(), arr.end());

	int j = 0;
	for (int i = 0; i < m; i++)
	{
		while (j < m && arr[j] - arr[i] < k)
		{
			j++;
		}
		if (j > i + 1)
		{
			cnt += (j - 1 - i);
		}
	}

	return cnt;
}

int main() 
{
	int n;
	cout << "Enter the number of elements: ";
	if (!(cin >> n) || n <= 0) {
		cout << "Invalid input size." << endl;
		return 0;
	}

	vector<int> nums(n);
	cout << "Enter the elements of the array/vector:\n";
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	int k;
	cout << " Enter k value: ";
	cin >> k;

	int res = countPairs(nums, k);
	cout << "    Result:-  " << res << endl;

	return 0;
}

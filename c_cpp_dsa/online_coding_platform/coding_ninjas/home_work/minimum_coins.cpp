/*

Minimum coins

 Problem statement

You are given a permutation 'A' of length 'N'. You can apply the following operation any number of times which costs 1 coin for each operation.

Select any subarray of length at most 'N' - 1 and rearrange the elements in any order.

Return the minimum number of coins required to sort the permutation in increasing order.

A permutation is an array in which each element from 1 to 'N' occurs exactly once.
For Example:-

Let 'N' = 5, 'A' = [1, 2, 3, 5, 4].
We can apply the operation to the subarray from index 4 to 5 (1-based indexing).
So our answer is 1.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:-

1 <= 'T' <= 10
3 <= 'N' <= 10^5

The Sum of 'N' overall test cases does not exceed 10^5.
Time Limit: 1 sec

Sample Input 1:-

2
4
1 3 2 4
3
1 2 3

Sample Output 1:-

1
0

Explanation of sample input 1:-

First test case:-
We can apply the operation to the subarray from index 2 to 3 (1-based indexing).
So our answer is 1.

Second test case:-
The array is already sorted.
So our answer is 0.

Sample Input 2:-

2
5
5 4 3 1 2
5
3 2 1 4 5

Sample Output 2:-

2
1

*/


#include <iostream>
#include <vector>

using namespace std;

int minimumCoins(vector<int> a) {
	// Write your code here

	return 0;
}

int main() {
	int n;
	cin >> n;

	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int result = minimumCoins(a);

	cout << result;

	return 0;
}

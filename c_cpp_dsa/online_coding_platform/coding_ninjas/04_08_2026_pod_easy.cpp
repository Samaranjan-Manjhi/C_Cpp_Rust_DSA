/*
 
 Count Of Divisible Pairs

 Problem statement
You are given two integers ‘N’ and ‘M’. A pair (x, y) is a divisible pair if it satisfies the following conditions:
a) 1 <= x <= ‘N’
b) 1 <= y <= ‘M’
c) x + y is divisible by 5.
Your task is to return the count of all divisible pairs that can be formed from given ‘N’ and ‘M’.

Example :
If N = 3 and M = 5, then { x = 1, y = 4 },  { x = 2, y = 3 },  { x = 3, y = 2 } are the pairs that satisfy the given conditions.

Constraints :
1 <= T <= 10
1 <= N, M <= 10^9
Time limit: 1 sec

Sample Input 1 :
2
1 5
2 3
Sample Output 1 :
1
1
Explanation Of Sample Output 1 :
For test case 1 :
Only (1,4) satisfy the given condition.
For test case 2 :
Only (2,3) satisfy the given conditions.

Sample Input 2 :
2
1 3
6 12
Sample Output 2 :
0
14
 
 */



#include <iostream>

using namespace std;

int countOfDivisiblePairs(int n, int m)
{
	// Write your code here
	int cnt = 0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if((i+j)%5 == 0)
				cnt++;
		}
	}

	return cnt;
}

int main()
{
	int n, m;
	cout << "Enter n & m Value: ";
	cin >> n >> m;

	int res = countOfDivisiblePairs(n, m);
	cout << "     Result:-    " << res << endl;

	return 0;
}

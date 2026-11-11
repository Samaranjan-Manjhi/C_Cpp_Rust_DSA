/*
 
 3345. Smallest Divisible Digit Product I
 
 You are given two integers n and t. Return the smallest number greater than or equal to n such that the product of its digits is divisible by t.

Example 1:
Input: n = 10, t = 2
Output: 10
Explanation:
The digit product of 10 is 0, which is divisible by 2, making it the smallest number greater than or equal to 10 that satisfies the condition.

Example 2:
Input: n = 15, t = 3
Output: 16
Explanation:
The digit product of 16 is 6, which is divisible by 3, making it the smallest number greater than or equal to 15 that satisfies the condition.

Constraints:
1 <= n <= 100
1 <= t <= 10
 
 */


#include <iostream>

using namespace std;

int getProd(int n)
{
	int res = 1;
	while(n > 0)
	{
		res *= n%10;
		n /= 10;
	}

	return res;
}

int smallestNumber(int n, int t)
{
	bool isDone = true;
	int res = 0;
	while(isDone)
	{
		int temp = getProd(n);
		if(temp%t == 0)
		{
			res = n;
			isDone = false;
		}
		n++;
	}

	return res;
}

int main()
{
	int n, t;
	cout << "Enter Value of n & t: ";
	cin >> n >> t;

	int res = smallestNumber(n, t);
	cout << "    Result:-   " << res << endl;

	return 0;
}

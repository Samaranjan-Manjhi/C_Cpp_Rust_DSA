/*
 
 Count Of Plates

 Problem statement
You are given 3 Integers ‘n’, ‘R’ & ‘r’ where ‘n’ is the number of plates,

‘R’ is the radius of the table, and ‘r’ is the radius of the ‘n’ plates. The task is to find out whether the given table has enough space to accommodate the given number of plates of radius ‘r’. Consider the table and plates to be round and no plate can be placed above any other.

Each plate must be completely inside the table and must touch the edge of the table. Of course, the plates must not intersect, but they can touch each other.

You have to return true if the table can accommodate the given number of plates else return false.

Constraints :
1 <= T <= 10^5
1 <= n <= 10^6
1 <= r <= 10^9
1 <= R <= 10^9
1 <= r <= R
Time Limit: 1 sec

Sample Input 1
3
4 10 4
5 10 4
1 10 10
Sample Output 1
Yes
No
Yes
Explanation Of Sample Input 1 :
Test Case 1: n = 4 , R = 10 , r = 4
One of the possible arrangements can be :

Test case 2 : n = 5, R = 10, r = 4
From the above figure we can see that we can place no more plates with “r” = 4.
So, we print No.

Test case 3 : n = 1, R = 10, r = 10
Since R=r , and n=1 so we can place the only plate over the table such that it overlaps
with the table.
So, we print Yes.

Sample Input 2
2
2 10 5
10 10 10
Sample Output 2
Yes
No
 
 */



#include <iostream>
#include <cmath>

using namespace std;

bool countPlatesOnTable(int n, int R, int r)
{
	// Write your code here
	if(n == 1 && R >= r)
		return true;

	if(R < r)
		return false;

	double res = (R - r) * sin(acos(-1.0)/n);
	if(res >= r - 1e-9)
		return true;

	return false;
}

int main() 
{
	int n, R, r;

	cout << "Enter number of plates (n): ";
	cin >> n;

	cout << "Enter radius of the table (R): ";
	cin >> R;

	cout << "Enter radius of the plates (r): ";
	cin >> r;

	bool canFit = countPlatesOnTable(n, R, r);

	if(canFit) 
	{
		cout << "True: The table can accommodate the plates." << endl;
	} 
	else 
	{
		cout << "False: The table cannot accommodate the plates." << endl;
	}

	return 0;
}

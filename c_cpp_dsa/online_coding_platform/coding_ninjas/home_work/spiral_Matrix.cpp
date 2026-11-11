/*

Spiral Matrix 

 Problem statement

You are given a 2-D array 'MATRIX' of dimensions N x M, of integers. You need to return the spiral path of the matrix.

Constraints:
1 <= T <= 5
1 <= N  <= 10 ^ 2
1 <= M <= 10 ^ 2
-10 ^ 9 <= MATRIX[ i ][ j ] <= 10 ^ 9
Time Limit: 1sec.

Sample Input 1 :
2
4 4
1 2 3 4 
5 6 7 8 
9 10 11 12 
13 14 15 16
3 6
1 2 3 4 5 6 
7 8 9 10 11 12 
13 14 15 16 17 18
Sample Output 1 :
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
1 2 3 4 5 6 12 18 17 16 15 14 13 7 8 9 10 11

Explanation of the Sample Input 1 :

The spiral path for the test case 2 is as shown below:

Sample Input 2 :
2
1 1
4
1 5
1 2 3 4 5
Sample Output 2 :
4
1 2 3 4 5

Explanation of the Sample Input 2:

In the first test case, there is only one element in the matrix, so the spiral path is only that element.
In the second test case, there is only one row or 1-D matrix, so the spiral path is only the single traversal of the matrix.

*/


#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralPathMatrix(vector<vector<int>> matrix, int m, int n) 
{
	// Write your code here.
	vector<int> res;
	if (m == 0 || n == 0) 
		return res;
	int left = 0, right = n-1;
	int top = 0, bottom = m-1;

	while(left <= right && top <= bottom)
	{
		for(int i=left;i<=right;i++)
		{
			res.emplace_back(matrix[top][i]);
		}
		top++;

		for(int i=top;i<=bottom;i++)
		{
			res.emplace_back(matrix[i][right]);
		}
		right--;

		if(top <= bottom)
		{
			for(int i=right;i>=left;i--)
			{
				res.emplace_back(matrix[bottom][i]);
			}
			bottom--;
		}

		if(left <= right)
		{
			for(int i=bottom;i>=top;i--)
			{
				res.emplace_back(matrix[i][left]);
			}
			left++;
		}
	}

	return res;
}

int main()
{
	int m, n;
	cout << "Enter Matrix Size (m*n): ";
	cin >> m >> n;

	vector<vector<int>> v(m, vector<int>(n));
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin >> v[i][j];
		}
	}

	vector<int> res = spiralPathMatrix(v, m, n);
	for(int i=0;i<res.size();i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;

	return 0;
}

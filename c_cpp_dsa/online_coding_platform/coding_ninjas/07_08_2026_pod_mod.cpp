/*
 
 Matrix Multiplication
 
 Problem statement
Ninja has been given two sparse matrices ‘MAT1’ and ‘MAT2’ of integers having size ‘N’ x ‘M’ and ‘M’ x ‘P’, respectively.

A sparse matrix is a matrix that contains very few non-zero elements.

Ninja has to find the matrix formed by the multiplication of ‘MAT1’ and ‘MAT2’. As Ninja is busy with some other tasks so he needs your help. Can you help Ninja to find the matrix formed by the multiplication of ‘MAT1’ and ‘MAT2’?

Note: The number of columns in ‘MAT1’ i.e ‘M’ is equal to the number of rows in ‘MAT2’ i.e ‘M’. It means we can always multiply ‘MAT1’ with ‘MAT2’.

For example:
For the ‘MAT1’ and ‘MAT2’ given below, ‘MAT3’ is the matrix formed by multiplying ‘MAT1’ and ‘MAT2’.
1. MAT3[0][0] = MAT1[0][0] * MAT2[0][0] + MAT1[0][1] * MAT2[1][0]  ie. 2 * 1 + 1 * 4 = 6
2. MAT3[1][0] = MAT1[1][0] * MAT2[1][0] + MAT1[1][1] * MAT2[1][0] ie. 0 * 6 + 0 * 4 = 0

Constraints:
1 <= ‘T’ <= 100
1 <= ‘N’, ‘M’ and ‘P’ <= 100
-10^5 <= ‘MAT1[i][j]’ and ‘MAT2[i][j]’ <= 10^5
Time limit: 1 sec

Sample Input 1:
1
2 1 1 2
2
0
1 2
Sample Output 1:
2 4
0 0
Explanation for Sample Output 1:
For sample test case 1:
1. MAT3[0][0] = MAT1[0][0] * MAT2[0][0] ie. 2 * 1 = 2
2. MAT3[0][1] = MAT1[0][0] * MAT2[0][1] ie. 2 * 2 = 4
3. MAT3[1][0] = MAT1[0][1] * MAT2[0][0] ie. 0 * 1 = 0
4. MAT3[1][1] = MAT1[1][1] * MAT2[0][1] ie. 0 * 2 = 0

Sample Input 2:
2
1 1 1 2
3
1 0
1 1 1 1
-1
7
Sample Output 2:
3 0
-7
Explanation for Sample Output 1:
For sample test case 1:
1. MAT3[0][0] = MAT1[0][0] * MAT2[0][0] ie. 3 * 1 = 3
2. MAT3[0][1] = MAT1[0][0] * MAT2[0][1] ie. 3 * 0 = 0

For sample test case 2:
1. MAT3[0][0] = MAT1[0][0] * MAT2[0][0] ie. -1 * 7 = -7
 
 */



#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> multiplyMatrices(vector<vector<int>> &mat1, vector<vector<int>> &mat2) 
{
	int n = mat1.size();
	int m = mat1[0].size();
	int p = mat2[0].size();
	vector<vector<int>> res(n, vector<int>(p, 0));

	for(int i = 0; i < n; i++) 
	{
		for(int k = 0; k < m; k++) 
		{
			if(mat1[i][k] != 0) 
			{
				for(int j = 0; j < p; j++) 
				{
					res[i][j] += mat1[i][k] * mat2[k][j];
				}
			}
		}
	}

	return res;
}

int main() 
{
	// Fast I/O
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int r1, c1;
	cout << "Enter rows and columns for Matrix 1: ";
	cin >> r1 >> c1;

	vector<vector<int>> mat1(r1, vector<int>(c1));
	cout << "Enter elements of Matrix 1:\n";
	for(int i = 0; i < r1; i++) 
	{
		for(int j = 0; j < c1; j++) 
		{
			cin >> mat1[i][j];
		}
	}

	int r2, c2;
	cout << "Enter rows and columns for Matrix 2: ";
	cin >> r2 >> c2;

	if(c1 != r2) 
	{
		cout << "Matrix multiplication not possible! Columns of Matrix 1 must equal rows of Matrix 2.\n";
		return 0;
	}

	vector<vector<int>> mat2(r2, vector<int>(c2));
	cout << "Enter elements of Matrix 2:\n";
	for(int i = 0; i < r2; i++) 
	{
		for(int j = 0; j < c2; j++) 
		{
			cin >> mat2[i][j];
		}
	}

	vector<vector<int>> result = multiplyMatrices(mat1, mat2);

	cout << "Resultant Matrix:\n";
	for(int i = 0; i < result.size(); i++) 
	{
		for(int j = 0; j < result[0].size(); j++) 
		{
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}

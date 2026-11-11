#include <iostream>
#include <vector>

using namespace std;

int digSum(const vector<vector<int>>& mat)
{
	int n = mat.size();
	int sum = 0;
	for(int i=0;i<n;i++)
	{
		sum += mat[i][i];
		if((n-i-1) != i)
			sum += mat[i][n-i-1];
	}

	return sum;
}

int main()
{
	//vector<vector<int>> v = {
	//			{1, 2, 3}, 
	//			{4, 5, 6}, 
	//			{7, 8, 9}};
	vector<vector<int>> v = {
				{1, 2, 3, 4}, 
				{5, 6, 7, 8}, 
				{9, 0, 1, 2}, 
				{3, 4, 5, 6}};

	int res = digSum(v);
	cout << "Res:- " << res << endl;

	return 0;
}

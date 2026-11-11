#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

pair<int, int> twoSumOptimal(const vector<int>& vec, int tar) 
{
	unordered_map<int, int> seen; 

	for (int i = 0; i < vec.size(); i++) 
	{
		int complement = tar - vec[i];

		if (seen.find(complement) != seen.end()) 
		{
			return {seen[complement], i + 1};
		}

		seen[vec[i]] = i + 1;
	}

	return {-1, -1};
}

pair<int, int> twoSumBruteForce(const vector<int>& vec, int tar) 
{
	int n = vec.size();

	for (int i = 0; i < n; i++) 
	{
		for (int j = i + 1; j < n; j++) 
		{
			if (vec[i] + vec[j] == tar) 
			{
				return {i + 1, j + 1}; 
			}
		}
	}

	return {-1, -1};
}

int main() 
{
	vector<int> v{1, 2, 8, 11, 15, 3, 4, 7, 9};
	int tar = 13;

	pair<int, int> res = twoSumOptimal(v, tar);
	cout << res.first << "  " << res.second << endl; // Output: 2  4 (values 2 and 11) or 7  9 (values 4 and 9)

	return 0;
}

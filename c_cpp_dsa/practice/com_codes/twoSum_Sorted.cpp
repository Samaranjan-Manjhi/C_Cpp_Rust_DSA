#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> twoSumSorted(const vector<int>& vec, int tar) 
{
	vector<pair<int, int>> res;
	int left = 0;
	int right = vec.size() - 1;

	while (left < right) 
	{
		int sum = vec[left] + vec[right];

		if (sum == tar) 
		{
			res.push_back({left + 1, right + 1}); 

			while(left < right && vec[left] == vec[left+1])
				left++;
			while(left < right && vec[right] == vec[right-1])
				right--;

			left++;
			right--;
		} 
		else if (sum < tar) 
		{
			left++;  
		} 
		else 
		{
			right--; 
		}
	}

	return res; 
}

int main() {
	vector<int> v{1, 2, 3, 4, 7, 8, 9, 11, 15};
	int tar = 13;

	vector<pair<int, int>> result = twoSumSorted(v, tar);
	for(const auto& res : result)
		cout << res.first << "  " << res.second << endl; // Output: 2  8 (values at indices 2 and 8 are 2 and 11)

	return 0;
}

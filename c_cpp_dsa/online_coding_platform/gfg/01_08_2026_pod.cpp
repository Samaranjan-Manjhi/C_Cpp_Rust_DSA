/*

   Max After m Range Increments

   Given three arrays a[], b[], and k[], representing m range increment operations on an array arr[] of size n, where all elements of arr[] are initially 0.

   Increment(a[i], b[i], k[i]) adds k[i] to each element arr[j] such that a[i] ≤ j ≤ b[i] (mainly indexes in range from a[i] to b[i])
   After performing all the given operations, find the maximum value present in the array.

Examples:

Input: n = 5, a[] = [0, 1, 2], b[] = [1, 4, 3], k[] = [100, 100, 100]
Output: 200
Explanation: Initially, arr = [0, 0, 0, 0, 0]
After the first operation: arr = [100, 100, 0, 0, 0]
After the second operation: arr = [100, 200, 100, 100, 100]
After the third operation: arr = [100, 200, 200, 200, 100]
The maximum element after all operations is 200.

Input: n = 4, a[] = [1, 0, 3], b[] = [2, 0, 3], k[] = [603, 286, 882]
Output: 882
Explanation: Initially, arr = [0, 0, 0, 0]
After the first operation: arr = [0, 603, 603, 0]
After the second operation: arr = [286, 603, 603, 0]
After the third operation: arr = [286, 603, 603, 882]
The maximum element after all operations is 882.

Constraints:
1 ≤  n ≤ 10^6
1 ≤  a.size() = b.size() = k.size() = m  ≤ 10^6
0 ≤  ai  ≤  bi  ≤ n-1
0 ≤  ki  ≤ 10^6

*/


#include <iostream>
#include <vector>

using namespace std;

/* // TLE
   int findMax(int n, vector<int>& a, vector<int>& b, vector<int>& k) 
   {
// code here
vector<int> res(n, 0);
for(int i=0;i<a.size();i++)
{
int left = a[i];
int right = b[i];
int val = k[i];

for(int j=left;j<=right;j++)
{
res[j] += val;
}
}

int maxi = 0;
for(int x : res)
{
if(maxi < x)
maxi = x;
}


return maxi;
}
*/

int findMax(int n, vector<int>& a, vector<int>& b, vector<int>& k)
{
	// code here
	vector<int> res(n+2, 0);
	for(int i=0;i<a.size();i++)
	{
		int left = a[i];
		int right = b[i];
		int val = k[i];

		//for(int j=left;j<=right;j++)
		//{
		//    res[j] += val;
		//}

		res[left] += val;
		res[right+1] -= val;
	}

	int maxi = 0;
	int curr = 0;
	for(int i=0;i<n;i++)
	{
		curr += res[i];
		if(curr > maxi)
			maxi = curr;
	}

	return maxi;
}

int main()
{
	int n;
	cout << "Enter Initial Vector Size: ";
	cin >> n;

	int s;
	cout << "Enter Vectors Size: ";
	cin >> s;
	vector<int> a(s);
	vector<int> b(s);
	vector<int> k(s);

	cout << "Enter Left Range Value: ";
	for(int i=0;i<s;i++)
		cin >> a[i];

	cout << "Enter Right Range Value: ";
	for(int i=0;i<s;i++)
		cin >> b[i];

	cout << "Enter Incremental Value: ";
	for(int i=0;i<s;i++)
		cin >> k[i];

	int res = findMax(n, a, b, k);
	cout << "    Result:-   " << res << endl;

	return 0;
}

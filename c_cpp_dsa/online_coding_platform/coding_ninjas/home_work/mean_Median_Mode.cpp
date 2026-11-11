/*

Mean Median Mode 

 Problem statement

You are given an array 'ARR' of 'N' integers and you have to calculate 3 things for the given array:-

1. Mean - function mean(): This function should calculate the mean of the array.

2. Median - function median(): This function should calculate the median of the array.

3. Mode - function mode(): This function should calculate the mode of the array.
Note :

It can be shown that Mean and Median is in the form of P/Q, where P and Q are coprime integers and Q != 0. You need to return P and Q.

For Mode, if the highest frequency of more than one element is the same, return the smallest element.

For Example, for the given array {1, 1, 2, 2, 3, 3, 4}, the mode will be 1 as it is the smallest of all the possible modes i.e 1, 2 and 3.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :

1 <= T <= 5
1 <= N <= 10^5 
1 <= ARR[i] <= 10^6 

Where 'ARR[i]' denotes the 'ith' element of the array.

Time limit: 1 sec

Sample input 1 :

1
4  
3 3 1 4 

Sample output 1 :

11 4
3 1
3

Explanation of sample input 1 :

To find the mean, we will take the sum of all the elements and then divide them by the total number of elements. Thus, (3 + 3 + 1 + 4)/4 = 11 / 4. Where P = 11 and Q = 4 and P, Q are coprime. 

To find the median, we will sort the array in ascending order and find the average of n/2 and (n/2 + 1)th number if N is even and (n+1)/2th number if N is odd. Thus, (3+3)/2 = 6 / 2. Thus P = 3 and Q = 1 and P, Q are coprimes.

To find the mode, we will find the element with the highest frequency which is 3 with a frequency of two and thus, the Mode is 3.  

Sample input 2 :

1
5
7 6 5 5 3

Sample output 2 :

26 5 
5 1 
5 

*/



#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Return a vector RES where RES[0] denotes P and RES[1] denotes Q.
vector<long long> mean(vector<int> &arr)
{
	// Write your code here.

	vector<long long> res(2);

	return res;
}

// Return a vector RES where RES[0] denotes P and RES[1] denotes Q.
vector<int> median(vector<int> &arr)
{
	// Write your code here.

	vector<int> res(2);

	return res;
}

// Return Mode of the array.
int mode(vector<int> &arr)
{
	// Write your code here.

	return 0;
}

int main() {
	int n;
	cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector<long long> meanResult = mean(arr);
	vector<int> medianResult = median(arr);
	int modeResult = mode(arr);

	cout << meanResult[0] << " " << meanResult[1] << endl;
	cout << medianResult[0] << " " << medianResult[1] << endl;
	cout << modeResult << endl;

	return 0;
}

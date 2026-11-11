/*
   Problem statement

   You are given an array/list ‘ARR’ of size ‘N’. ‘ARR' is binary i.e. it contains only 0s and 1s (ARR[i] = {0, 1}). Your task is to find out the minimum number of swaps required to group all 1s together.

Note: If ‘ARR’ contains only 0’s then print -1.

Example:

Let ‘ARR’ = [ 0, 1, 0, 1]. We can group all 1s together in the following ways: ‘ARR’ =[0, 0, 1, 1] or ‘ARR’ = [0, 1, 1, 0]. 

In this example, we need only 1 swap to group all 1’s together which is the minimum possible. 

Constraints:

1 <= ‘T’ <= 100
2 <= ‘N’ <= 5000
0 <= ‘ARR[i]’ <= 1

Where ‘ARR[i]’ represents the elements of array/list ‘ARR’. 

Time Limit: 1 sec

Sample Input 1:

2
5
1 0 1 0 1
6
1 1 1 1 1 1

Sample Output 1:

1
0

Explanation for Sample Output 1:

In test case 1, swap ‘ARR[1]’ and ‘ARR[4]’ (0-based indexing). Then ‘ARR’ = [1, 1, 1, 0, 0]. So, the minimum swaps to group all 1s together is 1.

In test case 2, all 1s are already together in 'ARR'. So, we don’t need any swaps. Hence, the minimum swaps to group all 1s together is 0.

Sample Input 2:

2
4 
0 0 0 0
6
1 1 0 0 1 1

Sample Output 2:

-1
2

Explanation for Sample Output 2:

In test case 1, the number of 1s in 'ARR' is 0. So we return -1.

In test case 2, first, we swap ‘ARR[2]’ and ‘ARR[4]’ (0-based indexing). Now, ‘ARR’ = [1, 1, 1, 0, 0, 1].
Then, swap ‘ARR[3]’ and ‘ARR[5]’. Now, ‘ARR’ = [1, 1, 1, 1, 0, 0]. So, the minimum swaps to group all 1s together is 2.

 */

#include <iostream>
#include <vector>
using namespace std;

//int groupAllOneTogether(vector<int> &arr, int n) 
int groupAllOneTogether(vector<int> &arr) 
{
     // Write your code here.
     int n = arr.size();
     int sum = 0;
     for(int i=0;i<n;i++)
     {
          sum += arr[i];
     }
     //cout << "Sum: " << sum << endl;
     if(sum == 0)     
          return -1;

     if(sum == n)    
          return 0;
     /*
        int l = 0, r = n-1, cnt = 0;
        while(l<=r)
        {
     //cout << "arr[l] : " << arr[l] << "        arr[r] : " << arr[r] << endl;
     if(arr[l] == 1)
     l++;
     if(arr[r] == 1)
     r--;
     if(arr[l] == 0 && arr[r] == 1)
     {
     if(arr[r] == 0)
     {
     r--;
     }
     else
     {
     swap(arr[l], arr[r]);
     cnt++;
     }
     }
     }
      */

     int curr = 0;
     for(int i=0;i<sum;i++)
     {
          curr += arr[i];
     }
     int maxi1 = curr;

     for(int i=sum;i<n;i++)
     {
          curr += arr[i];
          curr -= arr[i-sum];
          maxi1 = max(maxi1, curr);
     }
     return sum-maxi1;
}

int main()
{
     //vector<int> v{1, 0, 1, 0, 1}; // 1
     //vector<int> v{1, 1, 1, 1, 1, 1}; // 0
     //vector<int> v{0, 0, 0, 0, 0}; // -1
     //vector<int> v{1, 1, 0, 0, 1, 1}; // 2
     vector<int> v{1, 0, 1, 0, 1, 1}; // 1
     cout << "Result:- " << groupAllOneTogether(v) << endl;
     return 0;
}

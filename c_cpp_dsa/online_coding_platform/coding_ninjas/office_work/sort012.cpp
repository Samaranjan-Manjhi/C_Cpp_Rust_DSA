/*

 Problem statement

You have been given an integer array/list(ARR) of size 'N'. It only contains 0s, 1s and 2s. Write a solution to sort this array/list.

Note :
Try to solve the problem in 'Single Scan'. ' Single Scan' refers to iterating over the array/list just once or to put it in other words, you will be visiting each element in the array/list just once.

Constraints :
1 <= T <= 10
1 <= N <= (5 * (10 ^ 5))
0 <= ARR[i] <= 2

Where 'N' is the size of the given array/list.
And, ARR[i] denotes the i-th element in the array/list.
Time Limit: 1sec 

Sample Input 1 :
2
6
0 1 2 2 1 0
7
0 1 2 1 2 1 2
Sample Output 1 :
0 0 1 1 2 2
0 1 1 1 2 2 2

Sample Input 2 :
2
7
2 2 2 1 1 1 0
6
2 1 2 0 1 0
Sample Output 2 :
0 1 1 1 2 2 2
0 0 1 1 2 2

*/

#include <iostream>
#include <vector>

using namespace std;

void sort012(vector<int>& arr, int n)
{
     //   Write your code here
     /*
        int zero = 0, one = 0, two = 0;
        for(int i=0;i<n;i++)
        {
        int x = arr[i];
        if(x == 0)
        zero++;
        else if(x == 1)
        one++;
        else
        two++;
        }

        int i = 0;
        while(zero--)
        arr[i++] = 0;
        while(one--)
        arr[i++] = 1;
        while(two--)
        arr[i++] = 2;
      */

     int low = 0, mid = 0, high = n-1;
     while(mid <= high)
     {
          if(arr[mid] == 0)
          {
               swap(arr[low], arr[mid]);
               low++;
               mid++;
          }
          else if(arr[mid] == 1)
          {
               mid++;
          }
          else
          {
               swap(arr[mid], arr[high]);
               high--;
          }
     }
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     cout << "Elements Before Sorting:- ";
     for(int x : v)
          cout << x << " ";
     cout << endl;

     sort012(v, n);

     cout << "Elements After Sorting:- ";
     for(int x : v)
          cout << x << " ";
     cout << endl;

     return 0;
}

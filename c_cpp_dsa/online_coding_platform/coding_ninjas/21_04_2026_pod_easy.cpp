/*
   Problem statement

   You are given an array ‘A’ of length ‘N’ consisting only of positive integers. Your task is to make the given array a palindrome by using a minimum number of operations. In one operation, you can select two adjacent indexes and merge them by adding their values. After every operation, the length of the array decreases by one.

Note: An array of length ‘1’ is a palindrome.

For example:

Let’s say the array ‘A’ = [1, 2, 3, 4, 5], then after merging indexes 2 and 3, the array ‘A’ will look like [1, 5, 4, 5].

Constraints -

1 <= ‘T’ <= 5
1 <= ‘N’ <= 10^5 
1 <= A[i] <= 10^9, for 1 <= i <= ‘N’
Note- Sum of ‘N’ over all test cases does not exceed 10^5.

Time Limit: 1 sec

Sample Input-1
2
3
1 2 1
5
1 2 3 4 1

Sample Output-1
0
2

Explanation for Sample Input 1:

For test case 1:
The given array is already a palindrome. Hence the answer is 0.
For test case 2:
We select indexes 3 and 4 to merge. The array will look like [1, 2, 7, 1].
We select indexes 2 and 3 to merge. The array will look like [1, 9, 1].
Now the array is a palindrome. Hence the answer will be 2.

Sample Input -2
2
1
8
3
1 3 3

Sample Output -2
0
2

 */

#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(vector<int> v)
{
     int l = 0, r = v.size()-1;
     while(l <= r)
     {
          if(v[l] != v[r])
               return false;
          l++;r--;
     }
     return true;
}

void print(vector<int>v)
{
     for(int i=0;i<v.size();i++)
     {
          cout << v[i] << " ";
     }
     cout << endl;
}

int makePalindrome(vector<int> A)
{
     int n = A.size();
     int cnt = 0, l = 0, r = n - 1;
     long long left = A[l], right = A[r];
     while(l < r)
     {
          if(left == right)
          {
               l++;
               r--;
               if(l < r)
               {
                    left = A[l];
                    right = A[r];
               }
          }
          else if(left < right)
          {
               l++;
               left += A[l];
               cnt++;
          }
          else
          {
               r--;
               right += A[r];
               cnt++;
          }
     }
     return cnt;     
}

int main()
{
     int n, val;
     cout << "Enter the Size of the Vector: ";
     cin >> n;
     vector<int> v;
     for(int i=0;i<n;i++)
     {
          cin >> val;
          v.push_back(val);
     }
     cout << "Result:- " << makePalindrome(v) << endl;
     return 0;
}

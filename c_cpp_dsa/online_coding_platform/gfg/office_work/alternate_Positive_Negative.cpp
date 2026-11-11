/*

   Alternate Positive Negative

   Given an unsorted array arr containing both positive and negative numbers. Your task is to rearrange the array and convert it into an array of alternate positive and negative numbers without changing the relative order.

Note:

Resulting array should start with a positive integer (0 will also be considered as a positive integer).
If any of the positive or negative integers are exhausted, then add the remaining integers in the answer as it is by maintaining the relative order.

Examples:

Input: arr[] = [9, 4, -2, -1, 5, 0, -5, -3, 2]
Output: [9, -2, 4, -1, 5, -5, 0, -3, 2]
Explanation: The positive numbers are [9, 4, 5, 0, 2] and the negative integers are [-2, -1, -5, -3]. Since, we need to start with the positive integer first and then negative integer and so on (by maintaining the relative order as well), hence we will take 9 from the positive set of elements and then -2 after that 4 and then -1 and so on.

Input: arr[] = [-5, -2, 5, 2, 4, 7, 1, 8, 0, -8]
Output: [5, -5, 2, -2, 4, -8, 7, 1, 8, 0]
Explanation : The positive numbers are [5, 2, 4, 7, 1, 8, 0] and the negative integers are [-5,-2,-8]. According to the given conditions we will start from the positive integer 5 and then -5 and so on. After reaching -8 there are no negative elements left, so according to the given rule, we will add the remaining elements (in this case positive elements are remaining) as it in by maintaining the relative order.

Input: arr[] = [9, 5, -2, -1, 5, 0, -5, -3, 2]
Output: [9, -2, 5, -1, 5, -5, 0, -3, 2]
Explanation: The positive numbers are [9, 5, 5, 0, 2] and the negative integers are [-2, -1, -5, -3]. Since, we need to start with the positive integer first and then negative integer and so on (by maintaining the relative order as well), hence we will take 9 from the positive set of elements and then -2 after that 5 and then -1 and so on.

Constraints:
1 ≤ arr.size() ≤ 10^6
-106 ≤ arr[i] ≤ 10^6

 */


#include <iostream>
#include <vector>

using namespace std;

void rearrange(vector<int> &arr) 
{
     // code here
     vector<int> pos, neg;
     for(int x : arr)
     {
          if(x < 0)
               neg.push_back(x);
          else
               pos.push_back(x);
     }

     vector<int> res;
     int mini = min(neg.size(), pos.size());
     for(int i=0;i<mini;i++)
     {
          res.push_back(pos[i]);
          res.push_back(neg[i]);
     }

     if(neg.size() < pos.size())
     {
          for(int i=mini;i<pos.size();i++)
               res.push_back(pos[i]);
     }
     else
     {
          for(int i=mini;i<neg.size();i++)
               res.push_back(neg[i]);
     }

     arr = res;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     cout << "   Result Before rearrange Operation:- " ;
     if(!v.empty())
     {
          for(int x : v)
               cout << x << " ";
          cout << endl;
     }
     rearrange(v);
     cout << "   Result After rearrange Operation:- " ;
     if(!v.empty())
     {
          for(int x : v)
               cout << x << " ";
          cout << endl;
     }

     return 0;
}

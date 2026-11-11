/*

 Next Greater Element 

 Problem statement

You are given an array 'a' of size 'n'.
Print the Next Greater Element(NGE) for every element.
The Next Greater Element for an element 'x' is the first element on the right side of 'x' in the array, which is greater than 'x'.
If no greater elements exist to the right of 'x', consider the next greater element as -1.

For example:
Input: 'a' = [7, 12, 1, 20]
Output: NGE = [12, 20, 20, -1]

Explanation: For the given array,
- The next greater element for 7 is 12.
- The next greater element for 12 is 20. 
- The next greater element for 1 is 20. 
- There is no greater element for 20 on the right side. So we consider NGE as -1.

Sample Input 1:
5
1 5 3 4 2
Sample Output 1:
5 -1 4 -1 -1

Sample Input 2:
5
5 5 5 5 5
Sample Output 2:
-1 -1 -1 -1 -1
Expected time complexity :
The expected time complexity is O(n).

Constraints :
1 <= 'n' <= 10^5
1 <= 'a[i]' <= 10^9
Time Limit: 1 sec

*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextGreaterElement(vector<int>& arr, int n)
{
     // Write your code here
     int l = 1, r = n-1;
     vector<int>v(n, -1);
     for(int i=0;i<n;i++)
     {
          for(int j=i+1;j<n;j++)
          {
               if(arr[j] > arr[i])
               {
                    v[i] = arr[j];
                    break;
               }
          }
     }
     return v;
}

/* // Using Stack
vector<int> nextGreaterElement(vector<int>& arr, int n)
{
    stack<int> st;
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }

        if (st.empty())
            ans[i] = -1;
        else
            ans[i] = st.top();

        st.push(arr[i]);
    }

    return ans;
}
*/

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     vector<int> res = nextGreaterElement(v, n);
     if(!res.empty())
     {
          for(int x : res)
               cout << x << " ";
          cout << endl;
     }

     return 0;
}

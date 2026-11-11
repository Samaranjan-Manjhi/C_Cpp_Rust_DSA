/*

   Doubling the value

   Given an array arr and an integer b, traverse the array (from the beginning) and if the element in array is b, double b and continue traversal. Find the value of b after the complete traversal.

Examples :

Input: b = 2, arr[] = [1, 2, 3, 4, 8]
Output: 16
Explanation: b is initially 2. We get 2 at the 1st index, hence b becomes 4. 
Next, we get b 3rd time, hence b becomes 8. 
Next, we get b 4th time, hence b becomes 16.

Input: b = 3, arr[] = [1, 2, 3, 4, 8]
Output: 6
Explanation: b is initially 3. We get 3 2nd time, hence b becomes 6.

Constraints:
1 ≤ arr.size() ≤ 20
1 ≤ b ≤ 103
1 ≤ arr[i] ≤ 109

 */


#include <iostream>
#include <vector>

using namespace std;

int solve(int b, vector<int> &arr) 
{
     // code here.
     int n = arr.size();
     for(int i=0;i<n;i++)
     {
          if(arr[i] == b)
               b *= 2;
     }

     return b;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int b;
     cout << "Enter b Value: ";
     cin >> b;

     int res = solve(b, v);
     cout << "     Result:- " << res << endl;     

     return 0;
}

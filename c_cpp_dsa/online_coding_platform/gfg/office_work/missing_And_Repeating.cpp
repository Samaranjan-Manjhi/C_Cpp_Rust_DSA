/*

   Missing And Repeating

   Given an unsorted array arr[] of size n, containing elements from the range 1 to n, it is known that one number in this range is missing, and another number occurs twice in the array, find both the duplicate number and the missing number.

Examples:

Input: arr[] = [2, 2]
Output: [2, 1]
Explanation: Repeating number is 2 and the missing number is 1.

Input: arr[] = [1, 3, 3] 
Output: [3, 2]
Explanation: Repeating number is 3 and the missing number is 2.

Input: arr[] = [4, 3, 6, 2, 1, 1]
Output: [1, 5]
Explanation: Repeating number is 1 and the missing number is 5.

Constraints:
2 ≤ n ≤ 106
1 ≤ arr[i] ≤ n

 */


#include <iostream>
#include <vector>

using namespace std;

vector<int> findTwoElement(vector<int>& arr) 
{
     // code here
     int n = arr.size();
     vector<int> freq(n+1, 0);
     for(int x : arr)
          freq[x]++;

     int rep = -1;
     int mis = -1;
     for(int i=1;i<=n;i++)
     {
          if(freq[i] == 0)
               mis = i;
          else if(freq[i] > 1)
               rep = i;
     }

     return {rep, mis};
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     vector<int> res = findTwoElement(v);
     cout << "    Result:- ";
     if(!res.empty())
     {
          for(int x : res)
               cout << x << " ";
          cout << endl;
     }
     return 0;
}

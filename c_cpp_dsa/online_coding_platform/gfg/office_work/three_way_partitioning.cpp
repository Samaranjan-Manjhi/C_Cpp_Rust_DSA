/*

   Three way partitioning

   Given an array and a range a, b. The task is to partition the array around the range such that the array is divided into three parts.
   1) All elements smaller than a come first.
   2) All elements in range a to b come next.
   3) All elements greater than b appear in the end.
   The individual elements of three sets can appear in any order. You are required to return the modified array.

Note: The generated output is true if you modify the given array successfully. Otherwise false.

Geeky Challenge: Solve this problem in O(n) time complexity.

Examples:

Input: arr[] = [1, 2, 3, 3, 4], a = 1, b = 2
Output: true
Explanation: One possible arrangement is: {1, 2, 3, 3, 4}. If you return a valid arrangement, output will be true.

Input: arr[] = [1, 4, 3, 6, 2, 1], a = 1, b = 3
Output: true
Explanation: One possible arrangement is: {1, 3, 2, 1, 4, 6}. If you return a valid arrangement, output will be true.

Constraints:
1 <= arr.size()<= 10^6
1 <= array[i], a, b <= 10^9

 */


#include <iostream>
#include <vector>

using namespace std;

void threeWayPartition(vector<int>& arr, int a, int b) 
{
     // code here
     int n = arr.size();
     int low = 0;
     int start = 0;
     int end = n - 1;
     while (low <= end)
     {
          if (arr[low] < a)
          {
               swap(arr[low], arr[start]);
               start++;
               low++;
          }
          else if (arr[low] > b)
          {
               swap(arr[low], arr[end]);
               end--;
          }
          else
               low++;
     }
}

int main()
{
     int m;
     cout << "Enter Vector Size: ";
     cin >> m;

     vector<int> v1(m);
     for(int i=0;i<m;i++)
          cin >> v1[i];

     int a, b;
     cout << "Enter a & b value: ";
     cin >> a >> b;

     cout << "    Result Before threeWayPartition Operation:-  ";
     if(!v1.empty())
     {
          for(int x : v1)
               cout << x << " ";
          cout << endl;
     }

     threeWayPartition(v1, a, b);

     cout << "    Result After threeWayPartition Operation:-  ";
     if(!v1.empty())
     {
          for(int x : v1)
               cout << x << " ";
          cout << endl;
     }

     return 0;
}

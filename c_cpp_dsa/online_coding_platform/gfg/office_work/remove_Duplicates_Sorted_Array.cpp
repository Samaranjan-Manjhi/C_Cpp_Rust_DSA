/*

   Remove Duplicates Sorted Array

   You are given a sorted array arr[] containing positive integers. Your task is to remove all duplicate elements from this array such that each element appears only once. Return an array containing these distinct elements in the same order as they appeared.
Examples :

Input: arr[] = [2, 2, 2, 2, 2]
Output: [2]
Explanation: After removing all the duplicates only one instance of 2 will remain i.e. [2] so modified array will contains 2 at first position and you should return array containing [2] after modifying the array.

Input: arr[] = [1, 2, 4]
Output: [1, 2, 4]
Explation:  As the array does not contain any duplicates so you should return [1, 2, 4].

Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 106

 */


#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> removeDuplicates(vector<int> &arr) 
{
     // code here
     unordered_set<int> seen;
     int n = arr.size();
     vector<int> res;
     for(int i=0;i<n;i++)
     {
          if(seen.find(arr[i]) == seen.end())
          {
               seen.insert(arr[i]);
               res.push_back(arr[i]);
          }
     }

     return res;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     vector<int> res = removeDuplicates(v);
     if(!res.empty())
     {
          cout << "   Result:- ";
          for(int x : res)
               cout << x << " ";
          cout << endl;
     }

     return 0;
}

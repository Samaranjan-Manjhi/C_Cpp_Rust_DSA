/*

   Remove Duplicates 

   Problem statement

   Ninja is playing with numbers but hates when he gets duplicate numbers. Ninja is provided an array, and he wants to remove all duplicate elements and return the array, but he has to maintain the order in which the elements were supplied to him.
Constraints:

1 <= T <= 10
1 <= N <= 5*10^3
-10^5 <= arr[i] <= 10^5
Time Limit: 1 sec

Sample Input 1 :
2
5
1 2 2 3 4
5
10 11 23 23 23 
Sample Output 1:
1 2 3 4
10 11 23

Explanation for Sample Input 1:
In the first test case, ‘2’ is a duplicate element, and there are two occurrences of ‘2’, so one ‘2’ is removed, and the resultant array becomes [1 2 3 4].
In the second test case, ‘23’ is a duplicate element, and there are three occurrences of ‘23’, so two occurrences of ‘23’ must be removed, and the resultant array becomes [10 11 23].

Sample Input 2 :
2
10
1 3 3 3 3 3 4 9 23 35
5
10 10 10 10 10 
Sample Output 2:
1 3 4 9 23 35
10 

 */


#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> removeDuplicates(vector<int> arr) 
{
     // Write your code here
     vector<int> res;
     unordered_set<int> seen;

     for(int i = 0; i < arr.size(); i++)
     {
          if(seen.find(arr[i]) == seen.end())
          {
               res.push_back(arr[i]);
               seen.insert(arr[i]);
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
          for(int x : res)
               cout << x << " ";
          cout << endl;
     }

     return 0;
}

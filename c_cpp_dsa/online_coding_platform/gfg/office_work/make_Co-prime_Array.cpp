/*

   Make Co-prime Array

   Given an array of elements, find the minimum number of insertions to convert the given array into a co-prime array adjacent pair-wise. 

Examples:

Input: arr[] = [2, 7, 28]
Output: 1
Explanation: Here, 1st pair = {2, 7} are co-primes(gcd(2, 7) = 1). 2nd pair = [7, 28] are not co-primes, insert 9 between them. gcd(7, 9) = 1 and gcd(9, 28) = 1.

Input: arr[] = [5, 10, 20]
Output : 2
Explanation: Here, there is no pair which are co-primes. Insert 7 between (5, 10) and 1 between (10, 20).

Constraints:
1<= arr.size() <=10^6
1<= arr[i] <=10^6

 */

#include <iostream>
#include <vector>

using namespace std;

int mygcd(int a, int b)
{
     while (b > 0)
     {
          int temp = b;
          b = a % b;
          a = temp;
     }
     return a;
}

int countCoPrime(const vector<int>& arr) 
{
     // code here
     int cnt = 0;
     int n = arr.size();
     for (int i = 0; i<n - 1; i++)
     {
          if (mygcd(arr[i], arr[i + 1]) != 1)
          {
               cnt += 1;
          }
     }

     return cnt;
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int res = countCoPrime(v);
     cout << "    Result:- " << res << endl;

     return 0;
}

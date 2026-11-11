/*

   Ninja is bored with his previous game of numbers, so now he is playing with divisors.
   He is given 'N' numbers, and his task is to return the sum of all numbers which is divisible by 2 or 3.
   Let the number given to him be - 1, 2, 3, 5, 6. As 2, 3, and 6 is divisible by either 2 or 3 we return 2 + 3 + 6 = 11.

Constraints:
1 <= T <= 10
1 <= N <= 10^3
0 <= input[i] <= 10^3

Where ‘T’ denotes the number of test cases and ‘N’ is the elements given to Ninja and input[i] denotes theith input.
Time Limit: 1 sec  

Sample Input 1 :
2
3
1 2 3
4
5 6 9 8
Sample Output 1 :
5
23  

Explanation for Sample Input 1 :
In the first test case, 1 is neither divisible by 2 or 3. 2 is divisible by 2, and 3 is divisible by 3. So here we return the sum of 2 + 3 which is equal to 5.
In the second test case, 5 is divisible by neither 5 nor 6.6 is divisible by 2, 9 is divisible by 3, and 8 is divisible by 2. So here we return 6 + 9 + 8 = 23. 

Sample Input 2 :
2
7
7 5 11 3 5 2 9
2
3 4
Sample Output 2 :
14
7

 */

#include <iostream>
#include <vector>
using namespace std;

int findSum(int n, vector<int>& arr) 
{
     // Write your code here
     int sum = 0;
     if(arr.size() < 1) return 0;
     for(int x : arr)
     {
          if(x%2 == 0 || x%3 == 0)
               sum += x;
     }
     return sum;
}

int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     if(n == 0)
          return 0;
     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int res = findSum(n, v);
     cout << "Result:- " << res << endl;

     return 0;
}

/*
   Find the missing number in an array of 1 to N
Hint: use XOR or sum formula N*(N+1)/2 - actual_sum
Asked at: Amazon, Microsoft, Google, Flipkart, TCS
 */

#include <iostream>
#include <vector>
using namespace std;

// using sum formula
int missing_num(const vector<int>& v)
{
     int n = v.size();
     int actual_sum = (n+1)*(n+2)/2;
     int sum = 0;
     for(int i=0;i<n;i++)
     {
          sum += v[i];
     }
     return actual_sum-sum;
}

// using xor
int missing_num1(const vector<int>& v)
{
     int n = v.size();
     int xor1 = 0;
     int xor2 = 0;
     for(int i=1;i<=n+1;i++)
     {
          xor1 ^= i;
     }
     for(int i=0;i<n;i++)
     {
          xor2 ^= v[i];
     }
     return xor1 ^ xor2;
}

int main()
{
     int n, val;
     cout << "Enter Number: ";
     cin >> n;
     if(n == 0)
          return 0;
     vector<int> v;
     for(int i=0;i<n-1;i++)
     {
          cin >> val;
          v.push_back(val);
     }
     cout << "Missing Number:- " << missing_num1(v) << endl;
     return 0;
}

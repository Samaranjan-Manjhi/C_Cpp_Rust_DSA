/*
   Count the number of set bits (1s) in an integer
Methods: Brian Kernighan's (while n: count++, n &= n-1)
Asked at: Microsoft, Samsung, Amazon
 */
#include <iostream>
using namespace std;
int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     int cnt = 0;
     while(n > 0)
     {
          n &= n-1;
          cnt++;
     }
     cout << "Count of 1's:- " << cnt << endl;
     return 0;
}

/*
   Count number of set bits (1s) in an integer using bit shifting
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
          cnt += (n & 1);
          n >>= 1;
     }
     cout << "Count of 1's using bit shifting:- " << cnt << endl;
     return 0;
}

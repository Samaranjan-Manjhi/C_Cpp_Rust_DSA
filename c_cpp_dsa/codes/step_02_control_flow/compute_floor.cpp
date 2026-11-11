/*
   Without math.h, compute floor(log2(N)) for a positive integer N
Hint: count how many times you can right-shift before reaching 0
Asked at: Dolat Capital, Samsung
 */
#include <iostream>
#include <cmath>
using namespace std;
int getFloorLog2(int n)
{
     int cnt = -1;
     while(n > 0)
     {
          n >>= 1;
          cnt++;
     }
     return cnt;
}
int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     cout << "floor(log2(N)) without math.h or cmath using right shift: " <<  getFloorLog2(n) << endl;
     cout << "With cmath or math.h: " << floor(log2(n)) << endl;
     return 0;
}

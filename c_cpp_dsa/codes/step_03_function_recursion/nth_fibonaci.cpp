/*
   Write a function that returns the Nth Fibonacci term using recursion
Sequence: 1, 1, 2, 3, 5, 8, 13...
Asked at: TCS, Wipro, Infosys
 */

#include <iostream>
using namespace std;

int fibbo(int n, int a, int b)
{
     if(n == 1)
          return a;
     return fibbo(n-1, b, a+b);
}

int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     int a = 1, b = 1;
     int i = 3;
     int temp = 0;
     /*while(i <= n)
       {
       temp = a+b;
       a = b;
       b = temp;
       i++;
       }*/
     cout << "Nth term:- " << fibbo(n, a, b) << endl;
     return 0;
}

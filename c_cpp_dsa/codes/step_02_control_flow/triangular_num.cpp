/*
   Find the Nth term in series: 1, 3, 6, 10, 15, 21 (triangular numbers)
   In O(1). Hint: N*(N+1)/2
   Asked at: Capgemini, Wipro
 */
#include <iostream>
using namespace std;
int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     cout << "Nth term of Triangular Numbers:- " << (n*(n+1)/2) << endl;
     return 0;
}

/*
   Find the sum of all even numbers between 1 and N (inclusive)
   Asked at: TCS, Wipro, Capgemini
 */
#include <iostream>
using namespace std;
int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     int evenSum = 0;
     for(int i=1;i<=n;i++)
     {
          if(i%2 == 0)
               evenSum+=i;
     }
     cout << "Sum of All even Number:- " << evenSum << endl;
     return 0;
}

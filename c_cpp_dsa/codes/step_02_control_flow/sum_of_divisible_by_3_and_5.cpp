/*
   Find sum of all numbers from 1 to N divisible by 3 OR 5
   (Classic FizzBuzz sum variant)
   Asked at: Google, Amazon campus
 */
#include <iostream>
using namespace std;
int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     long long sum = 0;
     for(int i=1;i<=n;i++)
     {
          if(i%3 == 0 || i%5 == 0)
               sum += i;
     }
     cout << "Result:- " << sum << endl;
     return 0;
}

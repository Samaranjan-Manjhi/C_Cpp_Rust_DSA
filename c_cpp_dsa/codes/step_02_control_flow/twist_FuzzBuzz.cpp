/*
   FizzBuzz with a twist: print "Fizz" for multiples of 3, "Buzz" for 5,
   "FizzBuzz" for both, and "Jazz" for multiples of 7 too
   Asked at: Amazon, Flipkart (common warm-up)
 */
#include <iostream>
using namespace std;
int main()
{
     int n;
     cout  << "Enter Number: ";
     cin >> n;
     if(n%15 == 0)
          cout << "FizzBuzz\n";
     else if(n%3 == 0)
          cout << "Fizz\n";
     else if(n%5 == 0)
          cout << "Buzz\n";
     else if(n%7 == 0)
          cout << "Jazz\n";
     return 0;
}

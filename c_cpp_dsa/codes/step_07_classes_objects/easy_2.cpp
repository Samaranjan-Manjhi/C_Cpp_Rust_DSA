/*

   Create a class Counter with increment(), decrement(), reset(), getValue().
   Use private member. Demonstrate encapsulation.
   Asked at: TCS, Wipro, Infosys

 */

#include <iostream>
using namespace std;

class Counter
{
     private:
          int count;
          int init;

     public:
          Counter(int x)
          {
               count  = x;
               init = x;
          }

          void increment()
          {
               count++;
          }

          void decrement()
          {
               count--;
          }

          void reset()
          {
               count = init;
          }

          int getValue()
          {
               return count;
          }
};

int main()
{
     Counter cnt(10);

     cnt.increment();
     cnt.increment();
     cnt.decrement();
     cnt.increment();
     cout << cnt.getValue() << endl;
     cnt.reset();
     cout << cnt.getValue() << endl;

     return 0;
}

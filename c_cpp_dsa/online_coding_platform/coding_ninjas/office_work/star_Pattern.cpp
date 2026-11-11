/*

   Star Pattern

   Problem statement

   Print the following pattern
   Pattern for N = 4

   The dots represent spaces.

Constraints :

1 <= T <= 100
1 <= N <= 100

Sample Input 1 :
2
1
2   
Sample Output 1 :
   *
   * 
  ***

 Sample Input 2 :
 2
 3
 4
 Sample Output 2 :
    *
   ***
  *****
    *
   ***
  *****
 *******

 */


#include <iostream>

using namespace std;

void printPattern(int n) 
{
     // Write your code here.
     for(int i=1;i<=n;i++)
     {
          for(int j=1;j<=n-i;j++)
               cout << " ";

          for(int j=1;j<=2*i-1;j++)
               cout << "*";
          cout << endl;
     }
}

int main()
{
     int n;
     cout << "Enter No. of Rows: ";
     cin >> n;

     printPattern(n);

     return 0;
}

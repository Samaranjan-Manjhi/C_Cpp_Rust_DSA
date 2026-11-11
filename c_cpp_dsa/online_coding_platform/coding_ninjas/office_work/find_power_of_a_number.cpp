/*

   Find power of a number 

   Problem statement

   Ninja is sitting in an examination hall. He is encountered with a problem statement, "Find ‘X’ to the power ‘N’ (i.e. ‘X’ ^ ‘N’). Where ‘X’ and ‘N’ are two integers."
   Ninja was not prepared for this question at all, as this question was unexpected in the exam.
   He is asking for your help to solve this problem. Help Ninja to find the answer to the problem.

Note :
For this question, you can assume that 0 raised to the power of 0 is 1.

Sample Input 1:
2
5 2
9 3
Sample Output 1:
25
729

Explanation for Sample Input 1:

Test Case 1: 
Given X = 5 and N = 2. So, 5 ^ 2 = 25. As 5 * 5 = 25.
Test Case 2:
Given X = 9 and N = 3. So, 9 ^ 3 = 729. As 9 * 9 * 9 = 729.

Sample Input 2:
2
5 0
1 10
Sample Output 2:
1
1

 */


#include <iostream>

using namespace std;

long long Pow(int X, int N)
{
     // Write your code here. 
     long long ans = 1;
     while(N > 0)
     {
          if(N % 2 == 1)
          {
               ans *= X;
          }
          X *= X;
          N /= 2;
     }

     return ans;
}

int main()
{
     int X, N;
     cout << "Enter Input Value of X & N: ";
     cin >> X >> N;

     long long ans = Pow(X, N);
     cout << "    Result:- " << ans << endl;

     return 0;
}

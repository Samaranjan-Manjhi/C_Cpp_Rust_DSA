/*

   Problem statement

   You have been given a positive integer N. Your task is to find the Nth term of the Look-And-Say sequence.
   The Look-And-Say sequence is a sequence of positive integers. The sequence is as follows:
   1, 11, 21, 1211, 111221, 312211, 13112221,...
   This sequence is constructed in the following way:

   The first number is 1.
   This is read as “One 1”. 
   Hence, the second number will be 11.

   The second number is read as “Two 1s”. 
   Hence, the third number will be 21.

   The third number is read as “One 2, One 1”. 
   Hence, the fourth number will be 1211.

   The fourth term is read as “One 1, One 2, Two 1s”.
   Hence, the fifth term will be 111221. And so on.

Constraints:
1 <= T <= 100
1 <= N <= 40
Time Limit: 1 sec

Sample Input 1:
3
1
2
3
Sample Output 1:
1
11
21
Explanation for Sample 1:
The first term is 1.
The second term is 11.
The third term is 21.

Sample Input 2:
1
6
Sample Output 2:
312211

 */

#include <iostream>
#include <string>

using namespace std;

string lookAndSaySequence(int n) 
{
     // Write your code here
     string curr = "1";
     for(int j=2;j<=n;j++)
     {
          string nextTerm = "";    
          int cnt = 1;
          for(int i=0;i<curr.length()-1;i++)
          {
               if(curr[i] == curr[i+1])
               {
                    cnt++;         
               }
               else
               {
                    nextTerm += to_string(cnt);
                    nextTerm += curr[i];
                    cnt = 1;
               }
          }
          nextTerm += to_string(cnt);
          nextTerm += curr[curr.length()-1];
          curr = nextTerm;
     }
     return curr;
}

int main()
{
     int n;
     cout << "Enter Input Term: ";
     cin >> n;

     string res = lookAndSaySequence(n);
     cout << "Result:- " << res << endl;

     return 0;
}

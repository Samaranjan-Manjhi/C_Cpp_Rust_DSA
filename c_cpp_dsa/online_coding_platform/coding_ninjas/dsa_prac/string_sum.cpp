/*

   Problem statement
   You are given two non-negative integers, ‘NUM1’ and ‘NUM2’, in the form of strings. Return the sum of both strings.

Note :
You do not need to print anything, it has already been taken care of. Just implement the given function.

Example:
Let ‘NUM1’ be: “5”
Let ‘NUM2’ be: “21”
The sum of both numbers will be: “26”.

Constraints :
1 <= T <= 10
1 <= |NUM1|, |NUM2| <= 10^5
NUM1 and NUM2 don’t have leading zeroes.
Where |NUM1| and |NUM2| denote the length of the respective strings.
Time limit: 1 sec

Sample Input 1 :
2
5 21
10 9
Sample output 1 :
26
19

Explanation For Sample Output 1 :
For the first test case:
The sum of both numbers will be: “26”.
For the second test case:
The sum of both numbers will be: “19”.

Sample Input 2 :
2
9 9
21 10
Sample output 2 :
18
31

4
9999999999999 999999999999
62330389321919 40518797368217655506
1999999999999 1
54225983823825735266 922275277979
Output
10999999999998
40518859698606977425
2000000000000
54225984746101013245
 */


#include <iostream>
#include <cstring>
using namespace std;

long long string_to_num(string& s1)
{
     long long n = s1.length();
     if(n <= 0)
          return 0;
     long long data = 0;
     for(long long i=0;i<n;i++)
     {
          if(s1[i] < '0' && s1[i] > '9')
               return -1;
          data = data*10 + (s1[i]-'0');
     }
     return data;
}

int main()
{
     string str, str1 ;
     cout << "Enter String: ";
     cin >> str >> str1;
     long long res = string_to_num(str);
     long long res1 = string_to_num(str1);
     cout << "Result: " << to_string(res+res1) << endl;

     return 0;
}

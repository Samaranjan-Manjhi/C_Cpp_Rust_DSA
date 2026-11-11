/*
You are given two positive integers ‘N’ and ‘K’. Your task is to find the smallest ‘N’ digit number whose sum of digits equals ‘K’. If no such number exists then you need to print -1.

Sample Input 1 :

2
2 8
3 1

Sample Output 1 :

17 
100

Explanation of Sample Input 1 :

Test Case 1 :  
N = 2 and K = 8. 
All two-digit numbers  whose sum of digits = 8 are [17, 26, 35, 44, 53, 62, 71, 80]
The smallest two-digit number whose sum of digits = 8 is 17. 

Test Case 2 : 
N = 3 and K = 1. 
The smallest three-digit number whose sum of digits = 1 is 100. 

Sample Input 2 :

2
4 5 
1 8

Sample Output 2 :

1004
8

Explanation of Sample Input 2 :

Test Case 1 :  
N = 4 and K = 5. 
The smallest four-digit number whose sum of digits = 5 is 1004. 

Test Case 2 : 
N = 1 and K = 8. 
The smallest one-digit number whose sum of digits = 8 is 8. 


*/

#include <iostream>
#include <cstring>
using namespace std;

string smallestNumber(int n, int k)
{
     // Write your code here
     /*
     string str = "";
     if(n == 0)
          return str;
     if(n == 1)
          return to_string(k);
     if(n > 1)
          str += "1";
     int temp = k-1;
     //str += to_string(temp);
     cout << "String length :- " << str.length()  << endl;
     for(int i=str.length()+2;i<=n;i++)
     {
          str += "0";
     }
     str += to_string(temp);
     return str;

     */

     if(k > 9*n || (k == 0 && n > 1))
		return "-1";
	string res(n, '0');
	k--;
	for(int i=n-1;i>0;i--)
	{
		if(k > 9)
		{
			res[i] = '9';
			k -= 9;
		}
		else
		{
			res[i] = char('0' + k);
			k = 0;
		}
	}
	res[0] = char('1' + k);
	return res;

}

int main()
{
     int n , k;
     cout << "Enter Nunmber: ";
     cin >> n >> k;
     string res = smallestNumber(n, k);
     cout << "Result:- " << res << endl;
     return 0;
}

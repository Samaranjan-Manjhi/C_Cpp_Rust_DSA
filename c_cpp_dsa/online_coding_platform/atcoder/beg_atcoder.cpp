/*


PracticeA - Welcome to AtCoder /

Time Limit: 2 sec / Memory Limit: 1024 MiB
Problem

Your task is to process some data.
You are given
3 integers a , b , c and a string s. Output result of a+b+c and string

s with a half-width break.
Constraints

1≤a,b,c≤1,000

    1≤∣s∣≤100

Input

Input will be given in the following format from Standard Input:
a
b c
s


*/

#include <iostream>
#include <cstring>
using namespace std;
int main()
{
     int a;
     cin >> a;
     int b, c;
     cin >> b >> c;
     string s;
     cin >> s;
     cout << (a+b+c) << " " << s << endl;
     return 0;
}

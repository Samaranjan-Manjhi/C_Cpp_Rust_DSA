/*

   Problem statement

   You have been given three distinct integers ‘X’, ‘Y’ and ‘Z’. You need to find the number with a value in the middle.

   For example :
   X = 4, Y = 6, Z = 2
   Here the element with value in the middle is 4, because 2 < 4 < 6.

Note :
You need to try doing it using minimum comparisons.

Constraints :
1 <= T <= 50
1 <= X, Y, Z <= 10^9
Where ‘T’ is the number of test cases.
Where ‘X’, ‘Y’, and ‘Z’ denote the distinct numbers.
Time limit: 1 sec

Sample Input 1 :
2
2 3 1
6 8 9   
Sample Output 1 :
2 
8

Explanation of sample input 1 :
In the first test case, the three numbers are 2, 3 and 1. The middle element is 2, as 1 < 2 < 3
In the second test case, the three numbers are 6, 8 and 9. The middle element is 8, as 6 < 8 < 9

Sample Input 2 :
2
15 2 3
2 3 4
Sample Output 2 :
3
3

Explanation for sample input 2 :
In the first test case, the three numbers are 15, 2 and 3. The middle element is 3, as 2 < 3 < 15
In the second test case, the three numbers are 2, 3 and 4. The middle element is 3, as 2 < 3 < 4

 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int middleOfThree(int x, int y, int z)
{
     // Write your code here   
     /*
        vector<int> v;
        v.push_back(x);
        v.push_back(y);
        v.push_back(z);
        sort(v.begin(), v.end());
        return v[1];
      */

     /*
        if ((x > y && x < z) || (x < y && x > z))
        return x;
        else if ((y > x && y < z) || (y < x && y > z))
        return y;
        else
        return z;
      */
     return (x+y+z-(max(x, max(y, z)))-(min(x, min(y, z))));
}
int main()
{
     int a, b, c;
     cout << "Enter 3 Numbers: ";
     cin >> a >> b >> c;
     int res = middleOfThree(a, b, c);
     cout << "Result:- " << res << endl;
     return 0;
}

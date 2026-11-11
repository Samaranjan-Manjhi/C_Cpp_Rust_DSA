/*

   Problem statement

   You have a bookshelf in the form of an array ‘arr’ in which names of the books(single word name) are given. You are also given names of two books, ‘book1’ and ‘book2’. You are supposed to find the minimum distance between ‘book1’ and ‘book2’.

   Distance between two books is defined as the absolute difference between the indices of the books i.e for two books at index 'i' and 'j' the distance is equal to |i-j|.

Note:
1. There may be multiple occurrences of any book.
2. book1 and book2 are present on the bookshelf.
3. The name of the books is in lower-case.
4. book1 is not equal to book2.

Constraints:
1<= T <= 50
2 <= N <= 10^4
1 <= arr[i].length <= 10^4
All strings consist of lowercase letters only.

Where ’T’ is the number of test cases, and N denotes the number of elements in the array ‘arr’, arr[i] denotes the element at index ‘i’.
Time Limit: 1 sec

Sample Input 1:
2
8
coding ninjas help to crack product based companies
coding product
8
eat code sleep repeat eat code sleep repeat 
eat repeat
Sample Output 1:
5
1
Explanation for Sample Input 1:
In the first test case, there are 8 books on the bookshelf.
book1 = “coding”, book2 = “product”. The distance between book1 and book2 is 5. So, the answer is 5.
In the second test case, there are 8 books on the bookshelf. and there are 2 occurrences in every book.
book1 = “eat”, book2 = “repeat”.  book1 is present at indices 0 and 4. book2 is present at indices 3 and 7. The distances are 3, 7, 1, 4. The minimum of these is 1. So, the answer is 1.

Sample Input 2:
2
5
alpha beta gamma theta beta
theta beta
6
be cool whatever the situation is
situation cool
Sample Output 2:
1
3

 */

#include <iostream>
#include <vector>
#include <string>
#include <limits.h>

using namespace std;

int minimumDistance(vector<string> &arr, string book1, string book2) 
{
     int n = arr.size();
     int start = -1, end = -1;
     int minidst = INT_MAX;
     for(int k=0;k<n;k++)
     {
          if(arr[k] == book1)
               start = k;

          if(arr[k] == book2)
               end = k;		

          if(start != -1 && end != -1)
          {
               int temp = abs(start-end);
               minidst = min(minidst, temp);
          }
     }
     return minidst;
}

int main()
{
     int n;
     cout << "Enter Size of Vector: ";
     cin >> n;

     vector<string> bk(n);
     for(int i=0;i<n;i++)
          cin >> bk[i];

     string bk1;
     cout << "Enter Book1 Name: ";
     cin >> bk1;

     string bk2;
     cout << "Enter Book2 Name: ";
     cin >> bk2;

     int res = minimumDistance(bk, bk1, bk2);
     cout << "Minimum Distance between books:- " << res << endl;

     return 0;
}

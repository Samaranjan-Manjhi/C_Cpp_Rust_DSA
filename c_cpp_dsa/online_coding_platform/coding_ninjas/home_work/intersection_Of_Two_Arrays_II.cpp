/*

   Intersection of Two Arrays II

   Problem statement

   You have been given two integer arrays/list(ARR1 and ARR2) of size N and M, respectively. You need to print their intersection; An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words, when there is a common value that exists in both the arrays/lists.
Note :
Input arrays/lists can contain duplicate elements.
The intersection elements printed would be in the order they appear in the first array/list(ARR1)

Constraints :
1 <= t <= 10^2
0 <= N <= 10^3
0 <= M <= 10^3
Time Limit: 1 sec 

Sample Input 1 :
2
6
2 6 8 5 4 3
4
2 3 4 7 
2
10 10
1
10
Sample Output 1 :
2 4 3
10

Sample Input 2 :
1
4
2 6 1 2
5
1 2 3 4 2
Sample Output 2 :
2 1 2
Explanation for Sample Output 2 :
Since, both input arrays have two '2's, the intersection of the arrays also have two '2's. The first '2' of first array matches with the first '2' of the second array. Similarly, the second '2' of the first array matches with the second '2' if the second array.

 */


#include <iostream>
#include <vector>

using namespace std;

void intersection(int *input1, int *input2, int size1, int size2)
{
     //Write your code here
     if(size1 == 0 || size2 == 0)
          return;
     bool *visited = new bool[size2];

     for(int i = 0; i < size2; i++)
     {
          visited[i] = false;
     }

     for(int i = 0; i < size1; i++)
     {
          for(int j = 0; j < size2; j++)
          {
               if(input1[i] == input2[j] && visited[j] == false)
               {
                    cout << input1[i] << " ";
                    visited[j] = true;
                    break;
               }
          }
     }

     delete [] visited;
}

int main()
{
     int n;
     cout << "Enter Input Array1 Size: ";
     cin >> n;

     int *arr = new int[n];
     for(int i=0;i<n;i++)
          cin >> arr[i];

     int m;
     cout << "Enter Input Array2 Size: ";
     cin >> m;

     int *arr1 = new int[m];
     for(int i=0;i<m;i++)
          cin >> arr1[i];

     intersection(arr, arr1, n, m);
     delete[] arr;
     delete[] arr1;

     return 0;
}

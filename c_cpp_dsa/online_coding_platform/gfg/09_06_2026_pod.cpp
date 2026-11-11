/*

   Given an integer k representing the number of people to be seated and an array seats[], where 0 denotes an empty seat and 1 denotes an occupied seat.
   Determine whether it is possible to seat all k people such that no two occupied seats are adjacent (including newly seated people).

Examples:

Input: k = 2, seats[] = [0, 0, 1, 0, 0, 0, 1]
Output: true
Explanation: The two people can sit at index 0 and 4.

Input: k = 1, seats[] = [0, 1, 0]
Output: false
Explanation: There is no way to get a seat for one person.

Input: k = 0, seats[] = [0, 0, 0, 1, 1]
Output: false
Explanation: The seating arrangement already contains two adjacent occupied seats at indices 3 and 4.

Constraints:
0 ≤ k ≤ 105
1 ≤ seats.size() ≤ 105
seats[i] == 0 or seats[i] == 1

 */

#include <iostream>
#include <vector>

using namespace std;

bool canSeatAllPeople(int k, vector<int> &seats) 
{
     // code here
     int n = seats.size();
     
     for(int i=0;i<n-1;i++)
     {
          if(seats[i] == 1 && seats[i+1] == 1)
               return false;
     }

     int placed = 0;
     for(int i=0;i<n;i++)
     {
          if((i == 0 || seats[i-1] == 0) && seats[i] == 0 && (i == n-1 || seats[i+1] == 0))
          {
               seats[i] = 1;
               k--;          
          }
     }
     if(k <= 0)
          return true;
     return false;
}

int main()
{
     int n;
     cout << "Enter Size of Vector: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     int k;
     cout << "Enter Person Count: ";
     cin >> k;

     bool res = canSeatAllPeople(k, v);
     if(res)
          cout << "Yes\n";
     else
          cout << "No\n";

     return 0;
}

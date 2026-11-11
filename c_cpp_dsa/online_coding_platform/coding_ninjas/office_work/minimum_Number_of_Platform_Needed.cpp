/*

   Minimum Number of Platform Needed 

   Problem statement

   You are given the arrival and departure times of N trains at a railway station in a day. You need to find the minimum of platforms required for the railway station such that no train waits i.e No train should wait for the platform to be clear or free.
Constraints :

1 <= T <=100
1 <= N <=1000
0 <= arrival[i] <= departure[i] <= 2359
Time Limit: 1 sec

Sample Input 1 :
1
6
900 940 950 1100 1500 1800
910 1200 1120 1130 1900 2000
Sample Output 1:
3

Explanation of Input 1 :

During the interval [900 - 910], there will be one train.
During the interval [910 - 940], there will be no train.
During the interval [940 - 950], there will be one train.
During the interval [950 - 1100], there will be two trains, as the third train will arrive before the second train leaves.
During the interval [1100 - 1120], there will be three trains.
During the interval [1120 - 1130], there will be two trains, as the third train leaves the station.
During the interval [1130 - 1200], there will be one train.
During the interval [1200 - 1500], there will be no train.
During the interval [1500 - 1800], there will be one train.
During the interval [1800 - 1900], there will be two trains.
During the interval [1900 - 2000], there will be one train.
After the interval [2000], there will be no train.
So the number of platforms needed is 3.

Sample Input 2 :
1
3
900 1000 1200
1000 1100 1240
Sample Output 2 :
2

 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int platformsNeeded(vector<int>& arrival, vector<int>& departure, int n)
{
     // Sort both arrival and departure arrays
     sort(arrival.begin(), arrival.end());
     sort(departure.begin(), departure.end());

     int i = 0, j = 0;
     int curr = 0;
     int maxi = 0;

     while (i < n && j < n)
     {
          if (arrival[i] <= departure[j])
          {
               curr++;
               maxi = max(maxi, curr);
               i++;
          }
          else 
          {
               curr--;
               j++;
          }
     }

     return maxi;
}

int main() 
{
     int n;
     cout << "Enter the number of trains: ";
     if (!(cin >> n) || n <= 0) {
          cout << "Invalid number of trains." << endl;
          return 0;
     }

     vector<int> arrival(n);
     vector<int> departure(n);

     // Read arrival times
     cout << "Enter the arrival times (e.g., 900 for 9:00, 1230 for 12:30):" << endl;
     for (int i = 0; i < n; i++) {
          cout << "Train " << i + 1 << " arrival: ";
          cin >> arrival[i];
     }

     // Read departure times
     cout << "Enter the departure times:" << endl;
     for (int i = 0; i < n; i++) {
          cout << "Train " << i + 1 << " departure: ";
          cin >> departure[i];
     }

     // Calculate and output result
     int result = platformsNeeded(arrival, departure, n);
     cout << "    Minimum number of platforms required: " << result << endl;

     return 0;
}

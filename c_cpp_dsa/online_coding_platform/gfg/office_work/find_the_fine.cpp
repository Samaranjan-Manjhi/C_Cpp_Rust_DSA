/*

Find the fine

Given an array of car numbers car[], an array of penalties fine[], and an integer date, determine the total fine collected on that date. The fine is collected based on parity, i.e., on an even date, fines are collected from odd-numbered cars, and on an odd date, fines are collected from even-numbered cars.

Examples:

Input: date = 12, car[] = [2375, 7682, 2325, 2352], fine[] = [250, 500, 350, 200]
Output: 600
Explanation: The date is 12 (even), so we collect the fine from odd-numbered cars. The odd-numbered cars and the fines associated with them are as follows:
2375 -> 250
2325 -> 350
The sum of the fines is 250+350 = 600

Input: date = 8, car[] = [2222, 2223, 2224], fine[] = [200, 300, 400]
Output: 300

Constraints:
1 <= car.size <= 105
1 <= car[i], fine[i], date <= 105

*/

#include <iostream>
#include <vector>

using namespace std;

long long int totalFine(int date, vector<int> &car, vector<int> &fine) 
{
     // code here
     cout << "funcrtiobdsd\n";
     long long int even = 0, odd = 0;
     bool isEven = false;
     if(date % 2 == 0)
          isEven = true;

     int n = car.size();
     int m = fine.size();
     for(int i=0;i<min(n, m);i++)
     {
          cout << "car: " << car[i] << "    fine: " << fine[i] << endl;
          if(car[i] % 2 != 0 && isEven == true)
               even += fine[i];
          else if(car[i] % 2 == 0 && isEven == false)
               odd += fine[i];
     }
     if(isEven)
          return even;
     
     return odd;
}

int main()
{
     int d;
     cout << "Enter Date: ";
     cin >> d;

     int n;
     cout << "Enter Size of Car: ";
     cin >> n;
     vector<int> car(n);
     for(int i=0;i<n;i++)
          cin >> car[i];

     int m;
     cout << "Enter Size of Fine: ";
     cin >> m;
     vector<int> fine(m);
     for(int i=0;i<m;i++)
          cin >> fine[i];

     long long int total = totalFine(d, car, fine);
     cout << "   Result:- " << total << endl;

     return 0;
}

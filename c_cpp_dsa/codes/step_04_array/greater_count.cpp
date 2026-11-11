/*
   Count elements greater than a given value X in an array
   Asked at: TCS, Wipro, Capgemini
 */

#include <iostream>
#include <vector>
using namespace std;

int count_greater(const vector<int>& v, int x)
{
     int cnt = 0;
     for(int data : v)
     {
          if(data > x)
               cnt++;
     }
     return cnt;
}

int main()
{
     int n, val;
     cout << "Enter Number: ";
     cin >> n;
     if(n == 0)
          return 0;
     vector<int> v;
     for(int i=0;i<n;i++)
     {
          cin >> val;
          v.push_back(val);
     }
     int num;
     cout << "Enter Num:- ";
     cin >> num;
     cout << "Result:- " << count_greater(v, num) << endl;
     return 0;
}

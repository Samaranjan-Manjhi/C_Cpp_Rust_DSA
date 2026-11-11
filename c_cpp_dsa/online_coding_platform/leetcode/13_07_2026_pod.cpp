/*

   1291. Sequential Digits

   An integer has sequential digits if and only if each digit in the number is one more than the previous digit.
   Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

   Example 1:
Input: low = 100, high = 300
Output: [123,234]

Example 2:
Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]

Constraints:
10 <= low <= high <= 10^9

 */


#include <iostream>
#include <vector>
#include <string>

using namespace std;

int getLen(int n)
{
     int cnt = 0;
     while(n > 0)
     {
          cnt++;
          n /= 10;
     }

     return cnt;
}

vector<int> sequentialDigits(int low, int high) 
{
     vector<int> res;
     string digit = "123456789";
     int lowLen = getLen(low);
     int highLen = getLen(high);
     //cout << "lowLen: " << lowLen << endl;
     //cout << "highLen: " << highLen << endl;

     for(int len=lowLen;len<=highLen;len++)
     {
          for(int start=0;start<=9-len;start++)
          {
               string temp = "";
               for (int j = start; j < start + len; j++)
               {
                    temp += digit[j];
               }
               //cout << "temp:- " << temp << endl;
               int curr = stoi(temp);

               if(curr >= low && curr <= high)
                    res.push_back(curr);
          }
     }

     return res;
}

int main()
{
     int low;
     cout << "Enter Low Range: ";
     cin >> low;

     int high;
     cout << "Enter High Range: ";
     cin >> high;

     vector<int> res = sequentialDigits(low, high);
     cout << "     Result:- ";
     if(!res.empty())
     {
          for(int x : res)
               cout << x << " ";
          cout << endl;
     }

     return 0;
}

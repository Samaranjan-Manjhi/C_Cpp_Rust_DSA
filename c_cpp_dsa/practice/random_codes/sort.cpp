#include <iostream>
#include <vector>
using namespace std;

void sortZeroOneTwo(vector<int>& nums) 
{
     int cnt0 = 0, cnt1 = 0, cnt2 = 0;
     for(int i=0;i<nums.size();i++)
     {
          if(nums[i] == 0)
               cnt0++;
          else if(nums[i] == 1)
               cnt1++;
          else
               cnt2++;
     }
     cout << cnt0 << "  " << cnt1 << "   " << cnt2 << endl;
     //for(int i=0; i<nums.size();i++)
     int i = 0;
     {
          while(cnt0-- )
          {
               nums[i++] = 0;
          }
          while(cnt1--)
          {
               nums[i++] = 1;
          }
          while(cnt2--)
          {
               nums[i++] = 2;
          }
     }
}

void print(const vector<int>& v)
{
     for(int i=0;i<v.size();i++)
     {
          cout << v[i] << " "; 
     }
     cout << endl;
}
int main()
{
     vector<int> v{1, 2, 0, 1, 1, 2, 2, 0, 0};
     print(v);
     sortZeroOneTwo(v);
     print(v);

     return 0;
}

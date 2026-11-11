/*

   Statistics From A Large Sample

   Problem statement

   You have been given a sample of integers in the range [0, 255]. Since the sample is quite large, you are provided with an array/list “count” whose i-th element denotes the number of times ‘i’ appears in the sample.

   You are supposed to calculate the following statistics :
   1. minimum: The minimum element in the sample.
   2. maximum: The maximum element in the sample.
   3. mean: The average of the sample, calculated as the total sum of all elements divided by the total number of elements.
   4. median:
   If the sample has an odd number of elements, then the median is the middle element once the sample is sorted.
   If the sample has an even number of elements, then the median is the average of the two middle elements once the sample is sorted.
   5. mode: The number that appears the most in the sample. It is guaranteed to be unique.

Constraints :
1 <= T <= 50
0 <= count[i] <= 1000    
Where count[i] is the i-th element of the “count” array/list.
Time limit: 1 sec

Sample Input 1 :
2
1 0 1 1 1 1 1 2 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
1 2 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
Sample Output 1 :
0.00000 8.00000 4.66667 5.00000 7.00000
0.00000 2.00000 1.00000 1.00000 1.00000

Explanation of Sample Input 1 :

For the first test case, the elements in the sample are [0, 2, 3, 4, 5, 6, 7, 7, 8]. The minimum and maximum element is 0 and 8 respectively. Mean is (0 + 2 + 3 + 4 + 5 + 6 + 7 + 7 + 8) / 9 = 4.66667. Since the sample size is odd, median is the middle element i.e. 5. The mode is 7 as it appears the most in the sample.

For the second test case, the elements in the sample are [0, 1, 1, 2]. The minimum and maximum element is 0 and 2 respectively. Mean is (0 + 1 + 1 + 2) / 4 = 1.00000. Since the sample size is even, the median is the average of the two middle elements i.e. (1 + 1) / 2 = 1. The mode is 1 as it appears the most in the sample.

 */


#include <iostream>
#include <vector>

using namespace std;

vector<double> sampleStats(vector<int> &count)
{
     // Write your code here.
     int mini = -1;
     int maxi = -1;
     int mode = -1;
     int maxFreq = 0;
     long long totalCnt = 0;
     long long totalSum = 0;

     for(int i=0;i<count.size();i++)
     {
          if(count[i] > 0)
          {
               if(mini == -1)
                    mini = i;
               maxi = i;
               totalCnt += count[i];
               totalSum += i*count[i];
               if(count[i] > maxFreq)
               {
                    maxFreq = count[i];
                    mode = i;
               }
          }
     }

     double mean = (double)totalSum / totalCnt;

     double median = 0;

     if(totalCnt % 2 == 1)
     {
          //double median = 0;
          double tar = (totalCnt + 1)/2;
          double commu = 0;
          for(int i=0;i<count.size();i++)
          {
               commu += count[i];

               if(commu >= tar)
               {
                    median = i;
                    break;
               }
          }
     }
     else
     {
          double tar1 = totalCnt / 2;
          double tar2 = tar1 + 1;
          double commu = 0;
          double firstMed = -1, secMed = 0;
          for(int i=0;i<count.size();i++)
          {
               commu += count[i];
               if(commu >= tar1 && firstMed == -1)
               {
                    firstMed = i;
               }

               if(commu >= tar2)
               {
                    secMed = i;
                    break;
               }
          }

          median = (firstMed + secMed) / 2;
     }

     return {(double)mini, (double)maxi, mean, (double)median, (double)mode};
}

int main()
{
     int n;
     cout << "Enter N value: ";
     cin >> n;

     vector<int> v(n);
     for(int i=0;i<n;i++)
          cin >> v[i];

     vector<double> res = sampleStats(v);
     cout << "    Result:- ";
     if(!res.empty())
     {
          for(double x : res)
               cout << x << " ";
          cout << endl;
     }

     return 0;
}

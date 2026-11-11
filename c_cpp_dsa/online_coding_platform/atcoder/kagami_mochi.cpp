/*
   Time Limit: 2 sec / Memory Limit: 256 MiB

Score :

200 points
Problem Statement

An
X-layered kagami mochi (X≥1) is a pile of X round mochi (rice cake) stacked vertically where each mochi (except the bottom one) has a smaller diameter than that of the mochi directly below it. For example, if you stack three mochi with diameters of 10, 8 and 6 centimeters from bottom to top in this order, you have a 3-layered kagami mochi; if you put just one mochi, you have a

1-layered kagami mochi.

Lunlun the dachshund has
N round mochi, and the diameter of the i-th mochi is
di​ centimeters. When we make a kagami mochi using some or all of them, at most how many layers can our kagami mochi have?
Constraints

1≤N≤100
1≤di​≤100
All input values are integers.

Input
Input is given from Standard Input in the following format:
N
d1 .. dN

Output
Print the maximum number of layers in a kagami mochi that can be made.

Sample Input 1
4
10
8
8
6
Sample Output 1
3
If we stack the mochi with diameters of 10, 8 and 6 centimeters from bottom to top in this order, we have a 3-layered kagami mochi, which is the maximum number of layers.

Sample Input 2
3
15
15
15
Sample Output 2
1
When all the mochi have the same diameter, we can only have a 1-layered kagami mochi.

Sample Input 3
7
50
30
50
100
50
80
30
Sample Output 3
4

 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int kagami_layer(vector<int>& v)
{
     int cnt = 0;
     sort(v.begin(), v.end(), greater<int>());
     for(int i=1;i<v.size();i++)
     {
          if(v[i-1] != v[i])
               cnt++;
     }
     return cnt;
}

int main()
{
     int n, val;
     cin >> n;
     set<int> v;
     for(int i=0;i<n;i++)
     {
          cin >> val;
          v.insert(val);
     }
     cout << "Result:- " << v.size() << endl;
     return 0;
}

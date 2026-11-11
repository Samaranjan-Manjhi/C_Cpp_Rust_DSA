#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
     vector<int> v{1, 1, 2, 2, 2, 4};
     vector<int> v1{2, 4};
     vector<int> res;

     unordered_set<int> us(v.begin(), v.end()); 
     unordered_set<int> us1(v1.begin(), v1.end());

     for (int x : us1) 
     {
          if (us.find(x) != us.end()) 
          {
               res.push_back(x);
          }
     }

     for (int x : res) 
          cout << x << " "; 

     return 0;
}

#include <iostream>

using namespace std;

void print(int n)
{
     for(int i=1;i<=n;i++)
     {
          for(int j=1;j<=n;j++)
          {
               cout << "*" << " ";
          }
          cout << "\n";
     }
}

int main()
{
     int n;
     cout << "Enter n Value: ";
     cin >> n;
     print(n);
     return 0;
}

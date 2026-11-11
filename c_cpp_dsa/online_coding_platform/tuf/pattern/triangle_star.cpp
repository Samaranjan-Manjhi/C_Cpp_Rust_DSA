#include <iostream>

using namespace std;

void print(int n)
{
     for(int i=1;i<=n;i++)
     {
          for(int j=0;j<i;j++)
          {
               cout << "* ";
          }
          cout << endl;
     }
}

int main()
{
     int n;
     cout << "Enter N value: ";
     cin >> n;
     print(n);
     return 0;
}

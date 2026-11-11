#include <iostream>
using namespace std;
int main()
{
char* p = "Hello";
char* &q = p;
cout << q << endl;

return 0;
}

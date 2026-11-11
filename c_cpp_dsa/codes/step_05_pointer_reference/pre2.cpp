#include <iostream>
using namespace std;

int main() 
{
	int x = 5;
	int *p = &x;

	*p = 15;
	int y = *p + x;

	cout << x << endl; // 15
	cout << y << endl; // 30
}

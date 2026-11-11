#include <iostream>
using namespace std;

int main() 
{
	int x = 5;
	int &r = x;
	int *p = &r;

	r = 15;
	*p = *p + 5;

	cout << x << endl; // 15
	cout << r << endl; // 20 
	cout << *p << endl; // 20
}

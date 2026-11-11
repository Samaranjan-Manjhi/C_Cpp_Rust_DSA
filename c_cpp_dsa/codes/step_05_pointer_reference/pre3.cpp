#include <iostream>
using namespace std;

int main() 
{
	int x = 10, y = 30;
	int *p = &x;
	int **q = &p;

	*q = &y;

	cout << x << endl; // 10
	cout << y << endl; // 30
	cout << *p << endl; // Address of x
	cout << **q << endl; // Address of y
}

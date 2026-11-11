#include <iostream>
using namespace std;

int main() 
{
	int x = 12;
	int *a = &x;
	int **b = &a;
	int ***c = &b;

	cout << &c << endl; // Address of c
	cout << &b << endl; // Address of b
	cout << &a << endl; // Address of a
	cout << *c << endl; // Address of b
	cout << **c << endl; // Address of a
	cout << ***c << endl; // 12
}

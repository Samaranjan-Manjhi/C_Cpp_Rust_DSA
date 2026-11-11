#include <iostream>
using namespace std;

int main() 
{
	int x = 10;
	int *p = &x;
	int **q = &p;

	cout << **q << endl; // 10

	(*p)++;
	cout << x << endl; // 11

	cout << *q << endl; // Address of x
	cout << &x << endl; // Address of x
	cout << **q << endl; // 11
}

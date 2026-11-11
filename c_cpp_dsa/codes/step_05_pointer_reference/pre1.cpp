#include <iostream>
using namespace std;

int main() 
{
	int x = 20;
	int *p = &x;
	int **q = &p;

	cout << x << endl; // 20
	cout << &x << endl; // Address of x
	cout << *p << endl; // 20 
	cout << **q << endl; // 20
	cout << p << endl; // Address of X
	cout << *q << endl; // Adress of x
}

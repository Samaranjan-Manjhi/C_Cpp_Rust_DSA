#include <iostream>
using namespace std;

int main() 
{
	int x = 3;
	int *p = &x;
	int **q = &p;

	cout << *p++ << endl; // 3
	cout << x << endl; // 4 
	cout << **q << endl; // 4
}

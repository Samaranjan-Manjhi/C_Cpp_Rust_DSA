#include <iostream>
using namespace std;

int main() 
{
	int x = 7;
	int *p = &x;
	int **q = &p;
	int ***r = &q;

	***r = 50;

	cout << x << endl; // 50
	cout << *p << endl; // 50
	cout << **q << endl; // 50
	cout << ***r << endl; // 50
}

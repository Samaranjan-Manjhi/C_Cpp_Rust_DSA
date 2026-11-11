#include <iostream>
using namespace std;

int main() 
{
	int arr[] = {2, 4, 6, 8};
	int *p = arr;

	cout << *p++ << endl; // 2
	cout << *p << endl; // 4
	cout << *++p << endl; // 8
}

#include <iostream>
using namespace std;

int main() {
	int arr[] = {10, 20, 30, 40};
	int *p = arr;

	cout << *p << endl; // 10
	cout << *(p + 2) << endl; // 30

	p++;
	cout << *p << endl; // 10
	cout << *(p + 2) << endl; // 30
}

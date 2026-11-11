#include <iostream>

int main() 
{
	int x = 10;
	int y = 20;
	int* ptr = &x;

	*ptr = 15;
	ptr = &y;
	*ptr = *ptr + 5;

	std::cout << x << " " << y << std::endl; // 15 25
	return 0;
}

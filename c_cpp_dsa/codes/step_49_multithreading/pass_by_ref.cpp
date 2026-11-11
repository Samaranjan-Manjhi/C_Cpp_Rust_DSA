
// Pass arguments to a thread by reference (std::ref)

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

void update1(int& x)
{
	lock_guard<mutex> lock(mtx);
	x = 100;
}

void update2(int& x)
{
	lock_guard<mutex> lock(mtx);
	x = 1000;
}

int main()
{
	int value = 10;
	cout << "Initial Value:- " << value << endl;

	thread t1(update1, ref(value));
	{
		lock_guard<mutex> lock(mtx);
		cout << "Value during t1:- " << value << endl;
	}
	t1.join();

	thread t2(update2, ref(value));
	{
		lock_guard<mutex> lock(mtx);
		cout << "Value during t2:- " << value << endl;
	}
	t2.join();

	cout << "Final Value:- " << value << endl;

	return 0;
}

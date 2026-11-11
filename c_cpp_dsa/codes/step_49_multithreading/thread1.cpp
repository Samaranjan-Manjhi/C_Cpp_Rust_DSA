
// Launch a thread that prints a message, then join it.

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

void task1()
{
	for(int i=0;i<100000;i++)
	{
		lock_guard<mutex> lock(mtx);
		cout << "T1:-  " << i << endl;
	}
}

void task2()
{
	for(int i=11;i<100000;i++)
	{
		lock_guard<mutex> lock(mtx);
		cout << "T2:-  " << i << endl;
	}
}

int main()
{
	thread t1(task1);
	thread t2(task2);

	t1.join();
	t2.join();

	return 0;
}

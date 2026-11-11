
// Pass arguments to a thread by value

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
mutex mtx;

void count1(int x, int y)
{
		lock_guard<mutex> lock(mtx);
	for(int i=x;i<=y;i++)
	{
		//lock_guard<mutex> lock(mtx);
		cout << "count1:-  " << i << "\n";
	}
}

void count2(int x, int y)
{
	for(int i=x;i<=y;i++)
	{
		lock_guard<mutex> lock(mtx);
		cout << "count2:-  " << i << "\n";
	}
}

int main()
{
	thread t1(count1, 1, 100);
	thread t2(count2, 101, 200);

	t1.join();
	t2.join();

	return 0;
}

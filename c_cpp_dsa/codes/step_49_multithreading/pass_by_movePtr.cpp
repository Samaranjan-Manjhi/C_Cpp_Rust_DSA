
// Pass arguments to a thread by move-only type (unique_ptr)

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
mutex mtx;

void process(unique_ptr<int>ptr)
{
	cout << "ptr value:- " << *ptr << endl;
}

int main()
{
	unique_ptr<int> p(new int(10));
	cout << "Initial Value of p:- " << *p  << "\n";

	thread t1(process, move(p));
	t1.join();
	if(p == nullptr)
		cout << "After process Value of p:- " << (p == nullptr)  << "\n";

	return 0;
}

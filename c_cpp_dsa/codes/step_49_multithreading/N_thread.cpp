
// Start N threads in a loop, each printing its ID. Notice the garbled output, then fix it with a mutex.

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

void print_id(int id)
{
	lock_guard<mutex> lock(mtx);
	cout << "ID:-- " << id << "\n";
}

int main(int argc, char* argv[])
{
	int n = 10;
	if(argc > 1 && argc < 3)
	{
		n = atoi(argv[1]);
	}
	vector<thread> threads;

	for(int i=0;i<n;i++)
	{
		threads.emplace_back(print_id, i);
	}
	cout << "Main thread: All " << n << " threads launched!" << endl;

	for (auto& t : threads) 
	{
		if (t.joinable()) 
		{
			t.join();
		}
	}

	cout << "Main thread: All threads finished execution." << endl;

	return 0;
}

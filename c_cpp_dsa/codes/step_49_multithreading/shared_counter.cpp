
// Increment a shared counter 1M times from 4 threads. Show the race, then fix it with mutex and with atomic, and compare timings.


#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>

using namespace std;

#define max_limit 4000000;

//int shared = 0;
atomic<int> shared{0};

mutex mtx;

void p1()
{
	for(int i=1;i<=1000000;i++)
	{
		//lock_guard<mutex> lock(mtx);
		shared++;
	}
}

void p2()
{
	for(int i=1;i<=1000000;i++)
	{
		//lock_guard<mutex> lock(mtx);
		shared++;
	}
}

void p3()
{
	for(int i=1;i<=1000000;i++)
	{
		//lock_guard<mutex> lock(mtx);
		shared++;
	}
}

void p4()
{
	for(int i=1;i<=1000000;i++)
	{
		//lock_guard<mutex> lock(mtx);
		shared++;
	}
}

int main()
{

	thread t1(p1), t2(p2), t3(p3), t4(p4);
	t1.join();
	t2.join();
	t3.join();
	t4.join();


	cout << "Shared value: " << shared << endl;

	return 0;
}


/*
 *
 

#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

constexpr int THREAD_COUNT = 4;
constexpr int ITERATIONS = 1'000'000;

int raceCounter = 0;           // Unsafe shared variable
int mutexCounter = 0;          // Protected by mutex
atomic<int> atomicCounter{0};  // Thread-safe atomic variable

mutex mtx;

// 1. Race condition: no synchronization
void raceWorker()
{
    for (int i = 0; i < ITERATIONS; ++i)
    {
        ++raceCounter;  // Data race: undefined behavior
    }
}

// 2. Mutex solution
void mutexWorker()
{
    for (int i = 0; i < ITERATIONS; ++i)
    {
        lock_guard<mutex> lock(mtx);
        ++mutexCounter;
    }
}

// 3. Atomic solution
void atomicWorker()
{
    for (int i = 0; i < ITERATIONS; ++i)
    {
        atomicCounter.fetch_add(1, memory_order_relaxed);
    }
}

template <typename Function>
double measureTime(Function worker)
{
    auto start = steady_clock::now();

    vector<thread> threads;

    for (int i = 0; i < THREAD_COUNT; ++i)
    {
        threads.emplace_back(worker);
    }

    for (auto& t : threads)
    {
        t.join();
    }

    auto end = steady_clock::now();

    return duration<double, milli>(end - start).count();
}

int main()
{
    double raceTime = measureTime(raceWorker);
    double mutexTime = measureTime(mutexWorker);
    double atomicTime = measureTime(atomicWorker);

    cout << "Expected counter: "
         << THREAD_COUNT * ITERATIONS << "\n\n";

    cout << "Race counter:   " << raceCounter
         << " | Time: " << raceTime << " ms\n";

    cout << "Mutex counter:  " << mutexCounter
         << " | Time: " << mutexTime << " ms\n";

    cout << "Atomic counter: " << atomicCounter.load()
         << " | Time: " << atomicTime << " ms\n";

    return 0;
}

 *
 */

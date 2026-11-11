#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex m1, m2;

void task1() {
    m1.lock();
    this_thread::sleep_for(chrono::milliseconds(100));
    m2.lock();

    cout << "Task 1 executed\n";

    m2.unlock();
    m1.unlock();
}

void task2() {
    m2.lock();
    this_thread::sleep_for(chrono::milliseconds(100));
    m1.lock();

    cout << "Task 2 executed\n";

    m1.unlock();
    m2.unlock();
}

int main() {
    thread t1(task1);
    thread t2(task2);

    t1.join();
    t2.join();

    return 0;
}

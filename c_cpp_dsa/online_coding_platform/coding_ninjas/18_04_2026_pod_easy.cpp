/*
   Problem statement

   You have been given a queue of integers. You need to rearrange the elements of the queue by interleaving the elements of the first half of the queue with the second half.
Note :

The given queue will always be of even length.

For example :

If N= 10
and Q = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
then the output will be
Q = [10, 60, 20, 70, 30, 80, 40, 90, 50, 100]

 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

void interleaveQueue(queue<int> &q) {
    if (q.empty()) return;

    int n = q.size();
    int half = n / 2;
    stack<int> s;

    // 1. Push first half into stack: [10, 20, 30, 40, 50] -> Stack: (top) 50, 40, 30, 20, 10
    for (int i = 0; i < half; i++) {
        s.push(q.front());
        q.pop();
    }

    // 2. Enqueue stack back to queue: Queue: [60, 70, 80, 90, 100, 50, 40, 30, 20, 10]
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // 3. Move first half of queue to back: Queue: [50, 40, 30, 20, 10, 60, 70, 80, 90, 100]
    for (int i = 0; i < half; i++) {
        q.push(q.front());
        q.pop();
    }

    // 4. Push first half back to stack: Stack: (top) 10, 20, 30, 40, 50
    for (int i = 0; i < half; i++) {
        s.push(q.front());
        q.pop();
    }

    // 5. Interleave stack and queue: [10, 60, 20, 70, 30, 80, 40, 90, 50, 100]
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

int main()
{
     vector<int> v{10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
     vector<int> res, frst, scnd;
     int n = v.size();
     int temp = n;
     for(int i=0;i<n/2;i++)
     {
          frst.push_back(v[i]);
     }
     for(int i=n/2;i<n;i++)
     {
          scnd.push_back(v[i]);
     }
     
     for(int i=0;i<n/2;i++)
     {
          res.push_back(frst[i]);
          res.push_back(scnd[i]);
     }
     for(int x : res)
          cout << x << " ";
     cout << endl;
     return 0;
}

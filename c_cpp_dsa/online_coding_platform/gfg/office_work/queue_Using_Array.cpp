/*

Queue Using Array

Implement a Queue using an Array, where the size of the array, n is given.
The Queue must support the following operations:

(i) enqueue(x): Insert an element x at the rear of the queue.
(ii) dequeue(): Remove the element from the front of the queue.
(iii) getFront(): Return front element if not empty, else -1.
(iv) getRear(): Return rear element if not empty, else -1.
(v) isEmpty(): Return true if the queue is empty else return false.
(vi) isFull(): Return true if the queue is full else return false.

There will be a sequence of queries queries[][]. The queries are represented in numeric form:

    1 x : Call enqueue(x)
    2: Call dequeue()
    3: Call getFront()
    4: Call getRear()
    5: Call isEmpty()
    6: Call isFull()

You just have to implement the functions enqueue, dequeue, getFront, getRear, isEmpty and isFull and the driver code will handle the output.

Examples:

Input: n = 3, q = 7, queries[][] = [[1, 5], [1, 3], [1, 4], [3], [2], [5], [4]]
Output: [5, false, 4]
Explanation: Queries on queue are as follows:
enqueue(5): Insert 5 at the rear of the queue.
enqueue(3): Insert 3 at the rear of the queue.
enqueue(4): Insert 4 at the rear of the queue.
getFront(): Return the front element i.e 5.
dequeue(): Remove the front element 5 from the queue.
isEmpty(): Return false as the queue is not empty.
getRear(): Return the rear element i.e 4.

Input: n = 2, q = 4, queries[][] = [[4], [1, 3], [1, 7], [6]]
Output: [-1, true]
Explanation: Queries on queue are as follows:
getRear(): As the queue is empty return -1.
enqueue(3): Insert 3 at the rear of the queue.
enqueue(7): Insert 7 at the rear of the queue.
isFull(): Return true as the queue is full i.e containing 2 elements.

Constraints:
1 ≤ n ≤ 10^3
1 ≤ number of query ≤ 10^3
0 ≤ x ≤ 10^5

*/

#include <iostream>
using namespace std;

class myQueue 
{
     int front;
     int rear;
     int *arr;
     int size;

     public:
     myQueue(int n) 
     {
          size = n;
          arr = new int[n];
          front = -1;
          rear = -1;
     }

     bool isEmpty() 
     {
          return (front == -1);
     }

     bool isFull() 
     {
          return ((rear + 1) % size == front);
     }

     void enqueue(int x) 
     {
          if (isFull()) 
          {
               cout << "Queue is Full\n";
               return;
          }

          if (isEmpty()) 
          {
               front = rear = 0;
          } 
          else 
          {
               rear = (rear + 1) % size;
          }
          arr[rear] = x;
     }

     void dequeue() 
     {
          if (isEmpty()) 
          {
               cout << "Queue is Empty\n";
               return;
          }

          if (front == rear) 
          {
               front = rear = -1;
          } 
          else 
          {
               front = (front + 1) % size;
          }
     }

     int getFront() 
     {
          if (isEmpty())
               return -1;
          return arr[front];
     }

     int getRear() 
     {
          if (isEmpty())
               return -1;
          return arr[rear];
     }

     ~myQueue() 
     {
          delete[] arr;
     }
};

int main() 
{
     myQueue q(5);

     q.enqueue(10);
     q.enqueue(20);
     q.enqueue(30);

     cout << "Front: " << q.getFront() << endl;
     cout << "Rear : " << q.getRear() << endl;

     q.dequeue();

     cout << "\nAfter one dequeue:\n";
     cout << "Front: " << q.getFront() << endl;
     cout << "Rear : " << q.getRear() << endl;

     q.enqueue(40);
     q.enqueue(50);
     q.enqueue(60);

     cout << "\nAfter more enqueues:\n";
     cout << "Front: " << q.getFront() << endl;
     cout << "Rear : " << q.getRear() << endl;

     q.enqueue(70);   // Queue Full

     while (!q.isEmpty()) 
     {
          cout << "Removing " << q.getFront() << endl;
          q.dequeue();
     }

     cout << "\nQueue Empty\n";
     cout << "Front: " << q.getFront() << endl;
     cout << "Rear : " << q.getRear() << endl;

     return 0;
}

/*
   Problem statement

   You are given a stack/deque of integers 'MY-STACK' and an integer ‘X’. Your task is to insert ‘X’ to the bottom of ‘MY-STACK’ and return the updated stack/deque.
Note :

If ‘MY_STACK’ = [7, 1, 4, 5], then the first element represents the element at the bottom of the stack and the last element represents the element at the top of the stack.

For Example :

Let ‘MY_STACK’ = [7, 1, 4, 5] and ‘X’ = 9. So, ‘MY_STACK’ after insertion becomes [9, 7, 1, 4, 5].

 */
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
     // Write your code here.
     vector<int> temp;
     stack<int> res;
     //res.push(x);
     while(!myStack.empty())
     {
          temp.push_back(myStack.top());
          myStack.pop();
     }
     res.push(x);
     if(!temp.empty())
          reverse(temp.begin(), temp.end());
     for(int x : temp)
     {
          res.push(x);
     }
     return res;
}

int main()
{
     vector<int> v{7, 1, 4, 5};
     int x = 9;
     stack<int> st;
     stack<int> out;

     for(int y : v)
     {
          //cout << y << " "; 
          st.push(y);
     }

     out = pushAtBottom(st, x);
     while(!out.empty())
     {
          cout << out.top() << " ";
          out.pop();
     }
     return 0;
}

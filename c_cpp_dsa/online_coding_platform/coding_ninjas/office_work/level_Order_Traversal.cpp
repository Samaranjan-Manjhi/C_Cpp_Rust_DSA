/*

   Level Order Traversal

   Problem statement

   You have been given a Binary Tree of integers. You are supposed to return the level order traversal of the given tree.
   For example:

   The level order traversal will be {1,2,3,4,5,6,7}.

Constraints:

1 <= T <= 100
0 <= N <= 1000
0 <= data <= 10^6 and data != -1
Where ‘T’ is the number of test cases, and ‘N’ is the total number of nodes in the binary tree, and “data” is the value of the binary tree node.
Time Limit: 1sec

Sample Input 1:
3
1 2 3 4 -1 5 6 -1 7 -1 -1 -1 -1 -1 -1
1 2 3 -1 -1 -1 -1
1 3 -1 2 -1 -1 -1
Sample Output 1:
1 2 3 4 5 6 7
1 2 3
1 3 2

Explanation of Sample Input 1:

For the first test case, {1} is at level 1 and {2,3} are at level 2 and {4,5,6} are at level 3 and {7} is at level 4. So combinations of all levels are {1, 2, 3 ,4, 5, 6, 7}.
For the second test case, {1} is at level 1 and {2,3} are at level 2. So combinations of level are {1, 2, 3}.
For the third test case, {1} is at level 1 and {3} is at level 2 and {2} is at level 3. So combinations of all levels are {1,3,2}.

Sample Input 2:
2
2 7 5 2 6 -1 9 -1 -1 5 11 4 -1 -1 -1 -1 -1 -1 -1
1 2 3 4 -1 5 6 -1 -1 -1 -1 -1 -1  
Sample Output 2:
2 7 5 2 6 9 5 11 4
1 2 3 4 5 6

Explanation of Sample Input 2:

For the first test case, {2} is at level 1 and {7,5} are at level 2 and {2,6,9} are at level 3 and {5,11,4} are at level 4. So combinations of all levels are {2, 7, 5, 2, 6, 9, 5, 11, 4}.
For the second test case, {1} is at level 1 and {2,3} are at level 2 and {4,5,6} are at level 3. So combinations of all levels are {1, 2, 3, 4, 5, 6}.

 */


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template <typename T>
class BinaryTreeNode 
{
     public:
          T val;
          BinaryTreeNode<T>* left;
          BinaryTreeNode<T>* right;

          BinaryTreeNode(T val) 
{
               this->val = val;
               left = NULL;
               right = NULL;
          }
};

vector<int> getLevelOrder(BinaryTreeNode<int>* root)
{
     if(root == NULL)
          return {};

     queue<BinaryTreeNode<int>*> q;
     vector<int> res;

     q.push(root);

     while(!q.empty())
     {
          BinaryTreeNode<int>* temp = q.front();
          q.pop();

          res.push_back(temp->val);

          if(temp->left != NULL)
               q.push(temp->left);

          if(temp->right != NULL)
               q.push(temp->right);
     }

     return res;
}


BinaryTreeNode<int>* buildTree()
{
     int val;
     cin >> val;

     if(val == -1)
          return NULL;

     BinaryTreeNode<int>* root = new BinaryTreeNode<int>(val);

     queue<BinaryTreeNode<int>*> q;
     q.push(root);

     while(!q.empty())
     {
          BinaryTreeNode<int>* curr = q.front();
          q.pop();

          int leftVal, rightVal;

          cin >> leftVal;
          cin >> rightVal;

          if(leftVal != -1)
          {
               curr->left = new BinaryTreeNode<int>(leftVal);
               q.push(curr->left);
          }

          if(rightVal != -1)
          {
               curr->right = new BinaryTreeNode<int>(rightVal);
               q.push(curr->right);
          }
     }

     return root;
}


int main()
{
     BinaryTreeNode<int>* root = buildTree();

     vector<int> ans = getLevelOrder(root);

     for(int x : ans)
          cout << x << " ";
     cout << endl;

     return 0;
}

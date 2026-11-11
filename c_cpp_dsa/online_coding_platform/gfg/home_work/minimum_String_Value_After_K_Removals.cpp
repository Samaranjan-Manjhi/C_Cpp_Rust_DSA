/*

   Minimum String Value After K Removals

   Given a string of lowercase alphabets and a number k, the task is to find the minimum value of the string after removal of ‘k’ characters. The value of a string is defined as the sum of squares of the count of each distinct character.
   For example, consider the string “geeks”, here frequencies of characters are g -> 1, e -> 2, k -> 1, s -> 1 and value of the string is 12 + 22 + 12 + 12 = 7

Examples:

Input: s = "abccc", k = 1
Output: 6
Explanation: Remove one 'c', then frequencies become a -> 1, b -> 1, c -> 2 and the value becomes 12 + 12 + 22 = 6

Input: s = "aaab", k = 2
Output: 2
Explanation: Remove 2 'a's, then frequencies become a -> 1, b -> 1 and value becomes 12 + 12 = 2

Constraints:
1 ≤ k , |s| ≤ 104

 */


#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

int minValue(string &s, int k) 
{
     // code here
     // Step 1: Count character frequencies
     unordered_map<char, int> freq;
     for (char c : s) 
     {
          freq[c]++;
     }

     // Step 2: Push all frequencies into a Max-Heap
     priority_queue<int> maxHeap;
     for (auto &pair : freq) 
     {
          maxHeap.push(pair.second);
     }

     // Step 3: Reduce highest frequency k times
     while (k > 0 && !maxHeap.empty()) 
     {
          int top = maxHeap.top();
          maxHeap.pop();

          top--; // Remove one instance of the most frequent character
          if (top > 0) 
          {
               maxHeap.push(top);
          }
          k--;
     }

     // Step 4: Calculate the sum of squares of remaining frequencies
     int ans = 0;
     while (!maxHeap.empty()) 
     {
          int count = maxHeap.top();
          maxHeap.pop();
          ans += count * count;
     }

     return ans;
}

int main() 
{
     string s;
     int k;

     cout << "Enter string: ";
     cin >> s;

     cout << "Enter value of k: ";
     cin >> k;

     int result = minValue(s, k);

     cout << "Minimum value: " << result << endl;

     return 0;
}

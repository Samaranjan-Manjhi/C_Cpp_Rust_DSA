/*

   Maximum Reachable Index Difference

   Given a string s containing lowercase English alphabets.

   Start from any index containing the character 'a' and perform jump operations.
   In each jump operation, move to any index on the right side whose character is the immediate next letter of the current character in the alphabet (i.e., 'a' to 'b', 'b' to 'c', 'c' to 'd', and so on). 
   Continue performing jumps until no further jump is possible.
   Find the maximum possible difference between the starting index and the ending index. If it is not possible to choose a starting index, return -1.

Examples :

Input: s = "aaabcb"
Output: 5
Explanation: Start at index 0 ('a'), jump to index 5 ('b'). Difference = 5 - 0 = 5.

Input: s = "xynjir"
Output: -1
Explanation: The string does not contain any character 'a'. So, the answer is -1.

Input: s = "abcbzzd"
Output: 6
Explanation: Start from index 0 ('a'). Jump to index 1 ('b') because 'b' is the next alphabet character. Jump to index 2 ('c') because 'c' is the next character after 'b'. Jump to index 6 ('d') because 'd' is the next character after 'c'.

Constraints:
1 ≤ s.size() ≤ 10^5

 */


#include <iostream>
#include <vector>
#include <string>

using namespace std;

int maxIndexDifference(string &s) 
{
     // code here
     int n = s.length();
     vector<int> arr(26, -1);
     int max_diff = -1;
     for(int i=n-1;i>=0;i--)
     {
          char cur_ch = s[i];
          int cur_idx = cur_ch - 'a';

          int best_end = i;

          if(cur_ch != 'z')
          {
               int next_idx = cur_idx + 1;
               if(arr[next_idx] != -1)
                    best_end = arr[next_idx];
          }

          arr[cur_idx] = max(arr[cur_idx], best_end);

          if(cur_ch == 'a')
               max_diff = max(max_diff, best_end-i);
     }

     return max_diff;
}

int main()
{
     string s;
     cout << "Enter Input String: ";
     cin >> s;

     int res = maxIndexDifference(s);
     cout << "    Result:-  " << res << endl;

     return 0;
}

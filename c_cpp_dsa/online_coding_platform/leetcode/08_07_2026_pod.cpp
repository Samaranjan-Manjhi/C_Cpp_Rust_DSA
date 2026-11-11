/*

   3756. Concatenate Non-Zero Digits and Multiply by Sum II

   You are given a string s of length m consisting of digits. You are also given a 2D integer array queries, where queries[i] = [li, ri].
   For each queries[i], extract the
   s[li..ri]. Then, perform the following:
   Form a new integer x by concatenating all the non-zero digits from the substring in their original order. If there are no non-zero digits, x = 0.
   Let sum be the sum of digits in x. The answer is x * sum.
   Return an array of integers answer where answer[i] is the answer to the ith query.
   Since the answers may be very large, return them modulo 109 + 7.

   Example 1:
Input: s = "10203004", queries = [[0,7],[1,3],[4,6]]
Output: [12340, 4, 9]

Explanation:
s[0..7] = "10203004"
x = 1234
sum = 1 + 2 + 3 + 4 = 10
Therefore, answer is 1234 * 10 = 12340.
s[1..3] = "020"
x = 2
sum = 2
Therefore, the answer is 2 * 2 = 4.
s[4..6] = "300"
x = 3
sum = 3
Therefore, the answer is 3 * 3 = 9.

Example 2:
Input: s = "1000", queries = [[0,3],[1,1]]
Output: [1, 0]

Explanation:
s[0..3] = "1000"
x = 1
sum = 1
Therefore, the answer is 1 * 1 = 1.
s[1..1] = "0"
x = 0
sum = 0
Therefore, the answer is 0 * 0 = 0.

Example 3:
Input: s = "9876543210", queries = [[0,9]]
Output: [444444137]

Explanation:
s[0..9] = "9876543210"
x = 987654321
sum = 9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1 = 45
Therefore, the answer is 987654321 * 45 = 44444444445.
We return 44444444445 modulo (109 + 7) = 444444137.

Constraints:
1 <= m == s.length <= 10^5
s consists of digits only.
1 <= queries.length <= 10^5
queries[i] = [li, ri]
0 <= li <= ri < m

 */


#include <iostream>
#include <vector>

using namespace std;

/*
const int mod = 1e9+7;
 // TLE
   vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) 
   {
   int n = queries.size();
   int m = s.length();
   vector<int> res;
   for (int i = 0; i < n; i++) 
   {
   int left = queries[i][0];
//cout << "left:- " << left << endl;
int right = queries[i][1];
//cout << "right:- " << right << endl;
long long sum = 0;
long long num = 0;
if (left < 0)
left = 0;
if (right >= m)
right = m - 1;
string digit = "";
for (int j = left; j <= right; j++) 
{
if (s[j] != '0') 
{
//digit += s[j];
num = (num * 10 + (s[j] - '0')) % mod;
sum += s[j] - '0';
}
}

//cout << "sum:- " << sum << endl;
//cout << "digit: " << digit << endl;
//if(!digit.empty())
//    num = stoll(digit);
//else
//    num = 0;
num = (num + mod) % mod;
//cout << "mod num:- " << num << endl;
sum = (sum + mod) % mod;
//cout << "mod sum:- " << sum << endl;
long long temp = (1LL * num * sum) % mod;
res.push_back((int)temp);
}

return res;
}
 */

static constexpr int MOD = 1000000007;

vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) 
{
     int n = s.size();
     // pow10[i] = 10^i % MOD
     vector<long long> pow10(n + 1, 1);
     for (int i = 1; i <= n; i++)
          pow10[i] = (pow10[i - 1] * 10) % MOD;
     // prefix sum of digits
     vector<int> prefSum(n + 1, 0);
     // cnt[i] = number of non-zero digits in s[0..i-1]
     vector<int> cnt(n + 1, 0);
     // val[k] = number formed by first k non-zero digits
     vector<long long> val(1, 0);
     for (int i = 0; i < n; i++) 
     {
          prefSum[i + 1] = prefSum[i] + (s[i] - '0');
          cnt[i + 1] = cnt[i];
          if (s[i] != '0') 
          {
               cnt[i + 1]++;
               long long x = (val.back() * 10 + (s[i] - '0')) % MOD;
               val.push_back(x);
          }
     }

     vector<int> ans;

     for (auto &q : queries) 
     {
          int l = q[0];
          int r = q[1];

          // sum of digits
          long long sum = prefSum[r + 1] - prefSum[l];

          // number of non-zero digits before l
          int a = cnt[l];

          // number of non-zero digits up to r
          int b = cnt[r + 1];

          long long x;

          if (a == b) 
          {
               x = 0;
          } 
          else 
          {
               x = (val[b] - val[a] * pow10[b - a]) % MOD;
               if (x < 0)
                    x += MOD;
          }

          ans.push_back((x * (sum % MOD)) % MOD);
     }

     return ans;
}

int main()
{
     string s = "10203004";
     vector<vector<int>> v{{0, 7}, {1, 3}, {4, 6}};

     vector<int> res = sumAndMultiply(s, v);
     for(int x : res)
          cout << x << " ";
     cout << endl;

     return 0;
}

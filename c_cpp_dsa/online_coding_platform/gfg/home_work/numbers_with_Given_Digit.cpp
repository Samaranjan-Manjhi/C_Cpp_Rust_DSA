/*

Numbers with Given Digit

Given two integers n and d. Return an array containing all the numbers between 0 to n that contain the specific digit d.

Examples:

Input: n = 20, d = 5
Output: [5, 15]
Explanation: For number till 20, 5 appears in 5 itself and 15.

Input: n = 50, d = 2
Output: [2, 12, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 32, 42]
Explanation: For number till 50, 2 appears in all these numbers.

Constraints:
0 ≤ n ≤ 103
0 ≤ d ≤ 9

*/


#include <iostream>
#include <vector>
using namespace std;

vector<int> findNumbers(int n, int d) {
    // code here
    return {};
}

int main() {
    int n, d;

    cout << "Enter value of n: ";
    cin >> n;

    cout << "Enter digit d: ";
    cin >> d;

    vector<int> result = findNumbers(n, d);

    cout << "Numbers found: ";
    for (int num : result) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}

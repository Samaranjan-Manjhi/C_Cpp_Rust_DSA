#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingSort(vector<int>& arr, int exp)
{
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};
    // Count occurrences of each digit
    for (int i = 0; i < n; i++)
    {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }
    // Convert counts into cumulative positions
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    // Build output array from right to left
    // This keeps the sorting stable
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }
    // Copy sorted values back
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void radixSort(vector<int>& arr)
{
    if (arr.empty()) return;
    int maxVal = *max_element(arr.begin(), arr.end());
    // Process ones, tens, hundreds, ...
    for (int exp = 1; maxVal / exp > 0; )
    {
        countingSort(arr, exp);
        // Prevent exp *= 10 from overflowing
        if (exp > maxVal / 10) break;
        exp *= 10;
    }
}

int main()
{
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    radixSort(arr);

    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}

/*
   Find factorial of N using a loop (iterative)
   Asked at: TCS, Infosys, Cognizant
 */
#include <iostream>
using namespace std;
int main()
{
     int n;
     cout << "Enter Number: ";
     cin >> n;
     long long int fact = 1;
     for(int i=n;i>=1;i--)
     {
          fact *= i;
     }
     cout << "Factorial of " << n << " = " << fact << endl;
     return 0;
}

/*
#include <iostream>
#include <vector>
using namespace std;

void multiply(vector<int> &res, int x) {
    int carry = 0;
    for (size_t i = 0; i < res.size(); i++) {
        int prod = res[i] * x + carry;
        res[i] = prod % 10;      // store last digit
        carry = prod / 10;       // remaining carry
    }
    while(carry) {               // push remaining carry digits
        res.push_back(carry % 10);
        carry /= 10;
    }
}

void factorial(int n) {
    vector<int> res;
    res.push_back(1); // initialize factorial = 1

    for(int i = 2; i <= n; i++) {
        multiply(res, i);
    }

    // print in reverse order
    for(int i = res.size() - 1; i >= 0; i--)
        cout << res[i];
    cout << endl;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if(n < 0) {
        cout << "Factorial not defined for negative numbers.\n";
    } else {
        cout << n << "! = ";
        factorial(n);
    }

    return 0;
}
*/

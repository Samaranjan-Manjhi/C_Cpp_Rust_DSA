#include <iostream>
using namespace std;

int main()
{
	int x = 10;
	int*          p1  = &x;
	int**         p2  = &p1;
	int***        p3  = &p2;
	int****       p4  = &p3;
	int*****      p5  = &p4;
	int******     p6  = &p5;
	int*******    p7  = &p6;
	int********   p8  = &p7;
	int*********  p9  = &p8;
	int********** p10 = &p9;

	cout << p10 << endl;                    // Q1   // A of p9
	cout << *p10 << endl;                   // Q2   // A of p8
	cout << ****p10 << endl;                // Q3   // A of p5
	cout << *********p10 << endl;           // Q4   // A of x
	cout << **********p10 << endl;          // Q5   // 10
	cout << &p7 << endl;                    // Q6   // A of p7
	cout << p5 << endl;                     // Q7   // A of p4
	cout << ***p8 << endl;                  // Q8   // A of p4
	cout << ********p9 << endl;             // Q9   // A of x
	cout << (&p3 == p4) << endl;            // Q10  // 1 true
	cout << (***p6 == p3) << endl;          // Q11  // 1 true
	cout << (*p10 == &p8) << endl;          // Q12  // 1 true
	cout << *&*&p4 << endl;                 // Q13  // A of p4 // Wrong p4 holds & of p3
	return 0;
}

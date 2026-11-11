#include <iostream>
using namespace std;

int main()
{
	int x = 10, y = 20;
	int&           rx = x;
	int*           p1 = &rx;
	int*&          r1 = p1;
	int**          p2 = &r1;
	int**&         r2 = p2;
	int***         p3 = &r2;
	int***&        r3 = p3;
	int****        p4 = &r3;
	int****&       r4 = p4;
	int*****       p5 = &r4;
	int*****&      r5 = p5;
	int******      p6 = &r5;
	int******&     r6 = p6;
	int*******     p7 = &r6;
	int*******&    r7 = p7;
	int********    p8 = &r7;
	int********&   r8 = p8;
	int*********   p9 = &r8;
	int*********&  r9 = p9;
	int********** p10 = &r9;

	// Part 1: before any assignment
	cout << (&rx == &x) << endl;            // Q14   // 1
	cout << (*p10 == r9) << endl;           // Q15   // 0
	cout << **********p10 << endl;          // Q16   // 10
	cout << *********p10 << endl;           // Q17   // A of rx
	cout << ****r7 << endl;                 // Q18   // A of p3
	cout << (&r9 == &p9) << endl;           // Q19   // 0
	cout << (*r4 == p3) << endl;            // Q20   // 
	cout << *****r5 << endl;                // Q21
	cout << (**p3 == p1) << endl;           // Q22
	cout << &*p10 << endl;                  // Q23
	cout << ***p10 << endl;                 // Q24

	// Part 2: assignments
	rx = y;
	*****r5 = 30;
	r1 = &y;
	**********p10 = 40;

	cout << x << " " << y << endl;          // Q25
	cout << *p1 << endl;                    // Q26
	cout << (p1 == &x) << endl;             // Q27
	cout << (*********p10 == &y) << endl;   // Q28
	cout << rx << endl;                     // Q29
	cout << (**********p10 == y) << endl;   // Q30
	cout << (*r1 == y) << endl;             // Q31
	return 0;
}

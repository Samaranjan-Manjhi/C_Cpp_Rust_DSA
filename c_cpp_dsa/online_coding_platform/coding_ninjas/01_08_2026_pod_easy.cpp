/*

   Alex And Infinity Circle

   Problem statement
   Alex wanted to buy a new keyboard, but due to the low battery in his GPS, he had to print his route on paper, now he wants to know if he can return safely to his home following the instructions written by him. The city of Alex can be represented by a 2D plane, and every location is denoted by ('X','Y') coordinates. Alex is currently standing at ( 0, 0 ) facing north.

   The printed route contains a string with characters like:

   'L' : which denotes he should turn to the left of the direction he is facing.
   'R' : which denotes he should turn to the right of the direction he is facing.
   'G' : which denotes he should walk in the same direction by one unit.
   Determine whether he can return home safely or not by following his instruction on the printed sheet.

Note:
He can follow the same printed set of instructions as many times as wanted.

Constraints:
1 <= T <= 50
1 <= N <= 100
‘STR’ = {‘L’, ‘R’ and ‘G’}.

Where ‘T’ is the number of test cases, 'N' is the length of string ‘STR’  and ‘STR’ is the string that denotes the direction that Alex should move. 
Time limit: 1 sec

Sample Input 1:
2
6
GGRRGG
2
GGG
Sample Output 1:
True
False
Explanation of sample input 1:
In the first test case, Alex follows the following instructions, he will go from (0,0) -> (0,1) -> (0,2) -> turned towards east -> turned towards south -> (0,1) -> (0,0).
In the second test case, he will always go towards the right, hence it is impossible for him to return home.

Sample Input 2:
2
2
LR
2
GL
Sample Output 2:
True
True
Explanation of sample input 2:
In the first test case, he is in the same position just turning in his direction.
In the second test case, he will go from (0,0) -> (0,1) -> (turned left) -> (-1,1) -> (turned left) ->(-1,0) ->(turned left) -> (0,0)

*/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

string isPossible(string str,int n)
{
	//	Write your code here.
	int x = 0;
	int y = 0;
	// North = 0, East = 1, South = 2, West = 3
	vector<int> dx = {0, 1, 0, -1};
	vector<int> dy = {1, 0, -1, 0};
	int curr_dir = 0;
	for(char c : str)
	{
		if(c == 'L')
			curr_dir = (curr_dir + 3)%4;
		else if(c == 'R')
			curr_dir = (curr_dir + 1)%4;
		else if(c == 'G')
		{
			x = x + dx[curr_dir];
			y = y + dy[curr_dir];
		}
	}

	if((x == 0 && y == 0) || (curr_dir != 0))
		return "True";

	return "False";
}

int main()
{
	string str;
	cout << "Enter Input String: ";
	cin >> str;

	string res = isPossible(str, str.length());
	cout << "    Result:-  " << res << endl;

	return 0;
}

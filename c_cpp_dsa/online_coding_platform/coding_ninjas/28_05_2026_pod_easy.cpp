/*

   Problem statement

   Ninja is an avid story lover. Today, he decides to go to the famous Storyteller of Ninjaland to listen to new stories. The Storyteller takes 'Y' coins to tell one story. The Storyteller has also put on a special offer for Ninja that for every 'X' story that the Storyteller tells to Ninja, the Storyteller will tell one story to Ninja free of cost, i.e., without taking any extra coins. Ninja currently has 'Z' coins with himself. He wants to know how many stories the Storyteller will tell him if he goes to the Storyteller with 'Z' coins.

Constraints:
1 <= T <= 10 ^ 4
2 <= X <= 10 ^ 9
1 <= Y , Z <= 10 ^ 9

Where 'T' denotes the number of test cases, 'X' denotes the number of stories that Ninja needs to listen to get one free story, 'Y' denotes the number of coins the Storyteller takes to tell one story, and 'Z'  denotes the number of coins that Ninja has.

Time Limit: 1 sec.
Sample Input 1:
2
2 2 4
3 3 3
Sample Output 1:
3
1

Explanation for Sample Input 1:
For the first test case :  
The ninja will use the 4 coins that he has to listen to 2 stories. After listening to the two stories, the Storyteller will tell Ninja a free story. Hence, the answer is 3 in this case.
For the second test case : 
The ninja will give 3 coins to the Storyteller to listen to one story. Hence, the answer is 1 in this case.

Sample Input 2:
2
2 1 4
2 3 2
Sample Output 2:
7
0

 */


#include <iostream>
using namespace std;

int countStories(int x, int y, int z)
{ 
     // Write your code here
     int p = z/y;
     int res = (p + ((p - 1) /(x - 1)));
     if (res >= 0)
          return res;

     return 0;
}

int main()
{
     int a, b, c;
     cout << "Enter story to get free: ";
     cin >> a;
     cout << "Enter cost of 1 story: ";
     cin >> b;
     cout << "Total coin ninja has: ";
     cin >> c;

     int res = countStories(a, b, c);
     cout << "Result:--    " << res << endl;

     return 0;
}

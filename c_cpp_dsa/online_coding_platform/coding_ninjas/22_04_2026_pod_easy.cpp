/*
   Problem statement

   You’re given a slot machine with four slots where each slot will contain the color Red(R), Yellow(Y), Green(G), Blue(B), respectively. You don’t know the colors of this slot beforehand. You have to guess the colors. When you guess the correct color for the correct slot, you get a perfect hit, and you get 2 points, but if you guess a color that exists in the machine but is in the wrong slot, you get a pseudo hit, and you get 1 point.

   You’re given the original string representing the slots’ colors and the guess string, and your task is to calculate and return the total number of points you have scored.

Note:

A slot that has been counted as a perfect hit can never count as a pseudo-hit.

Example:

Original String = “RGYB” and Guess String = “YGRR”.

The second slot of both the guess and original matches, hence it’s a perfect hit. The guess string contains yellow, which is also present in the original string but not at the same slot as the guess slot. Hence it’s a pseudo hit. The guess string also contains two red slots, but the original string contains only one red which is also not at the same slot as the guess string; hence it is also a pseudo hit. Therefore total points will be 2+1+1= 4.

Constraints:

1 <= T <= 5
length(original) = length(guess) = 4

Time limit: 1 sec

Sample Input 1
1
RGBY GGRR

Sample Output 1:
3

Sample Input 2:

1
RGYB YGRR

Sample Output 2:

4

 */

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int slotScore(string &original, string &guess)
{
     // Write your code here.
     int n = original.size();
     int per = 0, pse = 0;
     vector<int> freq(256, 0);
     for(int i=0;i<n;i++)
     {
          if(original[i] == guess[i])
          {
               per++;
          }
          else
          {
               freq[original[i]]++;
          }
     } 

     for(int i=0;i<n;i++)
     {
          if(original[i] != guess[i] && freq[guess[i]] > 0)
          {
               pse++;
               freq[guess[i]]--;
          }
     }
     return per*2+pse;
}

int main()
{
     string org, gu;
     cout << "Enter 2 String: ";
     cin >> org >> gu;
     cout << "Result: " << slotScore(org, gu) << endl;
     return 0;
}


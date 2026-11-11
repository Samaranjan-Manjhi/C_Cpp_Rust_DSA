/*

   Check Palindrome

   Problem statement

   You're given an alphabetical string ‘S’.
   Determine whether it is palindrome or not. A palindrome is a string that is equal to itself upon reversing it.

   For example:

   ‘S’ = racecar
   The reverse of ‘S’ is: racecar
   Since ‘S’ is equal to its reverse. So ‘S’ is a palindrome.
   Hence output will be 1.

   Sample Input 1 :
   2
   racecar
   niinja
   Sample Output 1 :
   1
   0

   Explanation For Sample Input 1 :

   For First Case - Same as explained in above example.

   For the second case -
   ‘S’ = niinja
   Reverse of ‘S’ is: ajniin
   Since ‘S’ is not equal to its reverse. So ‘S’ is not a palindrome.
   Hence output will be 0.

   Sample Input 2 :
   2
   level
   panama
   Sample Output 2 :
   1
   0

 */


#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string &s)
{
     // Write your code here.
     int l = 0, r = s.length()-1;
     while(l < r)
     {
          if(s[l] != s[r])
               return false;

          l++;
          r--;
     }
     return true;
}

int main()
{
     string s;
     cout << "Enter Input String: ";
     getline(cin, s);

     bool res = isPalindrome(s);
     if(res)
          cout << "    Result:-    Yes\n";
     else
          cout << "    Result:-    Nope\n";

     return 0;
}

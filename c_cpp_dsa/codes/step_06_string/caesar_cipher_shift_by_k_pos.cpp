/*

   Caesar cipher: shift characters by K positions in alphabet.
   Wrap around: 'z' + 1 = 'a'.
   Asked at: TCS, Capgemini, Zoho

 */

#include <iostream>
#include <string>

using namespace std;

char Caeser_Ciper_by_k_pos(char ch, int k)
{
     bool isCap = false;
     char ans ;
     int newChar;
     if(ch >= 97 && ch <= 122)
          newChar = ch;
     else if(ch >= 65 && ch <= 90)
     {
          isCap = true;
          newChar = ch+32;
     }
     int temp = newChar - 'a' + k;
     temp = ((temp%26 + 26)%26);
     ans = temp + 'a';
     if(isCap)
          return ans-32;
     return ans;
}

int main()
{
     char ch;
     cout << "Enter Input Alphabet: ";
     cin >> ch;

     int k;
     cout << "Enter Value to shift Alphabet: ";
     cin >> k;

     char res = Caeser_Ciper_by_k_pos(ch, k);
     cout << "Result:- " << res << endl;

     return 0;
}

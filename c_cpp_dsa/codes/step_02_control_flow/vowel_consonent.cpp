/*
   Check if a character is vowel or consonant using switch
   Asked at: TCS, Wipro, Infosys
 */
#include <iostream>
using namespace std;
int main()
{
     char ch;
     cout << "Enter a character: ";
     cin >> ch;
     if(ch >= 'A' && ch <= 'Z')
          ch = ch + ('a' - 'A');
     switch(ch)
     {
          case 'a':
          case 'e':
          case 'i':
          case 'o':
          case 'u':
               cout << ch << " is Vowel.\n";
               break;
          default:
               if(ch >= 'a' && ch <= 'z')
                    cout << ch << " is Consonant.\n";
               else
                    cout << ch << " is not a alphabet character.\n";
     }
     return 0;
}

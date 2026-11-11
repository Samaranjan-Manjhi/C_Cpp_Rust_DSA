/*

   Read a full sentence using getline and print each word on a new line.
   Demonstrate cin vs getline difference.
   Asked at: TCS, Wipro, Infosys

 */

#include <iostream>
#include <string>

using namespace std;

void print_words_on_new_line(const string& s)
{
     string word = "";
     for(char ch : s)
     {
          if(ch != ' ')
          {
               word += ch;
          }
          else
          {
               cout << word << endl;
               word = "";
          }
     }
     cout << word << endl;
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     getline(cin, str);

     print_words_on_new_line(str);

     return 0;
}

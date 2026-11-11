/*

   Count words in a sentence.
   Handle multiple consecutive spaces.
   Asked at: Wipro, Capgemini, Zoho

 */


#include <iostream>
#include <string>

using namespace std;

int count_words_in_sentense(string& s)
{
     int cnt = 0;
     if(s.length() == 0)
          return cnt;

     bool isWord = false;
     for(char ch : s)
     {
          if(ch != ' ')
          {
               if(!isWord)
               {
                    cnt++;
                    isWord = true;
               }
          }
          else
          {
               isWord = false;
          }
     }

     return cnt;
}

int main()
{
     string str;
     cout << "Enter Input String: ";
     getline(cin, str);

     int wordsCount = count_words_in_sentense(str);
     cout << "Result:- " << wordsCount << endl;

     return 0;
}

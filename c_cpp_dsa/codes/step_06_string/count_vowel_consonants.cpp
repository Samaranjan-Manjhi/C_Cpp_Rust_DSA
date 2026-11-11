/*

   Count vowels and consonants in a string.
   Asked at: TCS, Wipro, Capgemini

 */


#include <iostream>
#include <string>

using namespace std;

pair<int, int> get_count_of_Vowels_consonants(string& str)
{
     if(str.length() == 0)
          return {0, 0};

     int vowelsCnt = 0, consonantsCnt = 0;
     for(char ch : str)
     {
          if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
               vowelsCnt++;
          else if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
               consonantsCnt++;
     }
     return {vowelsCnt, consonantsCnt};
}

int main()
{
     string s;
     cout << "Enter String: ";
     getline(cin, s);

     pair<int, int> res = get_count_of_Vowels_consonants(s);
     cout << "Vowels Count:- " << res.first << endl;
     cout << "Consonants Count:- " << res.second << endl;

     return 0;
}

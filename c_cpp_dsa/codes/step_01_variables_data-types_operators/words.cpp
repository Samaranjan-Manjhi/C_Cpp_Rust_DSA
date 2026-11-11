/*
   Read a full sentence using getline and print it reversed word by word
   Asked at: TCS, Wipro
 */
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
int main()
{
     string str;
     cout << "Enter any sentence: ";
     getline(cin, str);
     vector<string> words;
     stringstream ss(str);
     string word;
     while(ss >> word)
          words.push_back(word);
     cout << "Entered Sentence in reverse order:- ";
     for(int i=words.size()-1;i>=0;i--)
          cout << words[i] << " ";
     cout << endl;
     return 0;
}

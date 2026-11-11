/*

   Any Common Word in Two Lists

   Given the menu of the two restaurants. There may be a chance of fight between them if any one of them have any item in common and you surely don't want that to happen. Each of the menu has 5 items (strings) in them. So, your task is to find out if there is any need to change the menu or let them be happy with their respective menu.

   Example 1:
Input:
cake pastry fish candy meat
burger ham fish cake sauce
Output:
CHANGE
Explanation:
"fish" is common in both the menu.

Example 2:
Input:
pizza chicken cake chilli candy
choco coco cabbage panner cheese
Output:
BEHAPPY
Expanation:
No item is common.

Your Task:
You don't need to read or print anything. Your task is to complete the function is_common() which takes first menu as first parameter and second menu as second parameter and returns the string "CHANGE" if any item is common otherwise returns "BEHAPPY"(Without quotes).

Expected Time Complexity:   O(n)
Expected Space Complexity: O(n)

Constraints:
1 <= Size of each string <= 1000

 */


#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

string is_common(vector<string>& s, vector<string>& t) 
{
     // Code here
     unordered_set<string> seen(t.begin(), t.end());
     for(string s1 : s)
     {
          if(seen.find(s1) != seen.end())
               return "CHANGE";
     }

     return "BEHAPPY";
}

int main()
{
     int n;
     cout << "Enter Vector Size: ";
     cin >> n;
     vector<string> s(n);
     for(int i=0;i<n;i++)
          cin >> s[i];

     vector<string> t(n);
     for(int i=0;i<n;i++)
          cin >> t[i];

     string res = is_common(s, t);
     cout << "    Result:- " << res << endl;

     return 0;
}

#include <iostream>
#include <cstring>

using namespace std;


bool isDone(string str, string s)
{
	int n = str.length();
	int m = s.length();
	int i = 0, j = 0;
	while(i < m && j < n)
	{
		if(s[i] == str[j])
		{
			i++;
		}
		else
			j++;

	}

	return i == m;
}

int main()
{
	string s1 = "afgkgfbhjhhc";
	string s2 = "abc";

	bool res = isDone(s1, s2);
	cout << "Res: " << res << endl;

	return 0;
}

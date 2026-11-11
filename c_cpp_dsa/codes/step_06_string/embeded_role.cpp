/*

   Implement strlen, strcpy, strcat, strcmp from scratch
   (without using <cstring> library functions).
   Asked at: TCS, Wipro, Samsung, Sasken, embedded roles

 */

#include <iostream>
using namespace std;

// 1. strlen
int myStrlen(const char *s)
{
     int len = 0;
     while (s[len] != '\0')
     {
          len++;
     }
     return len;
}

// 2. strcpy
char* myStrcpy(char *dest, const char *src)
{
     int i = 0;
     while (src[i] != '\0')
     {
          dest[i] = src[i];
          i++;
     }
     dest[i] = '\0';
     return dest;
}

// 3. strcat
char* myStrcat(char *dest, const char *src)
{
     int i = 0;

     // move to end of dest
     while (dest[i] != '\0')
     {
          i++;
     }

     int j = 0;
     while (src[j] != '\0')
     {
          dest[i + j] = src[j];
          j++;
     }

     dest[i + j] = '\0';
     return dest;
}

// 4. strcmp
int myStrcmp(const char *s1, const char *s2)
{
     int i = 0;

     while (s1[i] != '\0' && s2[i] != '\0')
     {
          if (s1[i] != s2[i])
          {
               return s1[i] - s2[i];
          }
          i++;
     }

     return s1[i] - s2[i];
}

// MAIN FUNCTION
int main()
{
     char str1[100], str2[100], temp[200];

     cout << "Enter first string: ";
     cin >> str1;

     cout << "Enter second string: ";
     cin >> str2;

     // strlen
     cout << "\nLength of str1: " << myStrlen(str1);
     cout << "\nLength of str2: " << myStrlen(str2);

     // strcpy
     myStrcpy(temp, str1);
     cout << "\n\nAfter strcpy (temp = str1): " << temp;

     // strcat
     myStrcat(temp, str2);
     cout << "\nAfter strcat (temp + str2): " << temp;

     // strcmp
     int res = myStrcmp(str1, str2);

     cout << "\n\nstrcmp result: " << res;
     if (res == 0)
          cout << " (Strings are equal)";
     else if (res < 0)
          cout << " (str1 < str2)";
     else
          cout << " (str1 > str2)";

     cout << endl;

     return 0;
}

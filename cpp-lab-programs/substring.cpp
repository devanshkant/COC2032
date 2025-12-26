#include <iostream>
using namespace std;
// to find substring in a string :- count number of occurence and to return index for each occurence
int main()
{
    char str[100];
    char sub_str[30];
    cout << "ENTER THE MAIN STRING : ";
    cin >> str;
    cout << "\n ENTER THE SUB STRING : ";
    cin >> sub_str;
    int len1 = 0; // for main string
    while (str[len1] != '\0')
    {
        len1++;
    }
    int len2 = 0; // for sub string
    while (sub_str[len2] != '\0')
    {
        len2++;
    }
    int y = 0;
    while (str[y] != '\0')
    {
        if (str[y] >= 'A' && str[y] <= 'Z')
        {
            str[y] = str[y] + 32;
        }
        y++;
    }

    int z = 0;
    while (sub_str[z] != '\0')
    {
        if (sub_str[z] >= 'A' && sub_str[z] <= 'Z')
        {
            sub_str[z] = sub_str[z] + 32;
        }
        z++;
    }

    if (len2 > len1)
    {
        cout << "-1";
        return 0;
    }
    int count = 0; // for no. of occurences

    int a = 0; // for index
    while (str[a] >= len1 - len2)
    {
        for (int i = 0; i < len2; i++)
        {
            if (str[a + i] != sub_str[i])
            {
                break;
            }
            if (i == len2 - 1)
            {
                count++;
                cout << "POSITION OF SUBSTRING " << count << " is " << a << endl;
            }
        }
        a++;
    }
    cout << "Total number of occurence : " << count << endl;
    if (count == 0)
    {
        cout << "No substring found!!";
    }
    return 0;
}
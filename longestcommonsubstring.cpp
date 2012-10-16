// marius gherman 2012, lowest common substring of two strings for a saratov problem
#include <iostream>
#include <stdio.h>
#include <string.h>


using namespace std;

string lcs(string& a, string&b)
{

    int *curr = new int[b.size()];
    int *prev = new int[b.size()];
    memset(curr, 0, b.size() * sizeof(int));
    memset(prev, 0, b.size() * sizeof(int));
    int length = 0;
    int endIndex = 0;

    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = 0; j < b.size(); ++j)
        {
           if (a.at(i) == b.at(j))
            {
                if (i == 0 || j == 0) // if it's the first element in either string
                {
                    curr[j] = 1;
                }
                else
                {
                    curr[j] = prev[j - 1] + 1;
                    if (curr[j] > length)
                    {
                        length = curr[j];
                        endIndex = i;
                    }
                }

            }
            else
            {
                curr[j] = 0;
            }
        }

        for (int k = 0; k < b.size(); ++k)
        {
            prev[k] = curr[k];
        }
    }

    delete[] prev;
    delete[] curr;
    string result = a.substr(endIndex + 1 - length, length);
    return result;
}



string lcs_morespace(string&a, string b)
{
    int **val = new int*[a.size()];
    for (int i = 0; i < a.size(); ++i)
    {
        val[i] = new int[b.size()];
        memset(val[i], 0, b.size() * sizeof(int));
    }
    int maxLength = 0;
    int endIndex = 0;
    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < b.size(); ++j)
        {
            if (a.at(i) == b.at(j))
            {
                if (i == 0 || j == 0)
                {
                    val[i][j] = 1;
                }
                else
                {
                    val[i][j] = val[i - 1][j - 1] + 1;
                    if (val[i][j] > maxLength)
                    {
                        maxLength = val[i][j];
                        endIndex = i;
                    }
                }
            }
            else
            {
                val[i][j] = 0;
            }
        }
    string result = a.substr(endIndex + 1 - maxLength, maxLength);
    return result;
}

int main()
{
    string a = "abacaba";
    string b = "abracab";
//    cout << lcs_morespace(a,b) << endl;
//    cout << lcs(a,b) << endl;
//    cout << a << endl << b << endl;
//    string a;
//    string b;
//    getline(cin, a);
//    getline(cin, b);
    cout << lcs_morespace(a,b);


    return 0;
}


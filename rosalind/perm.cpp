// perm
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;
int numTotal = 0;

void gen_perm(int *sol, int n, int k)
{
    if (k == n)
    {
        for (int i = 0 ; i < n; ++i)
        {
         cout << sol[i] + 1 << " ";
        }
        cout << endl;
        numTotal++;
    }
    else
    {
        for (int i = 0; i < n; ++i)
          {
            bool isUsed = false;
            for (int j = 0 ; j < k; ++j)
                {
                    if (sol[j] == i)
                    {
                        isUsed = true;
                        break;
                    }
                }
            if (!isUsed)
            {
                sol[k] = i;
                gen_perm(sol, n, k + 1);
            }
          }
    }
}

int main()
{

    int N = 7;
    int *sol = new int[N];
    memset(sol, 0, N * sizeof(int));
    gen_perm(sol, N, 0);
    cout << numTotal << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        vector<vector<int> > solution;
        if (num.size() == 0)
        {
            return solution;
        }
        sort(num.begin(), num.end());

        vector<int>::iterator i, j;
        i = num.begin();
        for (; i != num.end(); ++i)
        {
            for (j = i + 1; j != num.end(); ++j)
            {
                int a = (*i);
                int b = (*j);
                const int c = - (a + b);
                if (std::binary_search(j + 1, num.end(), c))
                {
                    vector<int> answer;
                    answer.push_back(a);
                    answer.push_back(b);
                    answer.push_back(c);
                    if (!binary_search(solution.begin(), solution.end(), answer))
                    {
                        solution.push_back(answer);
                    }
                }
            }
        }
        return solution;
    }
};


int main()
{
    Solution* sol = new Solution();
    vector<int> vec;
    vec.push_back(-2);
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(2);
    //    vec.push_back(0);

    vector<vector<int> > solution = sol->threeSum(vec);


    vector<vector<int> >::const_iterator ii;
    for (ii = solution.begin(); ii != solution.end(); ++ii)
    {
        vector<int> answer = (*ii);

        vector<int>::const_iterator jj;
        for (jj = answer.begin(); jj != answer.end(); ++jj)
        {
            cout << (*jj) << " ";
        }
        cout << "\n";
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());

        int sum = num.at(0) + num.at(1) + num.at(2);
        int min_diff =  sum - target;
        if ( min_diff < 0 )
        {
            min_diff = - min_diff;
        }

        vector<int>::iterator i, j;

        for (i = num.begin(); i != num.end() && min_diff != 0; ++i)
            for (j = i + 1; j != num.end(); ++j)
            {
                for (int val = 0; val < min_diff; ++val)
                {
                    const int search1 = (val + target - (*i) - (*j));
                    const int search2 = (-val + target - (*i) - (*j));
                    if (binary_search(j + 1, num.end(), search1))
                    {
                        min_diff = val;
                        sum = (*i) + (*j) + search1;
                        break;
                    }
                    else if (binary_search(j + 1, num.end(), search2))
                    {
                        min_diff = val;
                        sum = (*i) + (*j) + search2;
                        break;
                    }
                }
            }
        return sum;
    }

};

int main()
{
    Solution* sol = new Solution();
    //    S = {-1 2 1 -4}, and target = 1.
    vector<int> S;
    S.push_back(1);
    S.push_back(1);
    S.push_back(1);
    S.push_back(0);

    cout << sol->threeSumClosest(S,100);
    return 0;
}

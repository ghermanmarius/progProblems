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

        vector<int>::iterator i, j, k;
        int min_diff = 32000, sum;
        bool found = false;
        for (i = num.begin(); i != num.end() && !found; ++i)
        {
            //solve this
            j = i + 1;
            k = &(*(num.end() - 1));
            while (j != k)
            {
                if ( (*i) + (*j) + (*k) == target)
                {
                    sum = (*i) + (*j) + (*k);
                    found = true;
                    break;
                    //solution found
                } else if ( (*i) + (*j) + (*k) > target)
                {
                    int current_diff = (*i) + (*j) + (*k) - target;
                    if (current_diff < min_diff)
                    {
                        min_diff = current_diff;
                        sum = (*i) + (*j) + (*k);
                    }
                    k--;
                }
                else
                {
                    int current_diff = target - ((*i) + (*j) + (*k));
                    if (current_diff < min_diff)
                    {
                        min_diff = current_diff;
                        sum = (*i) + (*j) + (*k);
                    }
                    j++;
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
    S.push_back(0);
    S.push_back(2);
    //    S.push_back(0);

    cout << sol->threeSumClosest(S,0);
    return 0;
}

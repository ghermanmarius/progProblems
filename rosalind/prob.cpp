// prob
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ifstream inFile;
    inFile.open("rosalind_prob.txt");
    std::vector<float>num;
    float val;
    while (inFile >> val)
    {
        num.push_back(val);
    }
       
    std::vector<float>::const_iterator it;
    for (it = num.begin(); it != num.end(); ++it)
    {
        float x = float(*it);
        printf("%.6f ", x * x - x + 0.5f);
    }
    // 0.322900 0.286100 0.312500 test input sol
    inFile.close();    
    return 0;
}

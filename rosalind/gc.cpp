// dna
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    
    std::ifstream inFile("rosalind_gc.txt");
    string id, content;
    float max = 0.f;
    int idMax;
    std::vector<string> idList;
    while (inFile >> id >> content)
    {
         int numC = count(content.begin(), content.end(), 'C');
         int numG = count(content.begin(), content.end(), 'G');
         idList.push_back(id);
    
         if ((float(numC) + float(numG)) * 100 / content.size() > max)
         {
            max = (float(numC) + float(numG)) * 100 / content.size();
            idMax = idList.size();
         }
    }

    printf("%2.6f\n", max);
    cout <<  static_cast<string>(idList.at(idMax - 1));
    inFile.close();    
    return 0;
}

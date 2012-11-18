// dna
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ifstream inFile;
    inFile.open("rosalind_gc.txt");
    string id, content;
    while (!inFile.eof())
    {
        inFile >> id;
        inFile >> content;
    
         int numC = count(content.begin(), content.end(), 'C');
         int numG = count(content.begin(), content.end(), 'G');
    
         cout << id.substr(1) << endl;
         cout << (float(numC) + float(numG)) / content.size() * 100 << endl;

    }
    inFile.close();    
    return 0;
}

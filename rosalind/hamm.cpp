// hamm
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ifstream inFile;
    inFile.open("rosalind_hamm.txt");
    string s, t;
    inFile >> s >> t;
    
    int hammCount = 0;
    for (int i = 0; i < s.size(); ++i)\
    {
       (s.at(i) != t.at(i)) ? (++hammCount) : false;
    }
   
    cout << hammCount << endl;
    inFile.close();    
    return 0;
}

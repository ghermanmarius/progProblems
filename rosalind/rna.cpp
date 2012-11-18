// dna
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ifstream inFile;
    inFile.open("rosalind_rna.txt");
    string s;
    inFile >> s;
    replace(s.begin(), s.end(), 'T', 'U');
    cout << s << endl;
    inFile.close();    
    return 0;
}

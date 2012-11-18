// dna
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ifstream inFile;
    inFile.open("rosalind_dna.txt");
    string s;
    inFile >> s;
    cout << std::count(s.begin(), s.end(), 'A') << " ";
    cout << std::count(s.begin(), s.end(), 'C') << " ";
    cout << std::count(s.begin(), s.end(), 'G') << " ";
    cout << std::count(s.begin(), s.end(), 'T') << endl;
    

    inFile.close();    
    return 0;
}

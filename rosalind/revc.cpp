// dna
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ifstream inFile;
    inFile.open("rosalind_revc.txt");
    string s;
    inFile >> s;
    reverse(s.begin(), s.end());
    
    replace(s.begin(), s.end(), 'C', '1');
    replace(s.begin(), s.end(), 'G', '2');
    replace(s.begin(), s.end(), 'T', '3');
    replace(s.begin(), s.end(), 'A', '4');
   
    replace(s.begin(), s.end(), '4', 'T');
    replace(s.begin(), s.end(), '3', 'A');
    replace(s.begin(), s.end(), '1', 'G');
    replace(s.begin(), s.end(), '2', 'C');    
             
    cout << s << endl;
    inFile.close();    
    return 0;
}

//http://codeforces.com/contest/27/problem/A

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

int main()
{
	long long n;
	std::cin >> n;
	std::vector<bool> isTaken(3000, false );

	int current;
	for (int i = 0; i < n; ++i) {
		std::cin >> current; 
		isTaken[current - 1] = true;
	}

	std::cout << std::find(isTaken.begin(), isTaken.end(), false) - isTaken.begin() + 1;
	return 0;
}


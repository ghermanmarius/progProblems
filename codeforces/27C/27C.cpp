//http://codeforces.com/contest/27/problem/C


#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>


int main()
{
	long long n;
	std::cin >> n;
	if (n < 3) {
		std::cout << "0";
		return 0;
	}

	std::vector<long> seq;
	std::vector<int> monotonicity;

	long long currentVal;
	std::cin >> currentVal;
	seq.push_back(currentVal);

	for (int i = 1; i < n; ++i) {
		std::cin >> currentVal;
		seq.push_back(currentVal);
		if (seq[i] == seq[i - 1]) monotonicity.push_back(0);
		if (seq[i] > seq[i - 1]) monotonicity.push_back(1);
		if (seq[i] < seq[i - 1]) monotonicity.push_back(-1);
	}

	std::vector<int> inc = { 1 };
	std::vector<int> dec = { -1 };
	auto resultUp = std::find_first_of(monotonicity.begin(), monotonicity.end(), inc.begin(), inc.end());
	auto resultDown = std::find_first_of(monotonicity.begin(), monotonicity.end(), dec.begin(), dec.end());

	if (resultUp != monotonicity.end() && resultDown != monotonicity.end()) {
		int indexUp = std::distance(monotonicity.begin(), resultUp) + 1;
		int indexDown = std::distance(monotonicity.begin(), resultDown) + 1;

		if (indexUp < indexDown) {
			std::cout << "3" << std::endl;
			std::cout << indexUp << " " << indexDown << " " << indexDown + 1;
		} else {
			std::cout << "3" << std::endl;
			std::cout << indexDown << " " << indexUp << " " << indexUp + 1;
		}
	} else {
		std::cout << "0";
	}


	return 0;
}


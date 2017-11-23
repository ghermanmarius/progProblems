//http://codeforces.com/contest/27/problem/E

#include <iostream>
#include <cmath>
#include <vector>

const int primes[11] = {1,
						2, 3, 5, 7, 11,
						13, 17, 19, 23, 29};
const int numPrimes = 10;

int target;
unsigned long long found = 9223372036854775807;

void rec(int index, int num, unsigned long long val) {
	if (index > 10) {
		return;
	}
	if (num > target) {
		return;
	}
	if (num == target) {
		found = val < found ? val : found;
	}
	for (int i = 1; i <= 70; ++i) {
		val *= primes[index];
		if (val > found) {
			return;
		}
		rec(index + 1, num * (i + 1), val);
	}
}

int main()
{
	std::cin >> target;
	rec(1, 1, 1);
	std::cout << found;
	return 0;
}


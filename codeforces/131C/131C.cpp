//http://codeforces.com/problemset/problem/131/C

#include "stdafx.h"
#include <iostream>

unsigned long long choose(unsigned long long n, unsigned long long k) {
	if (k > n) {
		return 0;
	}
	unsigned long long r = 1;
	for (unsigned long long d = 1; d <= k; ++d) {
		r *= n--;
		r /= d;
	}
	return r;
}


int main()
{
	long long n, m, t;
	std::cin >> n >> m >> t;

	long long result = 0;
	for (long long i = 4; i < t; ++i) {
		result += choose(n, i) * choose(m, t - i);
	}

	std::cout << result;
	
	return 0;
}


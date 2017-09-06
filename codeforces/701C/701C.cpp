//http://codeforces.com/problemset/problem/701/C

#include <iostream>
#include <string>
#include <map>
#include <vector>

#define INFINITY 999999999

int main()
{
	long n;
	std::string pokemons;
	std::cin >> n;
	std::map<char, int> charMap;

	std::vector<long> minLen;

	std::getline(std::cin, pokemons); // endofline
	std::getline(std::cin, pokemons);

	for (int i = 0; i < n; ++i) {
		charMap[pokemons[i]] = 1;
		minLen.push_back(0);
	}

	std::map<char, int>::iterator it = charMap.begin();

	while (it != charMap.end()) {
		int prev = -1;
		char _current = it->first;
		for (long i = 0; i < n; ++i) {
			if (pokemons[i] == _current) {
				prev = i;
			}
			if (prev == -1) {
				minLen[i] = INFINITY;
			} else {
				minLen[i] = minLen[i] > (i - prev + 1) ? minLen[i] : (i - prev + 1);
			}
		}
		++it;
	}

	long ans = INFINITY;
	for (int i = 0; i < n; ++i) {
		ans = ans > minLen[i] ? minLen[i] : ans;
	}

	std::cout << ans;
	return 0;
}


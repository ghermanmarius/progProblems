//http://codeforces.com/contest/27/problem/B


#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>


struct player {
	std::vector<int> wins;
	std::vector<int> loss;
	int numMatches;
};


int main()
{
	long long n;
	std::cin >> n;
	int numMatches = (n * (n - 1)) / 2 - 1;
	player* players = new player[n + 1];
	for (int i = 1; i < n + 1; i++) {
		players[i].numMatches = 0;
	}
	int p1, p2;

	for (int i = 0; i < numMatches; ++i) {
		std::cin >> p1 >> p2;
		players[p1].wins.push_back(p2);
		players[p2].loss.push_back(p1);
		players[p1].numMatches++;
		players[p2].numMatches++;
	}

	std::vector<int> leftBehind;
	for (int i = 1; i < n + 1; i++) {
		if (players[i].numMatches == (n - 2)) {
			leftBehind.push_back(i);
		}
	}

	p1 = leftBehind[0];
	p2 = leftBehind[1];

	for (int i = 0; i < n + 1; i++) {
		if (i == p1)
			continue;
		if (i == p2)
			continue;
		if (std::find(players[i].wins.begin(), players[i].wins.end(), p1) != players[i].wins.end() &&
			std::find(players[i].loss.begin(), players[i].loss.end(), p2) != players[i].loss.end()) {
			std::cout << p2 << " " << p1;
			return 0;
		}
		if (std::find(players[i].wins.begin(), players[i].wins.end(), p2) != players[i].wins.end() &&
			std::find(players[i].loss.begin(), players[i].loss.end(), p1) != players[i].loss.end()) {
			std::cout << p1 << " " << p2;
			return 0;
		}
	}
	std::cout << p1 << " " << p2;
	return 0;
}


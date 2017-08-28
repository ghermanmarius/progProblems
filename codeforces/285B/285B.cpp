//http://codeforces.com/problemset/problem/285/B

#include <iostream>

int main() {

	int n, s, t;
	std::cin >> n >> s >> t;

	if (s == t) {
		std::cout << 0;
		return 0;
	}
	
	int *p = new int[n + 1];
	int *visited = new int[n + 1];

	for (int i = 1; i < n + 1; ++i) {
		std::cin >> p[i];
		visited[i] = 0;
	}

	int count = 0;
	while (true) {
		count++;
		visited[s] = 1;
		s = p[s];

		if (s == t) {
			std::cout << count;
			break;
		} else if (visited[s] != 0) {
			std::cout << "-1";
			break;
		}

	}


	delete[] p;
	delete[] visited;

	return 0;
}
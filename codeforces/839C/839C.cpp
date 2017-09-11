//http://codeforces.com/problemset/problem/839/C

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <stack>
#include <iomanip>


int main()
{
	long n, u, v;
	std::cin >> n;
	std::vector<std::vector<long>> neighbors(n, std::vector<long>());

	for (long i = 0; i < n - 1; ++i) {
		std::cin >> u >> v;
		neighbors[u - 1].push_back(v - 1);
		neighbors[v - 1].push_back(u - 1);
	}

	std::vector<bool> visited(n, false);
	std::vector<double> prob(n, 1.f);
	std::stack<long> nodeStack;
	std::vector<long> depth(n, 0);

	double average = 0.f;

	nodeStack.push(0);
	while (!nodeStack.empty()) {

		long current = nodeStack.top();
		nodeStack.pop();
		if (visited[current] == false) {
			visited[current] = true;
			long numNeighbors = neighbors[current].size();
			bool isLeaf = true;
			double chance = (current == 0) ? numNeighbors : (numNeighbors - 1);
			for (long i = 0; i < numNeighbors; ++i) {
				if (!visited[neighbors[current][i]]) {
					nodeStack.push(neighbors[current][i]);

					prob[neighbors[current][i]] = prob[current] * (1.f / chance);
					depth[neighbors[current][i]] = depth[current] + 1;
					isLeaf = false;
				}
			}
			if (isLeaf) {
				average += prob[current] * (double)depth[current];
			}
		}
	}

	std::cout << std::setprecision(15) << average;
	return 0;
}


//http://codeforces.com/contest/27/problem/D

#include <iostream>
#include <cmath>
#include <vector>

struct node {
	int left, right;
	int color;
	std::vector<node*> neighbors;
	bool viz;
};

struct graph {
	int numNodes;
	std::vector<node*> nodes;
};

bool result;

void dfs(node* current, int c) {
	if (current->viz) {
		if (c != current->color) {
			result = false;
		}
		return;
	}
	current->color = c;
	current->viz = true;
	for (int i = 0; i < current->neighbors.size(); ++i) {
		dfs(current->neighbors[i], 1 - c);
	}
};


int main()
{
	long n, m;
	std::cin >> n >> m;
	graph g;
	g.numNodes = m;

	for (int i = 0; i < m; ++i) {
		int x, y;
		std::cin >> x >> y;
		node* n = new node();
		n->left = (x > y) ? y : x;
		n->right = (x > y) ? x : y;
		n->color = 0;
		n->viz = false;
		g.nodes.push_back(n);
	}


	for (int i = 0; i < g.nodes.size(); ++i)
		for (int j = i + 1; j < g.nodes.size(); ++j) {
			node* node1 = g.nodes[i];
			node* node2 = g.nodes[j];
			if (node1->right <= node2->left) {
				continue;
			}
			if (node1->left >= node2->right) {
				continue;
			}
			if (node1->left >= node2->left &&  node1->right <= node2->right) {
				continue;
			}
			if (node1->left <= node2->left && node1->right >= node2->right) {
				continue;
			}
			node1->neighbors.push_back(node2);
			node2->neighbors.push_back(node1);
		}

	int c = 1;
	result = true;
	for (int i = 0; i < g.nodes.size(); ++i) {
		if (!g.nodes[i]->viz) {
			dfs(g.nodes[i], 0);
		}
	}

	if (result) {
		for (int i = 0; i < g.nodes.size(); ++i) {
			std::cout << (g.nodes[i]->color == 0 ? "i" : "o");
		}
	} else {
		std::cout << "Impossible";
	}

	return 0;
}

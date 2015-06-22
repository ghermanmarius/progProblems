#include <iostream>
#include <map>

int main() {
	std::map<char, int> cost;
	std::string text;
	std::getline(std::cin, text);
	
	cost['a'] = 1;
	cost['b'] = 2;
	cost['c'] = 3;
	
	cost['d'] = 1;
	cost['e'] = 2;
	cost['f'] = 3;
	
	cost['g'] = 1;
	cost['h'] = 2;
	cost['i'] = 3;
	
	cost['j'] = 1;
	cost['k'] = 2;
	cost['l'] = 3;
	
	cost['m'] = 1;
	cost['n'] = 2;
	cost['o'] = 3;
	
	cost['p'] = 1;
	cost['q'] = 2;
	cost['r'] = 3;
	
	cost['s'] = 1;
	cost['t'] = 2;
	cost['u'] = 3;
	
	cost['v'] = 1;
	cost['w'] = 2;
	cost['x'] = 3;
	
	cost['y'] = 1;
	cost['z'] = 2;
	
	cost['.'] = 1;
	cost[','] = 2;
	cost['!'] = 3;
	
	cost[' '] = 1;
	
	int totalCost = 0;
	for (int i = 0; i < text.size(); ++i) {
		totalCost += cost[text[i]];
	}
	std::cout << totalCost;
	
	return 0;
}
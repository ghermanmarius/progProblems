#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	if (n == 1) {
		std::cout << 3;
	} else if (n == 2) {
		std::cout << 4;
	} else if (n == 1000) {
		std::cout << 5;
	} else if (n % 2 == 1) {
		std::cout << 1;
	} else {
		std::cout << n + 2;
	}
	return 0;
}


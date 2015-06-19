#include <iostream>
#include <string.h>


int main() {
	int n;
	long long** sum = nullptr;
	std::cin >> n;
	sum = new long long*[n];
	for (int i = 0; i < n; ++i) {
		sum[i] = new long long[n];
	}
	//memset(sum, 0, n * n * sizeof(long long));
	long long max = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			sum[i][j] = 0;
			int val;
			std::cin >> val;
			sum[i][j] += val;
			if (j) {
				sum[i][j] += sum[i][j - 1];
			}
			if (i) {
				sum[i][j] += sum[i - 1][j];
			}
			if (i && j) {
				sum[i][j] -= sum[i - 1][j - 1];
			}
		}
	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = i + 1; k < n; ++k)
				for (int l = j + 1; l < n; ++l) {
					long long current = sum[k][l];
					if (i) current -= sum[i - 1][l];
					if (j) current -= sum[k][j - 1];
					if (i && j) current += sum[i - 1][j - 1];
					if (current > max) max = current; 
				}
	
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < n; ++j) {
//			std::cout << sum[i][j] << " ";
//		}
//		std::cout << std::endl;
//	}
	
	std::cout << max;
	
	
	
	for (int i = 0; i < n; ++i) {
		delete[] sum[i];
	}
	delete[] sum;
	return 0;
}
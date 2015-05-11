// sudoku solver
#include <iostream>
#include <fstream>
#include <string.h>

const int freeCellMask = (1 << 10) - 1;
const int kGridSize = 9;

void printGrid(int** grid) {
	for (int i = 0; i < kGridSize; ++i) {
		for (int j = 0; j < kGridSize; ++j) {
			std::cout << grid[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main() {
	std::ifstream fileStream("sudoku.txt");
	
	int** grid = new int*[kGridSize];
	for (int i = 0; i < kGridSize; ++i) { 
		grid[i] = new int[kGridSize];
	} 
	int* rowMasks = new int[kGridSize];
	for (int i = 0; i < kGridSize; ++i) rowMasks[i] = 0;
	//read grid number
	char buffer[256];
	fileStream.getline(buffer, 256);
	char currentChar;
	for (int i = 0; i < kGridSize; ++i) {
		for (int j = 0; j < kGridSize; ++j) {
			fileStream.get(currentChar);
			int val = currentChar - '0';
			grid[i][j] = val ? (freeCellMask & (1 << val)) : freeCellMask;
			if (val) {
				rowMasks[i] |= (1 << val);
			}
		}
		fileStream.get(currentChar);
	}
	printGrid(grid);
	for (int i = 0; i < kGridSize; ++i) {
		std::cout << "row " << i << " -> " << rowMasks[i] << std::endl;
	}
	
	
	return 0;
}
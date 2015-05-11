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
	std::cout << std::endl;
}

void printArray(int* arr, const char* arrName) {
	for (int i = 0; i < kGridSize; ++i) {
		std::cout << arrName << "[" << i << "] : " << arr[i] << std::endl;
	}
	std::cout << std::endl;
}

int main() {
	std::ifstream fileStream("sudoku.txt");
	
	int** grid = new int*[kGridSize];
	for (int i = 0; i < kGridSize; ++i) { 
		grid[i] = new int[kGridSize];
	} 
	int* rowMasks = new int[kGridSize];
	int* colMasks = new int[kGridSize];
	memset(rowMasks, 0, kGridSize * sizeof(int));
	memset(colMasks, 0, kGridSize * sizeof(int));
	
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
				colMasks[j] |= (1 << val);
			}
			std::cout << val << " ";
		}
		fileStream.getline(buffer, 256);
		std::cout << std::endl;
		//std::cout << currentChar;
	}
	
	printGrid(grid);
	printArray(rowMasks, "rowMasks");
	printArray(colMasks, "colMasks");
	
	applyMasks(grid, rowMasks, colMasks);
	
	
	delete[] rowMasks;
	delete[] colMasks;
	for (int i = 0; i < kGridSize; ++i) { 
		delete[] grid[i];
	} 
	delete[] grid;
	return 0;
}
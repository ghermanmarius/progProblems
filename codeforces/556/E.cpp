#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>


int max(int a, int b) {
	return a > b ? a : b;
}


struct segTree {
public:
	//int (*f)(int, int);
	segTree *leftTree, *rightTree;
	int val;
	int delayed;
	segTree(int v/*, int(*ff)(int, int)*/) : val(v), delayed(0), leftTree(NULL), rightTree(NULL)/*, f(ff)*/ { }



	void lazyDown() {
		val = max(val, delayed);

		//init delayed values on left-right children

		if (leftTree != NULL) {
			leftTree->delayed = max(leftTree->delayed, delayed);
		}
		if (rightTree != NULL) {
			rightTree->delayed = max(rightTree->delayed, delayed);
		}

	}


	int getValue(int left, int right, int index) { // get the value from the range
		lazyDown(); // init/propagate in case it didn't happen before

		int mid = (left + right) >> 1;

		if (leftTree != NULL && index < mid) { //value is in left child
			return max(leftTree->getValue(left, mid, index),  val);
		}
		if (rightTree != NULL && index >= mid) {
			return max(rightTree->getValue(mid, right, index), val);
		}

		return val;;
	}

	void update(int left, int right, int updateLeft, int updateRight, int delayedValue) {
		lazyDown();

		if (left >= updateRight) { // updateLeft < updateRight < left < right
			return;
		}
		if (right <= updateLeft) {// left < right < updateLeft < updateRight
			return;
		}
		if (updateLeft <= left && updateRight >= right) { // updateLeft < [left, right] < updateRight -> nodul e in range-ul de update
			delayed = delayedValue; // update current node, propagate when needed
			// 3 hours of debugging here
			return;
		}

		// else update subtrees left < updateLeft < right < updateRight, or the other
		
		if (leftTree == NULL || rightTree == NULL) { //never been here before.    if left exists -> right exists
			leftTree = new segTree(val);
			rightTree = new segTree(val);
		}

		//print();

		int mid = (left + right) >> 1;
		leftTree->update(left, mid, updateLeft, updateRight, delayedValue);
		rightTree->update(mid, right, updateLeft, updateRight, delayedValue);
		//print();
	}



	//void print(int align = 0) {
	//	for (int i = 0; i < align; ++i) {
	//		std::cout << "";
	//	}
	//	std::cout << val << std::endl;
	//	if (leftTree != NULL) {
	//		leftTree->print(align + 1);
	//	}
	//	if (rightTree != NULL) {
	//		rightTree->print(align + 1);
	//	}
	//}
};

int main()
{
	int n, q;
	std::cin >> n >> q;

	segTree* columns = new segTree(0);
	segTree* rows = new segTree(0);

	int col, row;
	char op;
	int index;

	for (int i = 0; i < q; ++i) {
		
		std::cin >> col >> row >> op;
		if (op == 'U') {
			index = columns->getValue(1, n + 1, col);
			std::cout << row - index << std::endl;
			rows->update(1, n + 1, index + 1, row + 1, col); // update all rows betwenn index and current row
			columns->update(1, n + 1, col, col + 1, row); // column can not be "columned" again
			//cols->print();
			//rows->print();
		} 
		if (op == 'L') {
			index = rows->getValue(1, n + 1, row);
			std::cout << col - index << std::endl;
			columns->update(1, n + 1, index + 1, col + 1, row); // column can not be "columned" again
			rows->update(1, n + 1, row, row + 1, col); // update all rows betwenn index and current row
			//cols->print();
			//rows->print();
		}

	}

	return 0;
}


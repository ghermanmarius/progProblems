#include <iostream>
#include <stack>

int main() {
	char currentChar;
	std::stack<char> message;
	while (std::cin.get(currentChar) && currentChar != '\n') {
		if (message.size() > 0 && message.top() == currentChar) {
			message.pop();
		} else {
			message.push(currentChar);
		}
	}
	std::stack<char> temp;
	while (message.size()) { 
		temp.push(message.top());
		message.pop();
	}
	while (temp.size()) {
		std::cout << temp.top();
		temp.pop();
	}
	return 0;
}
#include <iostream>
#include <map>


int main() {
	
	std::map<std::string, int> shelves;
	
	shelves["Alice"] = 0;
	shelves["Ariel"] = 0;
	shelves["Aurora"] = 0;
	shelves["Phil"] = 0;
	shelves["Peter"] = 0;
	shelves["Olaf"] = 0;
	shelves["Phoebus"] = 0;
	shelves["Ralph"] = 0;
	shelves["Robin"] = 0;
	
	shelves["Bambi"] = 1;	
	shelves["Belle"] = 1;
	shelves["Bolt"] = 1;
	shelves["Mulan"] = 1;	
	shelves["Mowgli"] = 1;
	shelves["Mickey"] = 1;
	shelves["Silver"] = 1;	
	shelves["Simba"] = 1;
	shelves["Stitch"] = 1;
	
	shelves["Dumbo"] = 2;	
	shelves["Genie"] = 2;
	shelves["Jiminy"] = 2;
	shelves["Kuzko"] = 2;	
	shelves["Kida"] = 2;
	shelves["Kenai"] = 2;
	shelves["Tarzan"] = 2;	
	shelves["Tiana"] = 2;
	shelves["Winnie"] = 2;
	
	int n;
	int numSteps = 0;
	int currentShelf = 0;
	std::cin >> n;
	std::string name;
	while (n--) {
		std::cin >> name;
		int diff = currentShelf - shelves[name];
		if (diff != 0) {
			if (diff < 0) diff = -diff;
			numSteps += diff;
			currentShelf = shelves[name];
		}
	}
	std::cout << numSteps;
	
	return 0;
}
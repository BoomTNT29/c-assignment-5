#include "zoo-species.hpp"
#include "input-prog.hpp"
#include <sstream>

using namespace std;

int format_animals(string fileName, int &mp, int &rp, int &bp) {
	vector<string> animals;

	readFile(fileName, animals);
	
	for (int i = 0; i < animals.size(); i++) {
		if (animals[i].find("mammal")) {
			animals[i].erase(0, 8);
			int mam = stoi(animals[i]);
			for (; i < mam; i++) {
				istringstream ss(animals[i]);
				string name;
				int count;
				string dt;
				ss >> name >> count >> dt;
			}
		}
	}
}

int main(void) {
	vector<Zoo_species *> animals;
	int mp = 0, rp = 0, bp = 0; // three pointers to break the vector
	
	format_animals("db.txt", mp, rp, bp);
}

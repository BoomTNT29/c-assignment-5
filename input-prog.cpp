#include <fstream>
#include <vector>

using namespace std;

int readFile(string &fileName, vector<string> &outString) {
	// this will read a file and return its contents
	// contents will be in a readable format
	// return type is 0 or -1.

	ifstream infile(fileName);

	while (!infile.eof()) {
		string temp;
		getline(infile, temp);
		outString.push_back(temp);
	}

	return 0;
}

int writeFile(string &outFile, string &content) {
	// this will write to the file
	
	ofstream ofile(outFile);

	ofile << content;

	return 0;
}

// int main(void) {
// 	string source = "db.txt";
// 	string ch = "hi";
// 
// 	writeFile(source, ch);
// }

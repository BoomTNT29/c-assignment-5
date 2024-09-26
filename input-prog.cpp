#include <fstream>
#include <vector>

using namespace std;

int readFile(string fileName, vector<string> &outString) {
  // this will read a file and return its contents
  // contents will be in a readable format
  // return type is 0 or -1.

  ifstream infile(fileName);

  getline(infile, fileName); // want to igonre the first line

  while (!infile.eof()) {
    string temp;
    getline(infile, temp);
    outString.push_back(temp);
  }

  return 0;
}

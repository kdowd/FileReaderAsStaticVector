#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class FileReader {


public:
	static bool success;
	static vector<string> vec;


	//ctor
	FileReader(string path) {
		filePath = path;
		readFileAsVector();
	}


	// destructor
	~FileReader() {
		cout << "FileReader Memory Reclaimed" << "\n";
	}


	void readFileAsVector() {
		string line;

		ifstream file;
		file.open(filePath);

		if (file.fail()) {
			FileReadFail();
			FileReader::success = false;
		}

		if (file.good()) {
			// skip that first line
			getline(file, line);

			while (!file.eof()) {
				getline(file, line);

				if (line.size() > 0) {
					FileReader::vec.push_back(line);
				}
			}
			file.close();

			FileReader::success = true;
		}
	}

	static auto getStaticVector() {
		return FileReader::vec;
	}

private:
	string filePath;

	void FileReadFail() {
		cout << "FAIL" << "\n";
	}


};
// must initialize the statics once time
bool FileReader::success = false;
vector<string> FileReader::vec = {};



void test() {
	FileReader fr = FileReader("data.txt");

	if (FileReader::success) {

		for (auto& item : FileReader::getStaticVector()) {
			cout << " ### " << item << "\n";
		}

	}


}
int main() {

	test();
	cin.get();
}
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class FileReader {


public:
	bool success = false;
	static vector<string> vec;

	FileReader(string path) {
		filePath = path;
		readFileAsVector();
	}

	~FileReader() {
		cout << "FileReader Memory Reclaimed" << "\n";
	}


	void readFileAsVector() {
		string line;

		ifstream file;
		file.open(filePath);

		if (file.fail()) {
			FileReadFail();
		}

		if (file.good()) {
			// skip that first line
			getline(file, line);

			while (!file.eof()) {
				getline(file, line);

				if (line.size() > 0) {
					FileReader::vec.push_back(line);
				}

				//contentsVector.push_back(line);


			}
			file.close();

			// quick copy into static member var
			//FileReader::vec.swap(contentsVector);

			success = true;
		}
	}

	auto getContentsVector() {
		return contentsVector;
	}

	static auto getStaticVector() {
		return FileReader::vec;
	}

private:
	string filePath;
	vector<string>  contentsVector{};

	void FileReadFail() {
		cout << "FAIL" << "\n";
	}


};
// must initialize it once
vector<string> FileReader::vec = {};


void test() {
	FileReader fr = FileReader("data.txt");

	if (fr.success) {
		// get a copy of the vector
		auto contentsVector = fr.getContentsVector();

		for (auto& item : FileReader::getStaticVector()) {
			cout << " ### " << item << "\n";
		}

		cout << string(50, '*') << "\n";;
		//cout << FileReader::getStaticVector() << "\n";;
		cout << string(50, '*') << "\n";

	}


}
int main() {

	test();
	cin.get();
}
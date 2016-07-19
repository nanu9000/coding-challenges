#include <iostream>
#include <thread>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>

#include <typeinfo>

using namespace std;

string test_filename  = "test.csv";
string train_filename = "train.csv";

int main() {
	ifstream test_file(test_filename);
	ifstream train_file(train_filename);

	string header, train_point, test_point;
	test_file >> header;
	train_file >> header;

	// test_file >> test_point;
	// cout << test_point;
	while(train_file >> train_point) {
		vector<int> tp_vector;
		regex commas(",");
		sregex_token_iterator iter(train_point.begin(), train_point.end(), commas, -1);
		sregex_token_iterator done;

		for(; iter != done; ++iter) {
			tp_vector.push_back(stoi(iter->str()));
		}
	}

	// vector<vector<int>> test_data;
	// vector<vector<int>> train_data;

	return 1;
}
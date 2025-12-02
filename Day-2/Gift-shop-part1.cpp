#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

vector<string> custom_split(string line, char separator){
	vector<string> ranges;
	int startIndex = 0, endIndex = 0;
	for (int i = 0; i <= line.size(); i++) {
		if (line[i] == separator || i == line.size()) {
			endIndex = i;
			string temp;
			temp.append(line, startIndex, endIndex - startIndex);
			ranges.push_back(temp);
			startIndex = endIndex + 1;
		}
	}
	return ranges;
}

long long find_invalids(vector<string> ranges){
	long long result = 0;
	for(int i = 0; i < ranges.size(); i++){
		auto posIt = find(ranges[i].begin(), ranges[i].end(), '-');
		size_t pos = distance(ranges[i].begin(), posIt);
		long long start = stoll(ranges[i].substr(0, pos));
		long long end = stoll(ranges[i].substr(pos + 1));
		long long current = start;
		for (; current < end; current++){
			string str_current = to_string(current);
			int length = str_current.length();
			if (length%2 == 0){
				if(stoll(str_current.substr(0,(length/2))) == stoll(str_current.substr((length/2)))){
					cout << current << endl;
					result += current;
				}
			}
		}
	}
	return result;
}

int main(){
	//open
	ifstream f("input.txt");
	if (!f.is_open())
	{
		cerr << "Error opening the file!";
		return 1;
	}
	//read
	string line;
	getline(f, line);
	//cout << line << endl;

	//split by comma
	vector<string> ranges;
	ranges = custom_split(line, ',');

	//find Invalids
	long long invalids = find_invalids(ranges);
	cout << invalids << endl;

	return 0;
}
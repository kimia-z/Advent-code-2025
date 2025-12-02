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

bool is_multiples(int current_len, int i){
	if(current_len % i == 0 ){
		return true;
	}
	return false;
}

bool is_sequences(string str_current, int i){
	for(int start=0; start+i < str_current.length(); start+=i){
		if(str_current.substr(start, i) != str_current.substr(start+i, i))	return false;
	}
	return true;
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
			int current_len = str_current.length();
			for(int i=0; i < current_len ; ++i){
				if(is_multiples(current_len, i) && is_sequences(str_current, i)){
					cout << current << endl;
					result += current;
					break;
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
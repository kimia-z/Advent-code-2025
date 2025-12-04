#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

vector<int> line_int(string line){
	vector<int> vec_int_line;
	for (int i = 0; i < line.size(); i++){
		vec_int_line.push_back(line[i] - '0');
	}
	return vec_int_line;
}

string joltage(string number_str, int n) {
	vector<int> number_vector = line_int(number_str);

	auto max_itr = max_element(number_vector.begin(), number_vector.end());

	int max_index = distance(number_vector.begin(), max_itr);

	if (n == 1) {
		return number_str.substr(max_index, 1);
	}

	int max_to_end = distance(max_itr, number_vector.end());

	if (max_to_end == n) {
		return number_str.substr(max_index);
	}

	if (max_to_end < n) {
		string sub_string = number_str.substr(0, max_index);
		return joltage(sub_string, n - max_to_end) + number_str.substr(max_index);
	}

	if (max_to_end > n) {
		string sub_string = number_str.substr(max_index + 1);
		return number_str[max_index] + joltage(sub_string, n - 1);
	}
	return "kir";
}

long largest_joltage(string line){
	vector<int> vec_int_line = line_int(line);
	auto maxi = max_element(vec_int_line.begin(), vec_int_line.end());
	return 10;
}

int main(){
	//open
	//cout << joltage("987654321111111", 12) << endl;
	ifstream f("input.txt");
	if (!f.is_open())
	{
		cerr << "Error opening the file!";
		return 1;
	}
	//read
	string line;
	vector<string> lines;
	while(getline(f, line)){
		lines.push_back(line);
	}
	//find largest joltage
	//loop through each line
	long result = 0;
	for(int i = 0; i < lines.size(); i++){
		result += stol(joltage(lines[i], 12));
		//cout << result << endl;
	}
	cout << result << endl;
	return 0;
}
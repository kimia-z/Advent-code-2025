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

int largest_joltage(string line){
	vector<int> vec_int_line = line_int(line);
	auto maxi = max_element(vec_int_line.begin(), vec_int_line.end());
	if (distance(vec_int_line.begin(), maxi) + 1 == vec_int_line.size()){
		//maxi == yekan
		// number = 'second_maxi' 'maxi'
		auto second_maxi = max_element(vec_int_line.begin(), maxi);
		cout << "This 'if' largest is : " << (*second_maxi * 10)+(*maxi) << endl;
		return (*second_maxi * 10)+(*maxi);
	}
	else{
		//maxi == dahgan
		// number = 'maxi' 'second_maxi'
		auto second_maxi = max_element(maxi + 1, vec_int_line.end());
		cout << "This 'else' largest is : " << (*maxi * 10)+(*second_maxi) << endl;
		return (*maxi * 10)+(*second_maxi);
	}
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
	vector<string> lines;
	while(getline(f, line)){
		lines.push_back(line);
	}
	//find largest joltage
	//loop through each line
	int result = 0;
	for(int i = 0; i < lines.size(); i++){
		result += largest_joltage(lines[i]);
		//cout << result << endl;
	}
	cout << result << endl;
	return 0;
}
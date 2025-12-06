#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void action(vector<string> vec_lines){
	int count = 0;
	int pos_new_line = 0;
	while(pos_new_line < vec_lines.size()){
		if(vec_lines[pos_new_line].empty()){
			cout << "position new line: " << pos_new_line << endl;
			break;
		}
		pos_new_line++;
	}
	vector<pair<long,long>> ranges;
	for (int i = 0; i < pos_new_line; i++){
		int pos_dash = vec_lines[i].find('-');
		long first = stol(vec_lines[i].substr(0, pos_dash));
		long last = stol(vec_lines[i].substr(pos_dash+1));
		cout<< "in ranges first: " << first << " - last: " << last << endl;
		ranges.push_back({first,last});
	}

	for(int i = pos_new_line + 1; i < vec_lines.size(); i++){
		for (int j = 0; j < ranges.size(); j++){
			if(stol(vec_lines[i]) >= ranges[j].first && stol(vec_lines[i]) <= ranges[j].second){
				count++;
				cout << "count: " << count << " for number: " << stol(vec_lines[i]) << endl;
				break;
			}
		}
		
	}
}

int main(){
	ifstream f("input.txt");
	if(!f.is_open()){
		cerr << "Error opening the file!";
		return 1;
	}
	string line;
	string lines = "";
	vector<string> vec_lines;
	while(getline(f, line)){
		lines += line;
		vec_lines.push_back(line);
		//cout << line << endl;
	}
	//cout << lines << endl;

	action(vec_lines);

	f.close();
	return 0;
}
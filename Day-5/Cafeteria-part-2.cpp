#include <string>
#include <iostream>
#include <fstream>
#include <unordered_set>

using namespace std;

void action(vector<string> vec_lines){
	int pos_new_line = 0;
	while (pos_new_line < vec_lines.size()){
		if (vec_lines[pos_new_line].empty()) {
			cout << "position new line: " << pos_new_line << endl;
			break;
		}
		pos_new_line++;
	}

	vector<pair<long long,long long>> ranges;
	for (int i = 0; i < pos_new_line; i++){
		int pos_dash = vec_lines[i].find('-');
		long long first = stoll(vec_lines[i].substr(0, pos_dash));
		long long last  = stoll(vec_lines[i].substr(pos_dash + 1));

		cout << "in ranges first: " << first << " - last: " << last << endl;
		ranges.push_back({first,last});
	}

	sort(ranges.begin(), ranges.end());

	long long total_count = 0;

	long long cur_start = ranges[0].first;
	long long cur_end   = ranges[0].second;

	for (int i = 1; i < ranges.size(); i++){
		long long s = ranges[i].first;
		long long e = ranges[i].second;

		if (s <= cur_end + 1){
			// overlaps
			cur_end = max(cur_end, e);
		} else {
			// no overlap
			total_count += (cur_end - cur_start + 1);
			cur_start = s;
			cur_end = e;
		}
	}

	total_count += (cur_end - cur_start + 1);

	cout << "TOTAL UNIQUE NUMBERS COVERED = " << total_count << endl;
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
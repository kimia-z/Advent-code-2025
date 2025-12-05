#include <string>
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

bool is_paper(vector<string> diagram, int row,int column){
	if(row < 0 || row > diagram[row].length() - 1) return false;;
	if(column < 0 || column > diagram.size() - 1) return false;
	if(diagram[row][column] == '@') {return true;}
	return false;
}

bool find_adjacents(vector<string> diagram, int row,int column){
	int count = 0;
	// (row,column) --> (row-1,column),(row-1,column-1),(row-1,column+1)
	//					(row+1,column),(row+1,column-1),(row+1,column+1)
	//					(row,column-1),(row,column+1)
	for(int i = row-1; i <= row+1; i++){
		for(int j = column-1; j <= column+1 ; j++){
			if(is_paper(diagram, i, j)) count++;
			if(count >= 5) return false;
		}
	}
	return true;

}

void blahblah(vector<string> diagram){
	int result = 0;
	for(int i = 0; i < diagram.size(); i++){
		for(int j = 0; j < diagram[i].size(); j++){
			if (diagram[i][j] == '@'){
				if (find_adjacents(diagram, i, j)) result++;
			}
		}
	}
	cout << "result: " << result << endl;
}

int main(){
	//open
	fstream f("input.txt");
	if (!f.is_open()){
		cerr << "Error opening the file!";
		return 1;
	}
	//read
	string line;
	vector <string> lines;
	while(getline(f, line)){
		lines.push_back(line);
	}
	//logic
	blahblah(lines);
	

	return 0;
}
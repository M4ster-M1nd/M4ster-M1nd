#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <io.h>
#include <stdio.h>
#include <array>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#define MAX_LEN 255

using namespace std;

int main() { //тестирование

	setlocale(LC_ALL, "Ru");

///////////////////////////////////////////////////////////////////////
	
	ifstream in("Text.txt");
	if (!in.is_open()) {
		return 0;
	}
	string temp;
	map<string, int> myword;
	
	ofstream fout;
	fout.open("words.txt");

	while (!in.eof()) {
		in >> temp;
		if ((temp[temp.length() - 1] == '.') || (temp[temp.length() - 1] == ',')) {
			temp.resize(temp.length() - 1);
		}

		if (myword.find(temp) != myword.end()) {
			myword.find(temp)->second += 1;
		}

		else {
			myword.emplace(make_pair(temp, 1));
		}
		
	}

	for (auto i : myword) {
		cout << " | ";
		cout << setw(17) << i.first;
		cout<< "| - встречается " << i.second << " раз." << endl;
		fout << " | ";
		fout << setw(17) << i.first;
		fout << "| - встречается " << i.second << " раз." << endl;
	}
	
	int max = 1;
	for (auto i : myword) {
		if (i.second >= max) {
			max = i.second;
		}
	}
	cout << endl << "___________________________________________" << endl;
	cout << "\tСамые частовстречающиейся слова:" << endl << "___________________________________________" << endl;
	fout << endl << "___________________________________________" << endl;
	fout << "\tСамые частовстречающиейся слова:" << endl << "___________________________________________" << endl;
	for (auto i : myword) {
		if (i.second == max) {
			cout << " | ";
			cout << setw(17) << i.first;
			cout << "| - встречается " << i.second << " раз." << endl;
			fout << " | ";
			fout << setw(17) << i.first;
			fout << "| - встречается " << i.second << " раз." << endl;
		}
	

	}
	
	fout.close();


	
///////////////////////////////////////////////////////////////////////

	return 0;

}
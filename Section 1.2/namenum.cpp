/*
ID:
PROG: namenum
LANG: C++
*/

#include<bits/stdc++.h>

using namespace std;

//vector<string> names;
string code;
ofstream fout ("namenum.out");
ifstream fin ("namenum.in"), fdict ("dict.txt");

/*void makeNames (int index, string name) {
	if (index == code.size()){
		names.push_back(name);
		return;
	}
	int read = (int)(code[index] - '2');
	int num = 'A' + read * 3;
	for (int i = 0; i < 3; i++) {
		string str = name;
		if (num >= 'Q')
			str += (char)(num + 1 + i);
		else
			str += num + i;
		makeNames(index+1, str);
	}
	
}*/


bool isEqual(string str){
	for (int i = 0; i < str.size(); i++) {
		if(str[i] == 'Q' || str[i] == 'Z')
			return false; 
		int num = str[i] - 'A';
		if (str[i] >=  'Q')
			num --;
		num /= 3;
		num += 2;
		//cout << str[i] << "  " << num << endl;
		if (num != code[i] - '0')
			return false;
	}
	return true;
}



int main () {
	fin >> code;
	string str = "";
	//makeNames(0,str);
	bool none = true;
	while(fdict >> str){
		if (str.size() == code.size() && isEqual(str)) {
			fout << str << endl;
			none = false;
		}
	}
	if (none == true)
		fout << "NONE" <<endl;
	
}

/*
ID: 
PROG: palsquare
LANG: C++
*/

#include<bits/stdc++.h>

using namespace std;

ofstream fout ("palsquare.out");
ifstream fin ("palsquare.in");

bool isPalindromic (string str) {
	for (int i = 0; i < str.size() / 2; i++) {
		if (str[i] != str[str.size() - 1 - i])
			return false;
	}
	return true;
}

string base (int num, int base) {
	string str = "";
	while (num != 0) {
		int remainder = (num % base);
		if (remainder < 10)
			str +=  remainder + '0';
		else 
			str += (remainder - 10) + 'A';
		num /= base;
	}
	reverse (str.begin(), str.end());
	return str;

}

int main() {
	int b;
	fin >> b;
	for (int i = 1; i <= 300; i++) {
		string square = base(i*i,b);
		if (isPalindromic(square))
			fout << base(i,b) << " " << square << endl;		
	}
}

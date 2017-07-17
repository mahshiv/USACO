/*
ID: 
PROG: dualpal
LANG: C++
*/

#include<bits/stdc++.h>

using namespace std;

ofstream fout ("dualpal.out");
ifstream fin ("dualpal.in");

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
	int n , s;
	fin >> n >> s;
	while (n != 0) {
		s++;
		int palcntr = 0;
		for (int i = 2; i <= 10; i++) {
			if(isPalindromic(base(s,i)))
				palcntr++;
			if (palcntr == 2) {
				n--;
				fout << s << endl;
				break;
			}
		}
	}
}

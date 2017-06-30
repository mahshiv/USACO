/*
ID:
PROG: gift1
LANG: C++11
*/

#include<bits/stdc++.h>
using namespace std;

vector<string> names;
vector<int> accounts;

ofstream fout ("gift1.out");
ifstream fin ("gift1.in");


void addData(){
	string name;
	int amount, n;
	fin >> name;
	fin >> amount >> n;
	ptrdiff_t pos = find(names.begin(), names.end(), name) - names.begin();
	if (pos < names.size())
		accounts[pos] += (-amount) + (n == 0 ? amount : amount % n );  
	for(int i = 0; i < n; i++)
	{
		string whom;
		fin>>whom;
		pos = find(names.begin(), names.end(), whom) - names.begin();
		if (pos < names.size())
			accounts[pos] += amount / n;	
	}
}

int main(){
	
	int np;
	fin>>np;
	for (int i = 0; i < np; i++)
	{
		string name;
		fin >> name;
		names.push_back(name);
		accounts.push_back(0);
	}
	for (int i = 0; i < np; i++)
		addData();
	for (int i = 0; i < np; i++)
		fout << names[i] << " " << accounts[i] << endl;

	
}

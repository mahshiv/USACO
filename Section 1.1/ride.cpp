/*
ID: 
PROG: ride
LANG: C++                
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	ofstream fout ("ride.out");
	ifstream fin ("ride.in");
	string comet, group;
	fin >> comet >> group;
	int cometNum = 1, groupNum = 1;
	string::iterator it;
	for ( it = comet.begin() ; it < comet.end(); it++)
	{
		cometNum = (cometNum * (((*it) - 'A') + 1)) % 47;
	}
	for (int i = 0; i < group.length(); i++)
	{
		groupNum = (groupNum * ((group[i] - 'A') + 1)) % 47;
	}
	fout << ((groupNum == cometNum) ? "GO" : "STAY") << endl;
}

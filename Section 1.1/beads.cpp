/*
ID:
PROG: beads
LANG: C++11
*/

#include<bits/stdc++.h>
using namespace std;

ifstream fin("beads.in");
ofstream fout("beads.out");

int main()
{
	int n;
	fin>>n;
	string beads ;
	fin >> beads ;
	beads += beads;
	int i = 0;
	int first = 0, second = 0 , max = 0, whites = 0;
	char counting;
	while(i < 2 * n){
		whites = 0;
		counting = beads[i];
		second  ++;
		while (++i < 2 * n && (beads[i] == counting || beads[i] == 'w' || counting == 'w')){
			if (counting == 'w')
				counting = beads[i];
			if (beads[i] == 'w'){
				whites ++;
			}else
				whites = 0;
			second ++;
		}
		//fout << first  << "  " << second << endl;
		if (first + second > max)
			max = first + second;
		first = second - whites;
		second = whites;

	}
	max = (max > n) ? n : max;
	fout << max << endl;
		
}

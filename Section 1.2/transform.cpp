/*
ID: 
PROG: transform
LANG: C++
*/

#include<bits/stdc++.h>

using namespace std;

ifstream fin ("transform.in");
ofstream fout ("transform.out");

int n;
char grid[10][10];
char wanted[10][10];

bool equal(){
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] != wanted[i][j])
				return false;
		}
	}
	return true;
}

void input(char a[10][10]){
	for ( int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			fin >> a[i][j]; 
}

void rotate(){
	char tmp[10][10];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			tmp[j][n-1-i] = grid[i][j];
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			grid[i][j] = tmp [i][j];
		}
	}
}

void reflect () {
	char tmp;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n/2; j++){
			tmp = grid[i][j];
			grid[i][j] = grid[i][n-1-j];
			grid[i][n-1-j] = tmp;
		}
	}
	
}

bool rotateAndEqual() {
	rotate();
	return equal();
}

int main(){
	fin >> n;
	input(grid);
	input(wanted);
	int ans = 7;
	if (rotateAndEqual()) 
		ans = 1;
	else if (rotateAndEqual())
		ans = 2;
	else if (rotateAndEqual())
		ans = 3;
	else {
		rotate();
		reflect();
		if (equal())
			ans = 4;
		else if (rotateAndEqual() || rotateAndEqual() || rotateAndEqual())
			ans = 5;
		else if (rotateAndEqual())
			ans = 6;
	}
	fout << ans << endl;
}


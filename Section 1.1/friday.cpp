/*
ID:
PROG: friday
LANG: C++11
*/

#include<bits/stdc++.h>
using namespace std;

ifstream fin("friday.in");
ofstream fout("friday.out");

int week[7] = {0,0,0,0,0,0,0};

int main(){
	int n;
	fin >> n;
	int lastIndex;
	for (int year = 1900; year < 1900 + n; year ++)
	{
		for (int i = 1; i <= 12; i++)
		{
			if (i == 1 && year == 1900)
			{
				lastIndex = 0;
				week[lastIndex] ++;	
				continue;
			}
			int day;
			switch(i)
			{
			case 5:
			case 7:
			case 10:
			case 12:
			{
				day = 30;
				break;
			}
			case 3:{
				if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
					day = 29;
				else
					day = 28;
				break;	
			}
			default:
			{
				day = 31;
			}
			}
			lastIndex = (lastIndex + day) % 7;
			//fout << "year : " << year <<" month : " << i << " day :  " << day << " last index : " << lastIndex << endl;
			week[lastIndex] ++;
		}
	}
	fout << week[0] << " "<< week[1] << " "<< week[2] << " "<< week[3] << " "<< week[4] << " "<< week[5] << " "<< week[6] << endl;
}

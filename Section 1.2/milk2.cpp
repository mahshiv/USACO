/*
ID:
PROG: milk2
LANG: C++
*/

#include<bits/stdc++.h>
using namespace std;

ofstream fout ("milk2.out");
ifstream fin ("milk2.in");


int main()
{
	vector< pair<int,int> > data;
	vector< pair<int,int> > interval;
	vector<bool> isUsed;
	int n;
	fin >> n;
	int max_milking = 0, max_free = 0;
	for (int i = 0; i < n; i ++)
	{
		int start , end;
		fin >> start >> end;
		isUsed.push_back(false);
		data.push_back(make_pair(start,end));
	}
	sort(data.begin(), data.end());
	for ( int i = 0; i < n; i++)
	{
		if (isUsed[i])
			continue;
		int start = data[i].first, end = data[i].second;
		isUsed[i] = true;
		for(int j = i + 1; j < n; j++)
		{
			if ((data[j].first >= start && data[j].first <= end) || (data[j].second >= start && data[j].second <= end))
			{
				isUsed[j] = true;
				start = min(data[j].first , start);
				end = max(data[j].second, end);
			}
		}
		interval.push_back(make_pair(start, end));
		if(end - start > max_milking)
			max_milking = end - start;
	}
	sort(interval.begin(), interval.end());
	for(int i = 0; i < interval.size() - 1; i++)
		max_free = max(max_free, (interval[i+1].first - interval[i].second));
	fout << max_milking << " " << max_free <<endl;
}

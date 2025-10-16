#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
int n, m;

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	priority_queue<int,vector<int>, greater<int>> minheap;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end());
	
	minheap.push(v[0].second);

	for(int i = 1; i < v.size() ; i++)
	{
		if (v[i].first >= minheap.top())
		{
			minheap.pop();
			minheap.push(v[i].second);
		}
		else
		{
			minheap.push(v[i].second);
		}
	}

	cout << minheap.size();

	return 0;
}
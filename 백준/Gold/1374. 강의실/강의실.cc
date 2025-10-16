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
	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++)
	{
		int num, st, ed;
		cin >> num >> st >> ed;
		v.push_back({ st,ed });
	}

	sort(v.begin(), v.end());

	priority_queue<int, vector<int>, greater<int>> minheap;

	minheap.push(v[0].second);

	for (int i = 1; i < n; i++)
	{
		if (minheap.top() <= v[i].first)
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
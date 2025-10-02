#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int m, n;

bool cmp(vector<int>& a, vector<int>& b) {
	for (int i = 0; i < n; i++)
		if (a[i] != b[i]) return false;
	return true;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> m >> n;
	vector<vector<int>> v(m);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int input;
			cin >> input;
			v[i].push_back(input);
		}
	}

	for (int i = 0; i < m; i++)
	{
		vector<int> tmp(v[i]);
		sort(tmp.begin(), tmp.end());

		tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

		for (int k = 0; k < v[i].size(); k++)
			v[i][k] = lower_bound(tmp.begin(), tmp.end(), v[i][k]) - tmp.begin();
	}

	int ans = 0;

	for (int i = 0; i < m-1; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			ans += cmp(v[i], v[j]);
		}
	}

	cout << ans;

	return 0;
}
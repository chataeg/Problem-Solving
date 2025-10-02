#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> tree;

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		tree.push_back(input);
	}

	sort(tree.begin(), tree.end());

	int ans = 0;

	long long low = 0;
	//long long high = *prev(tree.end());
	long long high = tree.back();


	while (low <= high)
	{
		long long mid = (low + high + 1) / 2;
		long long sum = 0;

		for (auto iter : tree)
		{
			if (iter - mid > 0)
			{
				sum += iter - mid;
			}
		}

		if (sum >= m)
		{
			ans = mid;
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}

	}

	cout << ans;

	return 0;
}
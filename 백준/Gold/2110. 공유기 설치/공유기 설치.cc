#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, c;
	cin >> n >> c;

	vector<int> v;

	while (n--)
	{
		int input;
		cin >> input;
		v.push_back(input);
	}

	long long st = 0;
	long long ed = 1000000000;

	long long ans = 0;
	
	sort(v.begin(), v.end());

	while (st <= ed)
	{
		long long mid = (st + ed + 1) / 2; 

		long long cnt = 1;

		auto iter = v.begin();
		
		while (iter != v.end())
		{
			auto next_pos = lower_bound(iter, v.end(), *iter + mid);
			if (next_pos != v.end())
			{
				iter = next_pos;
				cnt++;
			}
			else
				iter++;
		}
		
		if (cnt >= c)
		{
			st = mid + 1;
			ans = mid;
		}
		else
			ed = mid - 1;
	}

	cout << ans;

	return 0;
}
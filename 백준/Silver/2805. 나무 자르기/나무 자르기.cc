#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	long long l = 0;
	long long r = 1000000000;
	long long mx = 0;

	while (l <= r)
	{
		long long mid = (l + r + 1) / 2;

		long long sum = 0;
		for (auto iter : v)
			if(iter > mid)
				sum += iter - mid;
		
		if (sum >= m)
		{
			l = mid + 1;
			mx = max(mx, mid);
		}
		else
		{
			r = mid - 1;
		}
	}

	cout << mx;

	return 0;
}
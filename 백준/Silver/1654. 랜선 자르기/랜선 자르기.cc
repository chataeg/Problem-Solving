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

int arr[10007];
int k, n;
long long mx;

bool canmeet(long long num)
{
	int cnt = 0;
	for (int i = 0; i < k; i++)
	{
		cnt += arr[i] / num;
	}
	
	if (cnt >= n)
		return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k >> n;
	for (int i = 0; i < k; i++)
		cin >> arr[i];

	long long l = 0;
	long long r = 0x7fffffff;

	while (l <= r)
	{
		long long mid = (l + r + 1) / 2;
		
		if (canmeet(mid))
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

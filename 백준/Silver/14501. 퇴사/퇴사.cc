#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int t[20];
int p[20];
int dp[20];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> t[i] >> p[i];
	
	int mx = -10;
	for (int i = 0; i <= n; i++)
	{
		dp[i] = max(dp[i], mx);
		if (i + t[i] <= n)
		{
			dp[i + t[i]] = max(dp[i +t[i]], dp[i] + p[i]);
	
		}
		mx = max(mx, dp[i]);
	}

	cout << mx;


	return 0;
}
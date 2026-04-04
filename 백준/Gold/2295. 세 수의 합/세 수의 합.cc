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
int arr[1007];

unordered_set<int> xysum;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int mx = -1;

	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			xysum.insert(arr[i] + arr[j]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			auto result = xysum.find(arr[i] - arr[j]);
			if (result != xysum.end())
				mx = max(mx, *result + arr[j]);
		}


	cout << mx;

	return 0;
}

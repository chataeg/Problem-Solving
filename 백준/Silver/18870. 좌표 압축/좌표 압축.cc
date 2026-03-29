#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	
	vector<int> origin(n);
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> origin[i];
		v[i] = origin[i];
	}

	sort(v.begin(), v.end());

	v.erase(unique(v.begin(), v.end()), v.end());
	
	for (auto iter : origin)
		cout << lower_bound(v.begin(), v.end(), iter) - v.begin() << " ";

	return 0;
}

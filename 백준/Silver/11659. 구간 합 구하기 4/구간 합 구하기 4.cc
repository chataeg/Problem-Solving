#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int n, m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	vector<int> v(n, 0);
	vector<int> cumul(n, 0);

	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;

		v[i] = input;
		if (i == 0)
			cumul[i] = input;
		else
			cumul[i] = cumul[i-1] + input;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;

		cin >> a >> b;

		cout << cumul[b-1] - cumul[a-1] + v[a-1] << '\n';
	}
	

	
	return 0;
}

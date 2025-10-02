#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int t;

multiset<int> m;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int k;
		cin >> k;

		for (int j = 0; j < k; j++)
		{
			char c; int input;
			cin >> c >> input;

			if (c == 'I')
			{
				m.insert(input);
			}
			else if (c == 'D')
			{
				if (m.empty()) continue;

				if (input == 1) m.erase(--m.end());
				else m.erase(m.begin());
			}
		}
	
		if (!m.empty())
		{
			auto mnit = m.begin();
			auto mxit = --m.end();

			cout << *mxit << " " << *mnit << '\n';
		}
		else
		{
			cout << "EMPTY" << '\n';
		}

		m.clear();
	}


	return 0;
}
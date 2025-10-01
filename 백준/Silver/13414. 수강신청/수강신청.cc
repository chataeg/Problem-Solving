#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

unordered_multimap<string, list<string>::iterator> um;
list<string> students;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k, l;
	cin >> k >> l;

	for (int i = 0; i < l; i++)
	{
		string input;
		cin >> input;

		auto finditer = um.find(input);
		if (finditer != um.end())
		{
			students.erase(finditer->second);
		}


		students.push_back(input);
		um.insert({input, prev(students.end())});

	}

	int cnt = 0;
	for (string iter : students)
	{
		if (cnt >= k) break;
		cout << iter << '\n';
		cnt++;
	}


	return 0;
}
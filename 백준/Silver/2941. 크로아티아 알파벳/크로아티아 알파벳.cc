#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <istream>

using namespace std;

string cro[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string input;
	getline(cin, input);

	int pos = 0;
	int crocnt = 0; 

	for (auto iter : cro)
	{
		while (true)
		{
			int result = input.find(iter);
			if (result != -1) input.replace(result, iter.size(), "#");
			else break;
		}
	}

	cout << input.size();


	return 0;
}
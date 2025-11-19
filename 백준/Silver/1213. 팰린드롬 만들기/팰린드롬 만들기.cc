#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int arr[26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;

    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        arr[str[i] - 'A']++;
    }

    

    char center = ' ';
    int oddnum = 0;
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] % 2 == 1)
        {
            oddnum++;
            center = 'A' + i;
        }
    }

    if (oddnum > 1)
    {
        cout << "I'm Sorry Hansoo";
        return 0;
    }

    string left = "";

    for (int i = 0; i < 26; i++)
        for (int j = 0; j < arr[i]/2; j++)
            left += 'A' + i;
    
    string right = left;

    reverse(right.begin(), right.end());

    cout << left;
    if (oddnum == 1) cout << center;
    cout << right;

    return 0;
}
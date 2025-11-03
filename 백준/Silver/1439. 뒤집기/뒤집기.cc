#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <deque>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);


    string input;

    cin >> input;

    int cnt[2] = { 0,0 };

    int cur = input[0] - '0';
    cnt[input[0] - '0']++;

    for (int i = 1; i < input.size(); i++)
    {
        if (input[i] - '0' != cur)
        {
            cnt[input[i] - '0']++;
            cur = input[i] - '0';
        }
    }

    cout << (cnt[0] < cnt[1] ? cnt[0] : cnt[1]);
   

    return 0;
}
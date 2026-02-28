#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <deque>
#include <map>
#include <set>
#include <algorithm>
#include <bitset>
#include <iostream>

using namespace std;

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;

    string input;

    cin >> input;
    long long ans = 0;
    for (int i = 0; i < input.size(); i++)
    {
        ans += input[i] - '0';
    }
    
    cout << ans;


    return 0;
}

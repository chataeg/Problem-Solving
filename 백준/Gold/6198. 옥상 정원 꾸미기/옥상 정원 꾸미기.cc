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

    stack<int> s; 
    long long cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        
        if (s.empty() && i == 0)
        {
            s.push(input);
            continue;
        }

        while (!s.empty() && s.top() <= input)
        {
            s.pop();
        }

        cnt += s.size();

        s.push(input);

    }

    cout << cnt;


    return 0;
}

#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <iostream>


using namespace std;

#define MAX 100007
/*
* 숨바꼭질 3
* 
* 
* 
*/

int n, k;
int cnt;
int vis[MAX];

bool inrange(int in)
{
    return in <= MAX && in >= 0;
}

void solve()
{
    deque<pair<int,int>> dq;

    dq.push_back({n,0});
    vis[n] = 1;
    
    while (!dq.empty())
    {
        auto cur = dq.front();
        dq.pop_front();
        vis[cur.first] = 1;

        if (!inrange(cur.first)) continue;

        if (cur.first == k)
        {
            cout << cur.second;
            return;
        }

        if (inrange(cur.first * 2) && !vis[cur.first * 2])
        {
            dq.push_front({ cur.first * 2 , cur.second});
        }
        if (inrange(cur.first + 1) && !vis[cur.first + 1])
        {
            dq.push_back({ cur.first + 1,cur.second + 1 });
        }
        if (inrange(cur.first - 1) && !vis[cur.first - 1])
        {
            dq.push_back({ cur.first - 1, cur.second + 1 });
        }
    }
   
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    solve();


    return 0;
}

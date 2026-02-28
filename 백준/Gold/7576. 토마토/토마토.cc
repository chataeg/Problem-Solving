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

#define y first
#define x second


int n, m;

int arr[1007][1007];
int dist[1007][1007];

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;

    queue<pair<int, int>> q;


    fill(&dist[0][0], &dist[1006][1007], -1);

    int cnt = 0;

    int tomato = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
            {
                q.push({ i,j });
                dist[i][j] = 0;
            }
            else if (arr[i][j] == 0)
            {
                cnt++;
            }

            if (arr[i][j] != -1)
                tomato++;
        }

    if (cnt == 0)
    {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                q.push({ i,j });
                dist[i][j] = 0;
            }
        }


    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];
        
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

            if (arr[ny][nx] == -1) continue;
            if (dist[ny][nx] != -1) continue;

            dist[ny][nx] = dist[cur.y][cur.x] + 1;
            arr[ny][nx] = 1;
            q.push({ ny,nx });
        }
    }

    int mx = 0;

    int how = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mx = max(mx, dist[i][j]);
            if (arr[i][j] == 1)
                how++;
        }
     
    }

    if (how != tomato)
        cout << -1;
    else
        cout << mx;


    return 0;
}

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

#define x second
#define y first
using namespace std;

int n;
int arr[107][107]; 
int dist[107][107];


int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
queue<pair<int, int>> q;

int mn = 0x7fffffff;

void bfs()
{
    
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();


        for (int dir = 0; dir < 4; dir++)
        {
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];

            if (ny < 0 || nx < 0 || nx >= n || ny >= n) continue;
            
            if (arr[cur.y][cur.x] == 0 && arr[ny][nx] == 1 && dist[ny][nx] == -1)
            {
                mn = min(mn, dist[cur.y][cur.x]);
            }
            
            if (dist[ny][nx] != -1) continue;

            dist[ny][nx] = dist[cur.y][cur.x] + 1;

            q.push({ ny,nx });
        }
    }

    cout << "";
}


int vis[107][107];

vector<pair<int, int>> findisland(int sty, int stx)
{
   vector < pair<int, int>> v;

   queue < pair<int, int>>q;
   q.push({ sty,stx });
   v.push_back({ sty,stx });

   while (!q.empty())
   {
       auto cur = q.front();
       q.pop();

       for (int dir = 0; dir < 4; dir++)
       {
           int ny = cur.y + dy[dir];
           int nx = cur.x + dx[dir];

           if (ny < 0 || nx < 0 || nx >= n || ny >= n) continue;
           if (arr[ny][nx] == 0 || vis[ny][nx] == 1) continue;


           v.push_back({ ny,nx });
           q.push({ ny,nx });
           vis[ny][nx] = 1;
       }
   }
   
   return v;

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];


    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (!vis[i][j] && arr[i][j] == 1)
            {
                auto result = findisland(i, j);

                if (!result.empty())
                {

                    fill(&dist[0][0], &dist[106][107], -1);

                    for (auto iter : result)
                    {
                        q.push({ iter.first,iter.second });
                        dist[iter.first][iter.second] = 0;
                    }

                    bfs();
                }
            }
        }


    cout << mn;
   
    return 0;
}

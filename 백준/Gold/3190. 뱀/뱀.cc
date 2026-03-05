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


int n, k, l;

int arr[101][101];
int dist[101][101];

int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

deque<pair<int, char>> rot;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int y, x;
        cin >> y >> x;
        arr[y][x] = 1;
    }

    cin >> l;

    for (int i = 0; i < l; i++)
    {
        int e;
        char c;
        cin >> e >> c;

        rot.push_back({ e,c });
    }

    arr[1][1] = -1;

    int time = 0;
    int dir = 0;
    int cury = 1;
    int curx = 1;

    deque<pair<int, int>> body;
    body.push_back({ 1,1 });

    while (1)
    {
        time++;
        cury = cury + dy[dir];
        curx = curx + dx[dir];

        if (cury <= 0 || curx <= 0 || curx > n || cury > n || arr[cury][curx] == -1)
        {
            break; 
        }

        if (arr[cury][curx] != 1)
        {
            arr[body.front().y][body.front().x] = 0;
            body.pop_front();
        }

        body.push_back({ cury,curx });
        arr[cury][curx] = -1;

        for (auto iter : rot)
        {
            if (time == iter.first)
            {
                if (iter.second == 'D')
                    dir = (dir + 1) % 4;
                else
                    dir = (dir - 1 + 4) % 4;

                rot.pop_front();
                break;
            }
        }
    }

    cout << time;


    return 0;
}

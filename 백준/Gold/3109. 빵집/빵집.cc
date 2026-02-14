#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <deque>
#include <map>
#include <algorithm>
#include <bitset>
#include <iostream>

using namespace std;

int dy[3] = {-1,0,1};
int r, c;

char arr[10007][507];
int vis[10007][507];

int cnt;

void print()
{
    cout << "=================================" << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }

}

bool bfs(int y, int x)
{
    vis[y][x] = 1;
    
    if (x == c - 1)
    {
        cnt++;
        return true;
    }
    
    for (int dir = 0; dir < 3; dir++)
    {
        int ny = y + dy[dir];
        int nx = x + 1;

        if (arr[ny][nx] == 'x' || vis[ny][nx]) continue;
        if (nx < 0 || nx >= c || ny < 0 || ny >= r) continue;
        if(bfs(ny, nx)) return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < input.length(); j++)
            arr[i][j] = input[j];
    }
    int mx = 0;

    for (int i = 0; i < r; i++)
        bfs(i, 0);
    
    cout << cnt;

    return 0;
}

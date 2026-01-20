#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <deque>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int n, m;
int x, y;
int k;

int arr[20][20];

int dy[5] = { 0,0,0,-1,1 };
int dx[5] = { 0,1,-1,0,0 };

vector<int> dice(7); //index 1 윗면, 2 북쪽면, 3 동쪽면, 4 서쪽면, 5 남쪽면, 6 아랫면

void roll(int dir)
{
    if (dir == 1)
    {
        dice = { 0, dice[4],dice[2],dice[1],dice[6],dice[5],dice[3] };
    }
    else if (dir == 2)
    {
        dice = { 0, dice[3],dice[2],dice[6],dice[1],dice[5],dice[4] };
    }
    else if (dir == 3)
    {
        dice = { 0, dice[5],dice[1],dice[3],dice[4],dice[6],dice[2] };
    }
    else if (dir == 4)
    {
        dice = { 0, dice[2],dice[6],dice[3],dice[4],dice[1],dice[5] };
    }
}


int main()
{
    cin >> n >> m >> y >> x >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    
    int cur = 6;

    while (k--)
    {
        int input; 
        cin >> input;

        int ny = y + dy[input];
        int nx = x + dx[input];

        if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

        roll(input);

        if (arr[ny][nx] != 0)
        {
            dice[6] = arr[ny][nx];
            arr[ny][nx] = 0;
        }
        else
        {
            arr[ny][nx] = dice[6]; 
        }

        y = ny;
        x = nx;

        cout << dice[1] << endl;
    }
    

    return 0;
}

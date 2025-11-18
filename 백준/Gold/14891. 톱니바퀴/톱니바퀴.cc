#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int wheel[4][8];

int st0, st1, st2, st3;

// 0     1      2      3
//  2  6   2  6  2    6  

void cw(int st,int prev);

void ccw(int st, int prev)
{
    switch (st)
    {
    case 0:

        if (prev != 1 && wheel[0][(st0 + 2) % 8] != wheel[1][(st1 + 6) % 8])
            cw(1,0);
        st0 = (st0 + 1) % 8;
        break;
    case 1:

        if (prev != 0 && wheel[0][(st0 + 2) % 8] != wheel[1][(st1 + 6) % 8])
            cw(0,1);
        if (prev != 2 && wheel[1][(st1 + 2) % 8] != wheel[2][(st2 + 6) % 8])
            cw(2,1);
        st1 = (st1 + 1) % 8;
        break;
    case 2:
        if (prev != 1 && wheel[1][(st1 + 2) % 8] != wheel[2][(st2 + 6) % 8])
            cw(1,2);
        if (prev != 3 && wheel[2][(st2 + 2) % 8] != wheel[3][(st3 + 6) % 8])
            cw(3,2);
        st2 = (st2 + 1) % 8;
        break; 
    case 3:
        if (prev != 2 && wheel[2][(st2 + 2) % 8] != wheel[3][(st3 + 6) % 8])
            cw(2,3);
        st3 = (st3 + 1) % 8;
        break;
    }
}
void cw(int st, int prev)
{
    switch (st)
    {
    case 0:
        if (prev != 1 && wheel[0][(st0 + 2) % 8] != wheel[1][(st1 + 6) % 8])
            ccw(1,0);
        st0--;
        if (st0 < 0) st0 = 7;
        break;
    case 1:
        if (prev != 0 && wheel[0][(st0 + 2) % 8] != wheel[1][(st1 + 6) % 8])
            ccw(0,1);
        if (prev != 2 && wheel[1][(st1 + 2) % 8] != wheel[2][(st2 + 6) % 8])
            ccw(2,1);
        st1--;
        if (st1 < 0) st1 = 7;
        break;
    case 2:
        if (prev != 1 && wheel[1][(st1 + 2) % 8] != wheel[2][(st2 + 6) % 8])
            ccw(1,2);
        if (prev != 3 && wheel[2][(st2 + 2) % 8] != wheel[3][(st3 + 6) % 8])
            ccw(3,2);
        st2--;
        if (st2 < 0) st2 = 7;
        break;
    case 3:
        if (prev != 2 && wheel[2][(st2 + 2) % 8] != wheel[3][(st3 + 6) % 8])
            ccw(2,3);
        st3--;
        if (st3 < 0) st3 = 7;
        break;
    }
}

void solve(int num, int dir)
{
    if (dir == 1)
        cw(num,num);
    else
        ccw(num,num);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int t = 0 ; t < 4 ; t++)
    {
        string input;
        cin >> input;
        for (int i = 0; i < input.size(); i++)
            wheel[t][i] = input[i] - '0';
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int num, dir;
        cin >> num >> dir;
        solve(num-1,dir);
    }

    int ans = 0;

    if (wheel[0][st0] == 1)
        ans += 1;

    if (wheel[1][st1] == 1)
        ans += 2;

    if (wheel[2][st2] == 1)
        ans += 4;

    if (wheel[3][st3] == 1)
        ans += 8;

    cout << ans;


    return 0;
}
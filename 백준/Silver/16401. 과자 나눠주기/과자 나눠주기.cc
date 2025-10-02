#include <bits/stdc++.h>
using namespace std;

int M, N;
vector<int> v;

bool solve(int num)
{
    if (num == 0) return true;
    long long cnt = 0;
    for (int i = 0; i < N; i++)
        cnt += v[i] / num;
    return cnt >= M; 
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> M >> N;

    for (int i = 0; i < N; i++)
    {
        int input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    long long st = 0, ed = *max_element(v.begin(), v.end());

    long long mid;

    while (st < ed)
    {
        mid = (st + ed + 1) / 2;
        if (solve(mid)) st = mid ;
        else ed = mid - 1;
    }
       
    cout << st;

    return 0;

}
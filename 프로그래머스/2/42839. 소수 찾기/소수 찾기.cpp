#include <string>
#include <vector>
#include <set>

using namespace std;

bool isprime(int num)
{
    if (num == 0) return false;
    if (num == 2 || num == 3) return true;

    for (int i = 5; i * i <= num; i++)
        if (num % i == 0) return false;

    return true;
}

int arr[10000007];

int num[8];
int vis[8];
int cnt = 0;
int n = 0;

set<int> s;

int targetdepth = 0;
int cur = 0;

void solve(int depth, int ind)
{
    if (depth == targetdepth)
    {
        if (arr[cur]) s.insert(cur); 
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (vis[i]) continue;
        vis[i] = true;
        cur = cur * 10 + num[i];

        solve(depth + 1, ind + 1);

        vis[i] = false;
        cur = cur / 10;
    }


}


int solution(string numbers) {
    int answer = 0;

    fill(arr, arr + 10000007, 1);
    arr[0] = 0;
    arr[1] = 0;

    for (int i = 2; i * i <= 10000007; i++)
    {
        if (!arr[i]) continue;
        for (int j = 2; i * j <= 10000007; j++)
            arr[i * j] = false;
    }

    n = numbers.length();
    for (int i = 0; i < numbers.length(); i++)
        num[i] = numbers[i] - '0';

    for (int i = 1; i <= n; i++)
    {
        targetdepth = i;
        solve(0, 0);
    }

    answer = s.size();

    return answer;
}

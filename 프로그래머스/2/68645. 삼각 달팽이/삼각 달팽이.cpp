#include <string>
#include <vector>

using namespace std;

int dy[3] = {1, 0, -1};
int dx[3] = {0, 1, -1};

vector<int> solution(int n) {
    vector<int> answer;
    
    vector<vector<int>> v(n);
    
    for(int i = 0 ; i < n ; i++)
        v[i].resize(i+1);
    
    // 0 10 20 30 31 32 33 22 22 21 
    
    int cury = -1;
    int curx = 0;
    int cnt = 0;

    int dir = 0;
    
    for(int i = n ; i > 0; i--)
    {
        for(int j = 0 ; j < i ; j++)
        {
            cury += dy[dir];
            curx += dx[dir];
            v[cury][curx] = ++cnt;
        }
        dir = (dir+1) % 3;
    }   

    for(int i = 0 ; i < n; i++)
        for(int j = 0 ; j <= i ; j++)
            answer.push_back(v[i][j]);
    
    
    return answer;
}
#include<vector>
#include<queue>
using namespace std;

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int dist[105][105];

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    
    queue<pair<int,int>> q;
    
    fill(&dist[0][0], &dist[104][105],-1);
    
    q.push({0,0});
    dist[0][0] = 1;
    
    int m = maps[0].size();
    int n = maps.size();
    
    
    while(!q.empty())
    {
        auto cur = q.front();
        q.pop();
        
        if(cur.first == n-1 && cur.second == m-1)
            break;
        
        for(int dir = 0 ; dir < 4 ; dir++)
        {
            int ny = cur.first + dy[dir];
            int nx = cur.second + dx[dir];
            
            if(nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue;
            
            
            if(maps[ny][nx] == 0) continue;
            
            if(dist[ny][nx] == -1)
            {
                dist[ny][nx] = dist[cur.first][cur.second] + 1;
                q.push({ny,nx});
            }
        }
        
    }
    
    if(dist[n-1][m-1] == -1)
        answer = -1;
    else answer = dist[n-1][m-1];
    
    
    
    
    return answer;
}
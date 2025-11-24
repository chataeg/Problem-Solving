#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> g[200];
int dist[200];
int mn = 100;

int gn;


int bfs(int start)
{
    int cnt = 1; 
    queue<int> q;
    q.push(start);
    dist[start] = 1;
    
    while(!q.empty())
    {
        auto cur = q.front();
        q.pop();
        
        for(auto iter : g[cur])
        {
            if(!dist[iter])
            {
                cnt++;
                q.push(iter);
                dist[iter] = 1;
            }
        }
    }
    
    return cnt;
}


int solution(int n, vector<vector<int>> wires) {
    
    gn = n;
    for(int k = 0 ; k < n-1 ; k++)
    {
        for(int i = 0 ; i < n; i++)
            g[i].clear();
        
        
        fill(dist,dist + n,0);
        
        for(int i = 0 ; i < n-1 ; i++)
        {
            if(i == k) continue;
            
            int a = wires[i][0]-1;
            int b = wires[i][1]-1;

            g[a].push_back(b);
            g[b].push_back(a);
            
        }   
        
        int st1 = wires[k][0]-1;
        int st2 = wires[k][1]-1;
        
        int bfs1 = bfs(st1);
        
        fill(dist,dist + n,0);
        int bfs2 = bfs(st2);
        
        mn = min(mn, abs(bfs1-bfs2));
    }
    
    return mn;
        
    
    
    
}
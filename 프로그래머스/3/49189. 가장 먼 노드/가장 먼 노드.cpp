#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> adj[20007];
int dist[200007];

int solve(int start)
{
    fill(dist,dist + 20007,-1);
    queue<int> q;
    q.push(start);
    dist[start]++; 
    
    while(!q.empty())
    {
        auto cur = q.front();
        q.pop();
    
        for(auto iter : adj[cur])
        {
        
            if(dist[iter] == -1)
            {
                dist[iter] = dist[cur] +1;
                q.push(iter);
            }
        
        }
    }
    
    int mx = *max_element(dist,dist+20007);
    
    int cnt = 0;
    
    for(auto iter : dist)
    {
        if(iter == mx)
            cnt++;
    }
    
    return cnt; 
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
        
    for(auto iter : edge)
    {
        int a = iter[0];
        int b = iter[1];
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    answer = solve(1);
    
    
    
    return answer;
}
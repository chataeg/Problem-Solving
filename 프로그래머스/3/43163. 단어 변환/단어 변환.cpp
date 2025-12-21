#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
string gtarget;
vector<string> v;
queue<pair<string,int>> q;
int vis[100];
int ans;

bool cmp(const string& a, const string& b)
{
    int cnt = 0;
    for(int i = 0 ; i < a.length() ; i++)
        if(a[i] == b[i]) cnt++;
    
    if(cnt == a.length() - 1) return true;
    return false;
}


int solve(string cur)
{
    q.push({cur,0});
    
    
    while(!q.empty())
    {
        auto qcur = q.front();
        q.pop();
        
        if(qcur.first == gtarget)
            return qcur.second;
        
        if(qcur.second >= v.size())
        {
            continue;
        }
        
        for(auto iter : v)
        {
            if(cmp(qcur.first,iter))
                q.push({iter,qcur.second + 1});
        }
        
    }
    
    return 0;
}


int solution(string begin, string target, vector<string> words) {

    v = words;
    gtarget = target;
    
    return solve(begin);
    
    
    
}
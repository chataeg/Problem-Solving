#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

int sze = 0;

unordered_map<string, vector<string>> um;
unordered_map<string,bool> vis;
vector<string> answer;
vector<string> v;

bool solve(string cur, int num)
{
    answer.push_back(cur);
    if(num == sze) 
    {
        v = answer;
        return true;
    }
    
    for(int i = 0 ; i < um[cur].size(); i++)
    {
        auto nxt = um[cur].at(i);
        um[cur].erase(um[cur].begin() + i);
        
        if(solve(nxt,num+1))
            return true;
        
        um[cur].insert(um[cur].begin()+i,nxt);
        answer.pop_back();
    }
    return false;
}


vector<string> solution(vector<vector<string>> tickets) {
    
    set<string> st;
    
    for(auto y : tickets)
        for(auto x : y)
            st.insert(x);
    
    sze = tickets.size();
    
    for(auto iter : st)
    {
        um.insert({iter,vector<string>()});
        vis[iter] = false;        
    }

    for(auto iter : tickets)
    {
        um[iter[0]].push_back(iter[1]);
    }
    
    for(auto iter : st)
        sort(um.at(iter).begin(), um.at(iter).end());
    
   
    solve("ICN",0);
    

    return v;
}
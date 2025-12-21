#include <string>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

string target;
string itoc = "AEIOU";
int ans;
int cnt;

void solve(string cur)
{   

    if(cur == target)
    {
        ans = cnt;
        return;
    }
    
    if(cur.length() >= 5)
    {
        return;
    }
    
 
    
    for(int i = 0 ; i < 5 ; i++)
    { 
        if(ans != 0) return;
        
        cnt++;
        solve(cur + itoc[i]);
    }
}


int solution(string word) {
 
    target = word;
    solve("");
    
    return ans;
}
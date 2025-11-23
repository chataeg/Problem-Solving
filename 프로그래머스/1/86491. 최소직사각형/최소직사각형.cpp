#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int mn = INT_MAX;
int n;



int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    n = sizes.size();
    
    // 가로를 가장 길게, 세로를 가장 짧게
    
    int maxw = 0, maxh = 0;
    
    for(int i = 0 ; i < n ; i++)
    {
        int w = sizes[i][0];
        int h = sizes[i][1];
        
        
        int curw = max(w,h);
        int curh = min(w,h);
        
        maxw = max(maxw, curw);
        maxh = max(maxh, curh);
    }
    
    answer= maxw * maxh;
    
    
    
    
    
    return answer;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    
    for(int i = 0 ; i < commands.size(); i++)
    {
        int st,ed, k;
        st = commands[i][0] - 1;
        ed = commands[i][1] - 1;
        k = commands[i][2]- 1;
        vector<int> tmp;
        for(int j = st ; j <= ed ; j++)
            tmp.push_back(array[j]);
        
        sort(tmp.begin(),tmp.end());
        
        answer.push_back(tmp[k]);
    }
    
    
    
    return answer;
}
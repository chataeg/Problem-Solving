#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<int> q;
    
    int size = progresses.size();
    for(int i = 0 ; i < size; i++)
    {
        int day = 0;
        while(progresses[i] < 100)
        {
            day++;
            progresses[i] +=speeds[i];
            
        }
        q.push(day);
        
    }
    
   
    while(!q.empty())
    {
        int d = q.front(), p = 1;
        q.pop();
        
        while((!q.empty()) && (q.front() <= d))
        {
            q.pop();
            p++;
        }
        
        answer.push_back(p);
    }
    
    
    return answer;
}
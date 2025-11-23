#include <string>
#include <vector>

using namespace std;
vector<int> tmp;
int n;
int cnt = 0;
int gtarget;
void solve(int depth, int cur)
{
    if(depth == n)
    {
        if (cur == gtarget) cnt++;
        return;
    }
    
    solve(depth+1, cur + tmp[depth]);
    solve(depth+1, cur - tmp[depth]);

}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    tmp = numbers;
    n = tmp.size();
    gtarget = target;
    
    solve(0,0);
    
    answer = cnt;
    
    return answer;
}
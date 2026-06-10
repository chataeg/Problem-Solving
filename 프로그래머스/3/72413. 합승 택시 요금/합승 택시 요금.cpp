#include <string>
#include <vector>
#include <tuple>
#include <queue>


using namespace std;

int vertex[207];

long long arr[207][207];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    long long answer = 0;

    for(int i = 1 ; i <= n;  i ++)
        for(int j = 1; j <= n; j++)
        {    
            if(i == j) continue;
            arr[i][j] = 0x3f3f3f3f;  
        }
    
    for (int i = 0; i < fares.size(); i++)
    {
        arr[fares[i][0]][fares[i][1]] = fares[i][2];
        arr[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    
    for(int k = 1; k <= n ; k++)
    {
        for(int from = 1; from <= n ; from++)
        {
            for(int to = 1; to <= n ; to++)
            {
                if(arr[from][to] > arr[from][k] + arr[k][to])
                    arr[from][to] = arr[from][k] + arr[k][to];
            }
        }
    }
    
    answer = arr[s][a] + arr[s][b];
    
    for(int i = 1; i <= n ; i++)
        answer = min(answer, arr[s][i] + arr[i][a] + arr[i][b]);
    
    return answer;
}
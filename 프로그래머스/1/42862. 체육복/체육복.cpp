#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int arr[31];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    for(int i = 0 ; i < lost.size(); i++)
    {
        for(int j = 0 ; j < reserve.size() ; j++)
        {
            if(lost[i] == reserve[j])
            {
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + j);
                i--;
                j--;
            }
        }
    }
    
    
    answer = n - lost.size();
    
    for(int i = 0; i < reserve.size() ; i++)
        arr[reserve[i]] = true;
    
    for(int i = 0; i < lost.size() ; i++)
    {
        if(lost[i] == 1)
        {
            if(arr[lost[i]+1] == true)
            {
                answer++;
                arr[lost[i]+1] = false;
            }
        }
        else if(lost[i] == n)
        {
            if(arr[lost[i]-1] == true)
            {
                answer++;
                
                arr[lost[i]-1] = false;
            }
        }
        else
        {
            if(arr[lost[i]-1])
            {
                arr[lost[i]-1] = false;
                answer++;
                
            }
            else if(arr[lost[i]+1])
            {
                arr[lost[i]+1] = false;
                answer++;
            }
        }
    }
    
    return answer;
}
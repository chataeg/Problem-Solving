#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int m1[5] = {1,2,3,4,5};
int m2[8] = {2,1,2,3,2,4,2,5};
int m3[10] = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    //12345
    //21232425
    //3311224455
    
    int m[3] = {0,0,0};
    
    for(int i = 0 ; i < answers.size() ; i++)
    {
        m[0] += (answers[i] == m1[i%5]);
        
        m[1] += (answers[i] == m2[i%8]);
        
        m[2] += (answers[i] == m3[i%10]);
    }
    
    int mx = *max_element(m,m+3);

    for(int i = 0 ; i < 3; i ++)
    {
        if(m[i] == mx)
            answer.push_back(i+1);
    }
    
    sort(answer.begin(),answer.end());
    

    return answer;
}
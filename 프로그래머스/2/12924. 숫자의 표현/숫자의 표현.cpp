
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;


    int base = 1;
    while(base <= n)
    {
         int tmp = 0;
        for(int i = base ; i <= n ; i++)
        {

            tmp +=i;
            if(tmp > n)
            {
                base++;
                break;
            }
            else if(tmp == n )
            {
                answer++;
                base++;
            }
         }
    }




    return answer;
}

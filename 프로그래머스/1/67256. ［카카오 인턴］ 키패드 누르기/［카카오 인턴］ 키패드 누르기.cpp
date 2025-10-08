#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
	string answer = "";

	struct POINT {
		int x;
		int y;
	};

	POINT lh, rh;

	lh.x = 3;
	lh.y = 0;

	rh.x = 3;
	rh.y = 2;

	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == 1 || 
			numbers[i] == 4 ||
			numbers[i] == 7 )
		{
			answer += "L";
			lh.x = (numbers[i]-1) / 3;
			lh.y = 0;
		}
		else if (numbers[i] == 3 ||
			numbers[i] == 6 ||
			numbers[i] == 9)
		{
			answer += "R";
			rh.x = (numbers[i] - 1) / 3;
			rh.y = 2;
		}
		else
		{
			auto posx = (numbers[i] - 1) / 3;
			auto posy = 1;

			if (numbers[i] == 0)
			{
				posx = 3;
				posy = 1;
			}

		
				if (abs(posx - lh.x) + abs(posy - lh.y) < abs(posx - rh.x) + abs(posy - rh.y))
				{
					answer += "L";
					lh.x = posx;
					lh.y = posy;
				}
				else if (abs(posx - lh.x) + abs(posy - lh.y) > abs(posx - rh.x) + abs(posy - rh.y))
				{

					answer += "R";
					rh.x = posx;
					rh.y = posy;
				}
				else
				{
					if (hand == "right")
					{
						answer += "R";
						rh.x = posx;
						rh.y = posy;
					}
					else
					{

						answer += "L";
						lh.x = posx;
						lh.y = posy;
					}
				}
				
		}


	}


	return answer;
}
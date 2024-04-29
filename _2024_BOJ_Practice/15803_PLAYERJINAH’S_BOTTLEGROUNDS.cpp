#include <iostream>
using namespace std;

bool line = true;
double pos[3][2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 3; ++i)
		cin >> pos[i][0] >> pos[i][1];

	if ((pos[0][0] == pos[1][0] && pos[0][0] == pos[2][0])
		|| (pos[0][1] == pos[1][1] && pos[0][1] == pos[2][1]))
		line = false;
	else if ((double)((pos[0][0] - pos[1][0]) / (pos[0][1] - pos[1][1])) == (double)((pos[0][0] - pos[2][0]) / (pos[0][1] - pos[2][1])))
		line = false;

	if (line)
		cout << "WINNER WINNER CHICKEN DINNER!";
	else
		cout << "WHERE IS MY CHICKEN?";
	return 0;
}
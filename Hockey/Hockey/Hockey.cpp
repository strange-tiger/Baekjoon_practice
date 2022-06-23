#include <iostream>

struct Pos
{
	int x;
	int y;
};

int d_distance(Pos A, Pos B)
{
	int dist = (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);

	return dist;
}

bool pointInCircle(int dist, int d_rad)
{
	return dist <= d_rad;
}

int main()
{
	int W;
	int H;
	int X;
	int Y;
	int P;
	std::cin >> W >> H >> X >> Y >> P;
	int R = H / 2;

	Pos* player = new Pos[P];
	Pos lCircle = { X, Y + R };
	Pos rCircle = { X + W, Y + R };

	int count = 0;
	for (int i = 0; i < P; i++)
	{
		std::cin >> player[i].x >> player[i].y;
	}

	for (int i = 0; i < P; i++)
	{
		if (player[i].x >= X && player[i].x <= X + W)
		{
			if (player[i].y >= Y && player[i].y <= Y + H)
			{
				count++;
			}
		}
		else if (player[i].x < X)
		{
			bool inLCircle = pointInCircle(d_distance(player[i], lCircle), R * R);

			if (inLCircle)
			{
				count++;
			}
		}
		else if (player[i].x > X)
		{
			bool inRCircle = pointInCircle(d_distance(player[i], rCircle), R * R);

			if (inRCircle)
			{
				count++;
			}
		}
	}
	std::cout << count << std::endl;

	return 0;
}
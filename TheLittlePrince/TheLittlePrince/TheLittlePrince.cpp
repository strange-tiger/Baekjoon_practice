#include <iostream>

struct Position
{
	int x;
	int y;
};

struct Prince
{
	Position	s;	// start
	Position	d;	// destination
} prince;

struct Planet
{
	Position	c;	// center
	int			r;	// radius
};

int d_distance(Position A, Position B)
{
	int dist = (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);

	return dist;
}

bool pointInPlanet(int dist, int d_rad)
{
	return dist < d_rad;
}

int main()
{
	int T;
	std::cin >> T;
	for (int test = 0; test < T; test++)
	{
		int count = 0;
		std::cin >> prince.s.x >> prince.s.y >> prince.d.x >> prince.d.y;
		
		int n = 0;
		std::cin >> n;
		if (!n)
			continue;
		
		Planet* planet = new Planet[n];
		for (int num = 0; num < n; num++)
		{
			std::cin >> planet[num].c.x >> planet[num].c.y >> planet[num].r;
		}

		for (int i = 0; i < n; i++)
		{
			bool startInPlanet = pointInPlanet(d_distance(prince.s, planet[i].c), planet[i].r * planet[i].r);
			bool destInPlanet = pointInPlanet(d_distance(prince.d, planet[i].c), planet[i].r * planet[i].r);
			
			if (startInPlanet && destInPlanet)
			{
				continue;
			}
			else if (startInPlanet)
			{
				count++;
			}
			else if (destInPlanet)
			{
				count++;
			}
		}
		
		std::cout << count << std::endl;

		delete[] planet;
	}

	return 0;
}
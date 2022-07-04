#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <utility>
#include <cstring>

int m, n, o, p, q, r, s, t, u, v, w;
bool isVisited[1000000] = {false};
int box[1000000] = {0};
int count[1000000] = {0};

struct Dev
{
	int M;
	int N;
	int O;
	int P;
	int Q;
	int R;
	int S;
	int T;
	int U;
	int V;
	int W;
};

int bfs()
{
	static int dm[] = { 1, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0, -1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 };
	static int dn[] = { 0, 1, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0, -1,  0,  0,  0,  0,  0,  0,  0,  0,  0 };
	static int dO[] = { 0, 0, 1, 0, 0, 0, 0, 0, 0,  0,  0,  0,  0, -1,  0,  0,  0,  0,  0,  0,  0,  0 };
	static int dp[] = { 0, 0, 0, 1, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  0,  0,  0,  0 };
	static int dq[] = { 0, 0, 0, 0, 1, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  0,  0,  0 };
	static int dr[] = { 0, 0, 0, 0, 0, 1, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  0,  0 };
	static int ds[] = { 0, 0, 0, 0, 0, 0, 1, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0,  0 };
	static int dt[] = { 0, 0, 0, 0, 0, 0, 0, 1, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0,  0 };
	static int du[] = { 0, 0, 0, 0, 0, 0, 0, 0, 1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, -1,  0,  0 };
	static int dv[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, -1,  0 };
	static int dw[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, -1 };
	std::queue<Dev> ripe;
	for (int W = 0; W < w; ++W)
	{
		for (int V = 0; V < v; ++V)
		{
			for (int U = 0; U < u; ++U)
			{
				for (int T = 0; T < t; ++T)
				{
					for (int S = 0; S < s; ++S)
					{
						for (int R = 0; R < r; ++R)
						{
							for (int Q = 0; Q < q; ++Q)
							{
								for (int P = 0; P < p; ++P)
								{
									for (int O = 0; O < o; ++O)
									{
										for (int N = 0; N < n; ++N)
										{
											for (int M = 0; M < m; ++M)
											{
												if (1 == box[M + m * N + m * n * O + m * n * o * P + m * n * o * p * Q + m * n * o * p * q * R + m * n * o * p * q * r * S + m * n * o * p * q * r * s * T + m * n * o * p * q * r * s * t * U + m * n * o * p * q * r * s * t * u * V + m * n * o * p * q * r * s * t * u * v * W] && !isVisited[M + m * N + m * n * O + m * n * o * P + m * n * o * p * Q + m * n * o * p * q * R + m * n * o * p * q * r * S + m * n * o * p * q * r * s * T + m * n * o * p * q * r * s * t * U + m * n * o * p * q * r * s * t * u * V + m * n * o * p * q * r * s * t * u * v * W])
												{
													Dev temp;
													temp.M = M;
													temp.N = N;
													temp.O = O;
													temp.P = P;
													temp.Q = Q;
													temp.R = R;
													temp.S = S;
													temp.T = T;
													temp.U = U;
													temp.V = V;
													temp.W = W;
													ripe.push(temp);
													isVisited[M + m * N + m * n * O + m * n * o * P + m * n * o * p * Q + m * n * o * p * q * R + m * n * o * p * q * r * S + m * n * o * p * q * r * s * T + m * n * o * p * q * r * s * t * U + m * n * o * p * q * r * s * t * u * V + m * n * o * p * q * r * s * t * u * v * W] = true;
													count[M + m * N + m * n * O + m * n * o * P + m * n * o * p * Q + m * n * o * p * q * R + m * n * o * p * q * r * S + m * n * o * p * q * r * s * T + m * n * o * p * q * r * s * t * U + m * n * o * p * q * r * s * t * u * V + m * n * o * p * q * r * s * t * u * v * W] = 0;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	int max = 0;
	while (!ripe.empty())
	{
		int M = ripe.front().M;
		int N = ripe.front().N;
		int O = ripe.front().O;
		int P = ripe.front().P;
		int Q = ripe.front().Q;
		int R = ripe.front().R;
		int S = ripe.front().S;
		int T = ripe.front().T;
		int U = ripe.front().U;
		int V = ripe.front().V;
		int W = ripe.front().W;

		ripe.pop();

		if (max < count[M + m * N + m * n * O + m * n * o * P + m * n * o * p * Q + m * n * o * p * q * R + m * n * o * p * q * r * S + m * n * o * p * q * r * s * T + m * n * o * p * q * r * s * t * U + m * n * o * p * q * r * s * t * u * V + m * n * o * p * q * r * s * t * u * v * W])
		{
			max = count[M + m * N + m * n * O + m * n * o * P + m * n * o * p * Q + m * n * o * p * q * R + m * n * o * p * q * r * S + m * n * o * p * q * r * s * T + m * n * o * p * q * r * s * t * U + m * n * o * p * q * r * s * t * u * V + m * n * o * p * q * r * s * t * u * v * W];
		}

		for (int i = 0; i < 22; ++i)
		{
			int _M = M + dm[i];
			int _N = N + dn[i];
			int _O = O + dO[i];
			int _P = P + dp[i];
			int _Q = Q + dq[i];
			int _R = R + dr[i];
			int _S = S + ds[i];
			int _T = T + dt[i];
			int _U = U + du[i];
			int _V = V + dv[i];
			int _W = W + dw[i];


			if (_M*_N*_O*_P*_Q*_R*_S*_T*_U*_V*_W < 1 || _M * _N * _O * _P * _Q * _R * _S * _T * _U * _V * _W > 1000000)
				continue;

			if (!isVisited[_M + m * _N + m * n * _O + m * n * o * _P + m * n * o * p * _Q + m * n * o * p * q * _R + m * n * o * p * q * r * _S + m * n * o * p * q * r * s * _T + m * n * o * p * q * r * s * t * _U + m * n * o * p * q * r * s * t * u * _V + m * n * o * p * q * r * s * t * u * v * _W])
			{
				if (0 == box[_M + m * _N + m * n * _O + m * n * o * _P + m * n * o * p * _Q + m * n * o * p * q * _R + m * n * o * p * q * r * _S + m * n * o * p * q * r * s * _T + m * n * o * p * q * r * s * t * _U + m * n * o * p * q * r * s * t * u * _V + m * n * o * p * q * r * s * t * u * v * _W])
				{
					Dev temp;
					temp.M = _M;
					temp.N = _N;
					temp.O = _O;
					temp.P = _P;
					temp.Q = _Q;
					temp.R = _R;
					temp.S = _S;
					temp.T = _T;
					temp.U = _U;
					temp.V = _V;
					temp.W = _W;
					ripe.push(temp);
					isVisited[_M + m * _N + m * n * _O + m * n * o * _P + m * n * o * p * _Q + m * n * o * p * q * _R + m * n * o * p * q * r * _S + m * n * o * p * q * r * s * _T + m * n * o * p * q * r * s * t * _U + m * n * o * p * q * r * s * t * u * _V + m * n * o * p * q * r * s * t * u * v * _W] = true;
					box[_M + m * _N + m * n * _O + m * n * o * _P + m * n * o * p * _Q + m * n * o * p * q * _R + m * n * o * p * q * r * _S + m * n * o * p * q * r * s * _T + m * n * o * p * q * r * s * t * _U + m * n * o * p * q * r * s * t * u * _V + m * n * o * p * q * r * s * t * u * v * _W] = 1;

					count[_M + m * _N + m * n * _O + m * n * o * _P + m * n * o * p * _Q + m * n * o * p * q * _R + m * n * o * p * q * r * _S + m * n * o * p * q * r * s * _T + m * n * o * p * q * r * s * t * _U + m * n * o * p * q * r * s * t * u * _V + m * n * o * p * q * r * s * t * u * v * _W] = count[M + m * N + m * n * O + m * n * o * P + m * n * o * p * Q + m * n * o * p * q * R + m * n * o * p * q * r * S + m * n * o * p * q * r * s * T + m * n * o * p * q * r * s * t * U + m * n * o * p * q * r * s * t * u * V + m * n * o * p * q * r * s * t * u * v * W] + 1;
				}
			}
		}
	}

	return max;
}

int main()
{
	std::memset(isVisited, 0, 1000000 * sizeof(bool));
	std::memset(box, 0, 1000000 * sizeof(int));
	std::memset(count, 0, 1000000 * sizeof(int));

	scanf("%d %d %d %d %d %d %d %d %d %d %d", &m, &n, &o, &p, &q, &r, &s, &t, &u, &v, &w);

	for (int W = 0; W < w; ++W)
	{
		for (int V = 0; V < v; ++V)
		{
			for (int U = 0; U < u; ++U)
			{
				for (int T = 0; T < t; ++T)
				{
					for (int S = 0; S < s; ++S)
					{
						for (int R = 0; R < r; ++R)
						{
							for (int Q = 0; Q < q; ++Q)
							{
								for (int P = 0; P < p; ++P)
								{
									for (int O = 0; O < o; ++O)
									{
										for (int N = 0; N < n; ++N)
										{
											for (int M = 0; M < m; ++M)
											{
												scanf("%d", &box[M + m * N + m * n * O + m * n * o * P + m * n * o * p * Q + m * n * o * p * q * R + m * n * o * p * q * r * S + m * n * o * p * q * r * s * T + m * n * o * p * q * r * s * t * U + m * n * o * p * q * r * s * t * u * V + m * n * o * p * q * r * s * t * u * v * W]);

												if (-1 == box[M + m * N + m * n * O + m * n * o * P + m * n * o * p * Q + m * n * o * p * q * R + m * n * o * p * q * r * S + m * n * o * p * q * r * s * T + m * n * o * p * q * r * s * t * U + m * n * o * p * q * r * s * t * u * V + m * n * o * p * q * r * s * t * u * v * W])
												{
													isVisited[M + m * N + m * n * O + m * n * o * P + m * n * o * p * Q + m * n * o * p * q * R + m * n * o * p * q * r * S + m * n * o * p * q * r * s * T + m * n * o * p * q * r * s * t * U + m * n * o * p * q * r * s * t * u * V + m * n * o * p * q * r * s * t * u * v * W] = true;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	int max = 0;
	max = bfs();

	bool able = true;

	for (int W = 0; W < w; ++W)
	{
		for (int V = 0; V < v; ++V)
		{
			for (int U = 0; U < u; ++U)
			{
				for (int T = 0; T < t; ++T)
				{
					for (int S = 0; S < s; ++S)
					{
						for (int R = 0; R < r; ++R)
						{
							for (int Q = 0; Q < q; ++Q)
							{
								for (int P = 0; P < p; ++P)
								{
									for (int O = 0; O < o; ++O)
									{
										for (int N = 0; N < n; ++N)
										{
											for (int M = 0; M < m; ++M)
											{
												if (!isVisited[M + m * N + m * n * O + m * n * o * P + m * n * o * p * Q + m * n * o * p * q * R + m * n * o * p * q * r * S + m * n * o * p * q * r * s * T + m * n * o * p * q * r * s * t * U + m * n * o * p * q * r * s * t * u * V + m * n * o * p * q * r * s * t * u * v * W])
												{
													able = false;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	if (able)
		printf("%d\n", max);
	else
		printf("-1\n");

	return 0;
}
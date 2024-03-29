#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
using namespace std;

double length(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double ans = 0;
    ans += sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    ans += sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));

    return ans * 2.0;
}

bool check(double x1, double y1, double x2, double y2, double x3, double y3)
{
    if ((x2 - x1) * (y3 - y1) == (y2 - y1) * (x3 - x1))
        return false;
    return true;
}

vector<double> x(3);
vector<double> y(3);
vector<double> ans(3);
int main()
{
    for (int i = 0; i < 3; i++)
        scanf("%lf %lf", &x[i], &y[i]);

    if (!check(x[0], y[0], x[1], y[1], x[2], y[2]))
    {
        printf("-1.0");
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            ans[i] = length(x[i], y[i], x[(i + 1) % 3], y[(i + 1) % 3], x[(i + 2) % 3], y[(i + 2) % 3]);
        }

        sort(ans.begin(), ans.end());

        printf("%.10lf\n", ans[2] - ans[0]);
    }
    
    return 0;
}
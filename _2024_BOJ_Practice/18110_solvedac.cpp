#include <iostream>
#include <queue>
using namespace std;

int N = 0;
int j = 0;
int cut = 0;
int cutCnt = 0;
float fCut;

priority_queue<int, vector<int>, greater<int>> bigPq;
priority_queue<int> smallPq;

int diffSum = 0;
int sumGrade = 0;
float fResult;

int diff = 0;

int main()
{
	cin >> N;

	if (N == 0)
	{
		cout << sumGrade;
		return 0;
	}

	fCut = N * 0.15f;
	cut = (int) fCut;

	if (fCut - cut >= 0.5f)
		++cut;

	while (N > j)
	{
		++j;

		cin >> diff;
		
		bigPq.push(diff);
		smallPq.push(diff);

		if (cutCnt < cut)
		{
			++cutCnt;

			continue;
		}
		else if (cutCnt < 2 * cut)
		{
			++cutCnt;

			bigPq.pop();
			smallPq.pop();
			
			continue;
		}

		if (bigPq.top() == smallPq.top())
			diffSum += diff;
		else if (diff != bigPq.top())
			diffSum += bigPq.top();
		else if (diff != smallPq.top())
			diffSum += smallPq.top();

		bigPq.pop();
		smallPq.pop();
	}

	fResult = (float) diffSum / (N - 2 * cut);
	sumGrade = (int) fResult;

	if (fResult - sumGrade >= 0.5f)
		++sumGrade;

	cout << sumGrade;
}
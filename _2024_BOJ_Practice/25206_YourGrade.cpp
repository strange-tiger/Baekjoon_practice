#include <iostream>
using namespace std;

int cnt = 0;
float sumGrade = 0;
float sumCredit = 0;
float courseCredit = 0;
float courseGradeNum = 0;
char courseGradeWord[2] = {};
string name;

int main()
{
	while (cnt++ < 20)
	{
		cin >> name >> courseCredit >> courseGradeWord;

		if (courseGradeWord[0] == 'P')
			continue;

		sumCredit += courseCredit;

		switch (courseGradeWord[0])
		{
			case 'A' :
				courseGradeNum = 4;
			break;
			case 'B':
				courseGradeNum = 3;
			break;
			case 'C':
				courseGradeNum = 2;
			break;
			case 'D':
				courseGradeNum = 1;
			break;
			default :
				continue;
			break;
		}

		if (courseGradeWord[1] == '+')
			courseGradeNum += 0.5;

		sumGrade += courseCredit * courseGradeNum;
	}

	cout << sumGrade / sumCredit;

	return 0;
}
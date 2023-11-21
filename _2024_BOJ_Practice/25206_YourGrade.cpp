#include <iostream>
using namespace std;

int j = 0;
float sumGrade = 0;
float sumCredit = 0;
float courseCredit = 0;
float courseGradeNum = 0;
string courseGradeWord;
string name;

int main()
{
	while (j++ < 20)
	{
		cin >> name >> courseCredit >> courseGradeWord;

		if (courseGradeWord[0] == 'P')
			continue;

		sumCredit += courseCredit;

		if (courseGradeWord[0] == 'F')
			continue;

		if (courseGradeWord[0] == 'A') 
			courseGradeNum = 4;
		else if (courseGradeWord[0] == 'B') 
			courseGradeNum = 3;
		else if (courseGradeWord[0] == 'C') 
			courseGradeNum = 2;
		else 
			courseGradeNum = 1;

		if (courseGradeWord[1] == '+')
			courseGradeNum += 0.5;

		sumGrade += courseCredit * courseGradeNum;
	}

	cout << fixed;
	cout.precision(6);
	cout << sumGrade / sumCredit;

	return 0;
}
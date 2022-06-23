#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Member
{
	int _age;
	string _name;
	int _num;

	Member(int age, string name, int num)
		: _age(age), _name(name), _num(num)
	{

	}

};

bool comp(Member& L, Member& R)
{
	if (L._age < R._age)
	{
		return true;
	}
	else if (L._age == R._age)
	{
		return L._num < R._num;
	}
	else
	{
		return false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	int age = 0;
	string name = "";
	vector<Member> members;
	for (int i = 0; i < N; ++i)
	{
		cin >> age >> name;
		members.push_back(Member(age, name, i));
	}

	sort(members.begin(), members.end(), comp);

	for (int i = 0; i < N; ++i)
	{
		cout << members[i]._age << ' ' << members[i]._name << '\n';
	}

	return 0;
}
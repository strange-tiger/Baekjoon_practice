#include <iostream>
#include <vector>
using namespace std;

vector<char> bst[26];
void preorder(vector<char>& node)
{
	if(node.front() != '.')
		cout << node.front();
	if (node.size() == 1)
		return;
	if (node[1] != '.')
		preorder(bst[node[1] - 'A']);
	if (node[2] != '.')
		preorder(bst[node[2] - 'A']);
}

void inorder(vector<char>& node)
{
	if (node[1] != '.')
		inorder(bst[node[1] - 'A']);
	if (node.front() != '.')
		cout << node.front();
	if (node[2] != '.')
		inorder(bst[node[2] - 'A']);
}

void postorder(vector<char>& node)
{
	if (node[1] != '.')
		postorder(bst[node[1] - 'A']);
	if (node[2] != '.')
		postorder(bst[node[2] - 'A']);
	if (node.front() != '.')
		cout << node.front();
}

int N;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	while (N--)
	{
		char parent, left, right;
		cin >> parent >> left >> right;

		bst[parent - 'A'].push_back(parent);
		
		bst[parent - 'A'].push_back(left);
		bst[parent - 'A'].push_back(right);
	}

	preorder(bst[0]);
	cout << '\n';
	inorder(bst[0]);
	cout << '\n';
	postorder(bst[0]);

	return 0;
}
#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<char> keyLogger;
	list<char>::iterator cursor = keyLogger.begin();

	int testCase;
	cin >> testCase;
	
	for (int i = 0; i < testCase; i++)
	{
		string str;
		cin >> str;

		keyLogger.clear();
		for (int i = 0; i < str.size(); i++)
		{
			switch (str[i])
			{
			case '<':
				if (cursor != keyLogger.begin())
					--cursor;
				break;
			case '>':
				if (cursor != keyLogger.end())
					++cursor;
				break;
			case '-':
				if (cursor != keyLogger.begin())
					cursor = keyLogger.erase(--cursor);
				break;
			default :
				keyLogger.insert(cursor, str[i]);
				break;
			}
		}
		
		for (cursor = keyLogger.begin(); cursor != keyLogger.end(); ++cursor)
		{
			cout << *cursor;
		}
		cout << '\n';
	}

	return 0;
}

#pragma region �ּ��������ڵ�_Ǯ��
//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//
//    int testCase;
//    cin >> testCase;
//    while (testCase--)
//    {
//        // 1. ���ڿ��� �Է� �޴´�.
//        string input;
//        cin >> input;
//
//        // 2. �����̳� 2���� �����.
//        // �ϳ��� Ŀ�� ���� �����ϴ� ���ڿ��� ���������� ����
//        // �ٸ� �ϳ��� Ŀ�� ������ �����ϴ� ���ڿ��� ���������� ����
//        vector<char> left, rightReversed;
//
//        // 3. �� ���ڿ� ���ؼ� ó���Ѵ�.
//        for (char ch : input)
//        {
//            switch (ch)
//            {
//            case '<':
//                if (false == left.empty())
//                {
//                    rightReversed.push_back(left.back());
//                    left.pop_back();
//                }
//                break;
//            case '>':
//                if (false == rightReversed.empty())
//                {
//                    left.push_back(rightReversed.back());
//                    rightReversed.pop_back();
//                }
//                break;
//            case '-':
//                if (false == left.empty())
//                {
//                    left.pop_back();
//                }
//                break;
//            default:
//                left.push_back(ch);
//                break;
//            }
//        }
//
//        cout << string(left.begin(), left.end()) << string(rightReversed.rbegin(), rightReversed.rend()) << "\n";
//    }
//}//�ּ��������ڵ�
#pragma endregion
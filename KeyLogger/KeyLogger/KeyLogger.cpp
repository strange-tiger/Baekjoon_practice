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

#pragma region 최선문교수코드_풀이
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
//        // 1. 문자열을 입력 받는다.
//        string input;
//        cin >> input;
//
//        // 2. 컨테이너 2개를 만든다.
//        // 하나는 커서 왼편에 존재하는 문자열로 정방향으로 저장
//        // 다른 하나는 커서 오른편에 존재하는 문자열로 역방향으로 저장
//        vector<char> left, rightReversed;
//
//        // 3. 각 문자에 대해서 처리한다.
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
//}//최선문교수코드
#pragma endregion
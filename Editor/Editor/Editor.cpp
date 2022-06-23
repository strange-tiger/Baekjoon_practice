#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<char> editor;
	list<char>::iterator cursor = editor.begin();
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		editor.push_back(str[i]);
	}

	cursor = editor.end();

	int M;
	cin >> M;
	char order;
	char letter;

	for (int i = 0; i < M; i++)
	{
		cin >> order;

		switch (order)
		{
		case 'L':
			if (cursor != editor.begin())
				--cursor;
			break;
		case 'D':
			if (cursor != editor.end())
				++cursor;
			break;
		case 'B':
			if (cursor != editor.begin())
				cursor = editor.erase(--cursor);
			break;
		case 'P':
			cin >> letter;
			editor.insert(cursor, letter);
			break;
		}
	}

	for (list<char>::iterator iter = editor.begin(); iter != editor.end(); ++iter)
	{
		if (*iter != NULL)
			cout << *iter;
	}

	return 0;
}


#pragma region 최선문교수코드_풀이
// 리스트 예제 : 백준 1406번 에디터 풀이
// baekjoon 1406 editor
//
//#include <iostream>
//#include <list>
//
//using namespace std;
//
//string s;
//int M;
//
//int main()
//{
//    // 0. 입출력 속도를 향상시킨다.
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    // 1. 문자열을 입력 받는다.
//    cin >> s;
//
//    // 2. 명령어의 개수를 입력 받는다.
//    cin >> M;
//
//    // 3. 명령어를 처리한다.
//    list<char> lst(s.begin(), s.end());
//    list<char>::iterator cursor = lst.end();
//    while (M--)
//    {
//        // 3-1. 명령어를 입력 받는다.
//        char op;
//        cin >> op;
//
//        // 3-2. 각 명령어에 맞게 실행한다.
//        switch (op)
//        {
//        case 'L':
//            if (cursor != lst.begin())
//                --cursor;
//            break;
//        case 'D':
//            if (cursor != lst.end())
//                ++cursor;
//            break;
//        case 'B':
//            if (cursor != lst.begin())
//            {
//                --cursor;
//                cursor = lst.erase(cursor);
//            }
//            break;
//        case 'P':
//            char param;
//            cin >> param;
//
//            cursor = lst.insert(cursor, param);
//            ++cursor;
//            break;
//        }
//    }
//
//    // 4. 출력
//    for (list<char>::iterator iter = lst.begin(); iter != lst.end(); ++iter)
//    {
//        cout << *iter;
//    }
//
//}
#pragma endregion

#pragma region 제출번호_28348215_jinhan814
//#include <bits/stdc++.h>
//#include <sys/stat.h>
//#include <sys/mman.h>
//using namespace std;
//
///////////////////////////////////////////////////////////////////////////////////////////////
///*
// * Author : jinhan814
// * Date : 2021-04-14
// * Source : https://blog.naver.com/jinhan814/222266396476
// * Description : FastIO implementation for cin, cout. (mmap ver.)
// */
//constexpr int INPUT_SZ = 8000000;
//constexpr int OUTPUT_SZ = 1 << 20;
//
//class INPUT {
//private:
//	char* p;
//	bool __END_FLAG__, __GETLINE_FLAG__;
//public:
//	explicit operator bool() { return !__END_FLAG__; }
//	INPUT() { p = (char*)mmap(0, INPUT_SZ, PROT_READ, MAP_SHARED, 0, 0); }
//	bool is_blank(char c) { return c == ' ' || c == '\n'; }
//	bool is_end(char c) { return c == '\0'; }
//	char _readChar() { return *p++; }
//	char readChar() {
//		char ret = _readChar();
//		while (is_blank(ret)) ret = _readChar();
//		return ret;
//	}
//	template<typename T> T readInt() {
//		T ret = 0; char cur = _readChar(); bool flag = 0;
//		while (is_blank(cur)) cur = _readChar();
//		if (cur == '-') flag = 1, cur = _readChar();
//		while (!is_blank(cur) && !is_end(cur)) ret = 10 * ret + cur - '0', cur = _readChar();
//		if (is_end(cur)) __END_FLAG__ = 1;
//		return flag ? -ret : ret;
//	}
//	string readString() {
//		string ret; char cur = _readChar();
//		while (is_blank(cur)) cur = _readChar();
//		while (!is_blank(cur) && !is_end(cur)) ret.push_back(cur), cur = _readChar();
//		if (is_end(cur)) __END_FLAG__ = 1;
//		return ret;
//	}
//	double readDouble() {
//		string ret = readString();
//		return stod(ret);
//	}
//	string getline() {
//		string ret; char cur = _readChar();
//		while (cur != '\n' && !is_end(cur)) ret.push_back(cur), cur = _readChar();
//		if (__GETLINE_FLAG__) __END_FLAG__ = 1;
//		if (is_end(cur)) __GETLINE_FLAG__ = 1;
//		return ret;
//	}
//	friend INPUT& getline(INPUT& in, string& s) { s = in.getline(); return in; }
//} _in;
//
//class OUTPUT {
//private:
//	char write_buf[OUTPUT_SZ];
//	int write_idx;
//public:
//	~OUTPUT() { bflush(); }
//	void bflush() {
//		fwrite(write_buf, sizeof(char), write_idx, stdout);
//		write_idx = 0;
//	}
//	void writeChar(char c) {
//		if (write_idx == OUTPUT_SZ) bflush();
//		write_buf[write_idx++] = c;
//	}
//	template<typename T> int getSize(T n) {
//		int ret = 1;
//		if (n < 0) n = -n;
//		while (n >= 10) ret++, n /= 10;
//		return ret;
//	}
//	template<typename T> void writeInt(T n) {
//		int sz = getSize(n);
//		if (write_idx + sz >= OUTPUT_SZ) bflush();
//		if (n < 0) write_buf[write_idx++] = '-', n = -n;
//		for (int i = sz - 1; i >= 0; i--) write_buf[write_idx + i] = n % 10 + '0', n /= 10;
//		write_idx += sz;
//	}
//	void writeString(string s) { for (auto& c : s) writeChar(c); }
//	void writeDouble(double d) { writeString(to_string(d)); }
//} _out;
//
///* operators */
//INPUT& operator>> (INPUT& in, char& i) { i = in.readChar(); return in; }
//INPUT& operator>> (INPUT& in, string& i) { i = in.readString(); return in; }
//template<typename T> INPUT& operator>> (INPUT& in, T& i) {
//	if constexpr (is_floating_point_v<T>) i = in.readDouble();
//	else if constexpr (is_integral_v<T>) i = in.readInt<T>(); return in;
//}
//OUTPUT& operator<< (OUTPUT& out, char i) { out.writeChar(i); return out; }
//OUTPUT& operator<< (OUTPUT& out, string i) { out.writeString(i); return out; }
//template<typename T> OUTPUT& operator<< (OUTPUT& out, T i) {
//	if constexpr (is_floating_point_v<T>) out.writeDouble(i);
//	else if constexpr (is_integral_v<T>) out.writeInt<T>(i); return out;
//}
//
///* macros */
//#define fastio 1
//#define cin _in
//#define cout _out
//#define istream INPUT
//#define ostream OUTPUT
///////////////////////////////////////////////////////////////////////////////////////////////
//
//int main() {
//	fastio;
//	string s; int n; cin >> s >> n;
//	deque<char> t1(s.begin(), s.end()), t2;
//	for (int i = 0; i < n; i++) {
//		char t, x; cin >> t;
//		if (t == 'P') cin >> x, t1.push_back(x);
//		else if (t == 'L' && !t1.empty()) t2.push_back(t1.back()), t1.pop_back();
//		else if (t == 'D' && !t2.empty()) t1.push_back(t2.back()), t2.pop_back();
//		else if (t == 'B' && !t1.empty()) t1.pop_back();
//	}
//	cout << string(t1.begin(), t1.end()) << string(t2.rbegin(), t2.rend()) << '\n';
//}
#pragma endregion
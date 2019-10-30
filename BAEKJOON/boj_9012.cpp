#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

int T;
string ch, result_;
stack<char> s;

int main(void) {
	cin >> T;
	for (int i = 0; i < T;i++) {
		cin >> ch;

		if (ch[0] == ')' || (int)ch.size() % 2 == 1) {
			cout << "NO" << endl; continue;
		}
		else s.push(ch[0]);
		
		int j = 0;
		for (j = 1; j < (int)ch.size(); j++) {
			if (ch[j] == '(') s.push(ch[j]);
			else {
				if (s.empty()) {
					result_ = "NO"; break;
				}
				else s.pop();
			}
		}
		if (j == (int)ch.size() && s.empty()) result_ = "YES";
		else result_ = "NO";
		while (!s.empty()) s.pop();

		cout << result_ << endl;
	}
	return 0;
}
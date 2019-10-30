#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int len;

int main(void) {
	for (int test_case = 1; test_case <= 10; test_case++) {
		int answer = 0;
		char ch;
		queue<char>q; stack<char>s;
		cin >> len;
		for (int i = 0; i < len; i++) {
			cin >> ch;
			if (ch == '+') {
				if (s.empty()) s.push(ch);
				else {
					q.push(s.top()); s.pop();
					s.push(ch);
				}
			}
			else {
				q.push(ch);
			}
		}

		while (!s.empty()) { q.push(s.top()); s.pop(); }
		stack<int> calc;
		while (!q.empty()) {
			char cur = q.front(); q.pop();
			if (cur == '+') {
				int num1 = calc.top(); calc.pop();
				int num2 = calc.top(); calc.pop();
				calc.push(num1 + num2);
			}
			else {
				calc.push(cur - '0');
			}
		}
		answer = calc.top();
		printf("#%d %d\n", test_case, answer);
	}

	return 0;
}
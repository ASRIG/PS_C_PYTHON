#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main(int argc, char** argv) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int len;
	char ch;
	for (int testcase = 1; testcase <= 10; testcase++) {
		cin >> len;
		stack<char> s;
		queue<char> q;
		for (int i = 0; i < len; i++) {
			cin >> ch;
			switch (ch) {
			case '(':
				s.push(ch); break;
			case ')':
				while (!s.empty()) {
					if (s.top() != '(') {
						q.push(s.top());
						s.pop();
					}
					else {
						s.pop();
						break;
					}
				}
				break;
			case '+':
				while (!s.empty()) {
					if (s.top() == '*') {
						q.push(s.top());
						s.pop();
					}
					else if (s.top() == '+') {
						q.push(s.top());
						s.pop();
						s.push(ch);
						break;
					}
					else {
						s.push(ch);
						break;
					}
				}
				if (s.empty())
					s.push(ch);
				break;
			case '*':
				while (!s.empty()) {
					if (s.top() == '*') {
						q.push(s.top());
						s.pop();
					}
					else {
						s.push(ch);
						break;
					}
				}
				if (s.empty())
					s.push(ch);
				break;
			default:
				q.push(ch); break;
			}
		}

		while (!s.empty()) {
			q.push(s.top());
			s.pop();
		}

		stack<int> calc;
		while (!q.empty()) {
			if (q.front() != '+' && q.front() != '*') {
				calc.push(q.front() - '0');
				q.pop();
			}
			else {
				int num1 = calc.top();
				calc.pop();
				int num2 = calc.top();
				calc.pop();
				if (q.front() == '+')
					calc.push(num1 + num2);
				else if (q.front() == '*')
					calc.push(num1 * num2);
				q.pop();
			}
		}

		cout << "#" << testcase << " " << calc.top() << "\n";
	}

	return 0;
}
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

int n, num;
char str[5];
stack<int> s;

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str[0] == 'p' && str[1] == 'u') {
			cin >> num;
			s.push(num);
		}
		else if (str[0] == 't' && str[1] == 'o') {
			if (s.empty()) printf("-1\n");
			else printf("%d\n", s.top());
		}
		else if (str[0] == 's' && str[1] == 'i') {
			printf("%d\n", s.size());
		}
		else if (str[0] == 'e' && str[1] == 'm') {
			if (s.empty()) printf("1\n");
			else printf("0\n");
		}
		else if (str[0] == 'p' && str[1] == 'o') {
			if (s.empty()) printf("-1\n");
			else {
				printf("%d\n", s.top()); s.pop();
			}
		}
	}
	return 0;
}
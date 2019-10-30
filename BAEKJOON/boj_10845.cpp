#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int n, num_;
string s;
queue<int> q;

int main(void) {
	cin >> n, num_;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "push") {
			cin >> num_;
			q.push(num_);
		}
		else if (s == "front") {
			if (!q.empty()) {
				printf("%d\n", q.front());
			}
			else printf("-1\n");
		}
		else if (s == "pop") {
			if (!q.empty()) {
				printf("%d\n", q.front()); q.pop();
			}
			else {
				printf("-1\n");
			}
		}
		else if (s == "size") {
			printf("%d\n", q.size());
		}
		else if (s == "empty") {
			printf("%d\n", q.empty());
		}
		else if (s == "back") {
			if (!q.empty()) {
				printf("%d\n", q.back());
			}
			else printf("-1\n");
		}
	}
	return 0;
}
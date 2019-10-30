#include <iostream>
#include <queue>

using namespace std;

int n, cmd;
priority_queue<int> q;

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &cmd);
		if (cmd == 0) {
			if (q.empty())printf("0\n");
			else printf("%d\n", q.top()), q.pop();
		}
		else {
			q.push(cmd);
		}
	}
	return 0;
}
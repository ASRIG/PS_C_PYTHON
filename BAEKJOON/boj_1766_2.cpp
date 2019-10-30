#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int> que;
queue<int> sol;
vector<int> arr[32005];
bool solved_[32005];
int n, m, a, b, line_num[32005];

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		arr[a].push_back(b); line_num[b]++;
	}

	for (int i = 1; i <= n; i++) {
		if (line_num[i] == 0) que.push(-i);
	}

	while (!que.empty()) {
		int cur = -que.top(); que.pop();
		solved_[cur] = true; sol.push(cur);

		for (int i = 0; i < (int)arr[cur].size(); i++) {
			int t = arr[cur][i];
			line_num[t]--;
			if (solved_[t] == true) continue;
			if (line_num[t] == 0) {
				que.push(-t);
			}
		}
	}

	while (!sol.empty()) {
		int cur = sol.front(); sol.pop();
		printf("%d ", cur);
	}printf("\n");

	return 0;
}
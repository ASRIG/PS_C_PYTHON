#include <iostream>
#include <queue>

using namespace std;

int t, n, m, a, b;
bool test_[10002][10002];
bool visited_[10002];

int main(void) {
	cin >> t;
	for (int tes = 1; tes <= t; tes++) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			visited_[i] = false;
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) test_[i][j] = false;
				else {
					test_[i][j] = true;
				}
			}
		}

		for (int ia = 0; ia < m; ia++) {
			cin >> a >> b;
			test_[a][b] = false; test_[b][a] = false;
		}

		int cnt = 0;
		queue<int> q;
		q.push(1); visited_[1] = true;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (int i = 1; i <= n; i++) {
				if (test_[cur][i] == false) continue;
				if (visited_[i] == true) continue;
				else {
					visited_[i] = true;
					q.push(i); cnt++;
				}
			}
		}

		int answer = (n * (n - 1)) / 2;
		answer -= m;
		printf("#%d %d\n", tes, answer - cnt);
	}
	return 0;
}
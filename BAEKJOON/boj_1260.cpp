#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, V, a, b;
vector<int> v[1001];
queue<int> q;
int visited_dfs[1001], visited_bfs[1001];

void dfs(int x) {
	if (visited_dfs[x] == 1) return;
	else {
		visited_dfs[x] = 1;
		for (int i = 0; i < v[x].size(); i++) {
			if (visited_dfs[v[x][i]] == 0) {
				printf("%d ", v[x][i]);
				dfs(v[x][i]);
			}
		}
	}
}

void bfs() {
	while (!q.empty()) {
		int cur_x = 1 * q.front(); q.pop();
		for (int i = 0; i < v[cur_x].size(); i++) {
			if (visited_bfs[v[cur_x][i]] == 0) {
				visited_bfs[v[cur_x][i]] = 1;
				printf("%d ", v[cur_x][i]);
				q.push(v[cur_x][i]);
			}
		}
	}
}

int main(void) {
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b); v[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		sort(v[i].begin(), v[i].end());
	}

	printf("%d ", V);
	dfs(V); printf("\n");
	printf("%d ", V);
	q.push(V); visited_bfs[V] = 1;
	bfs(); printf("\n");
	return 0;
}
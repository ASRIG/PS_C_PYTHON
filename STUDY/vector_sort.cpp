#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, V, a, b;
vector<int> v[1001];
int visited_dfs[1001], visited_bfs[1001];

int main(void) {
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b); v[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		sort(v[i].begin(), v[i].end());
	}

	return 0;
}
#include <iostream>
#include <queue>
#include <vector>
#define mp make_pair
#define INF 20000000
using namespace std;

vector<int> con[20001], conv[20001];
priority_queue<pair<int, int>> pq;
int V, E, K, D[20001], a, b, c;

int main(void) {
	cin >> V >> E; cin >> K;
	for (int i = 1; i <= V; i++) D[i] = INF;

	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		con[a].push_back(b); conv[a].push_back(c);
	}
	pq.push(mp(0, K)); D[K] = 0;
	while (!pq.empty()) {
		int cur_x = pq.top().second, cur_d = -pq.top().first;
		pq.pop();
		if (D[cur_x] != cur_d) continue;
		for (int i = 0; i < (int)con[cur_x].size(); i++) {
			int k = con[cur_x][i], t = conv[cur_x][i];
			if (D[k] > D[cur_x] + t) {
				D[k] = D[cur_x] + t; pq.push(mp(-D[k], k));
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (D[i] == INF) printf("INF\n");
		else {
			printf("%d\n", D[i]);
		}
	}

	return 0;
}
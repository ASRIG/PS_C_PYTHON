#include <iostream>
#include <queue>
#define mp make_pair
#define INF 10000100
using namespace std;

int d[105][105], n, m;
char map[105][105];

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };
priority_queue < pair<int, pair<int, int>>> pq;

int main(void) {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			d[i][j] = INF;
		}
	}

	pq.push(mp(-1, mp(0, 0)));
	d[0][0] = 1;

	while (!pq.empty()) {
		int cur_d = -pq.top().first;
		int cur_x = pq.top().second.first, cur_y = pq.top().second.second;
		pq.pop();
		if (d[cur_x][cur_y] != cur_d) continue;
		for (int dir = 0; dir < 4; dir++) {
			int new_x = cur_x + dx[dir], new_y = cur_y + dy[dir];
			if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m) continue;
			if (map[new_x][new_y] == '0') continue;
			if (d[new_x][new_y] > d[cur_x][cur_y] + 1) {
				d[new_x][new_y] = d[cur_x][cur_y] + 1;
				pq.push(mp(-(cur_d + 1), mp(new_x, new_y)));
			}
		}
	}

	printf("%d\n", d[n - 1][m - 1]);

	return 0;
}
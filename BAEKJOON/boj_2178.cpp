#include <iostream>
#include <queue>

#define mp make_pair
#define INF 9876542
using namespace std;

priority_queue<pair<int,pair<int, int>>> q;
char map[105][105];
int n, m, visit[105][105];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			visit[i][j] = INF;
	}
	q.push(mp(0, mp(0, 0)));
	visit[0][0] = 1;

	while (!q.empty()) {
		int cur_dist = -q.top().first, cur_x = q.top().second.first;
		int cur_y = q.top().second.second; q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int new_x = cur_x + dx[dir], new_y = cur_y + dy[dir];
			if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m) continue;
			if (map[new_x][new_y] == '0') continue;
			if (visit[new_x][new_y] > visit[cur_x][cur_y] + 1) {
				
				//printf("%d : %d\n", visit[new_x][new_y], visit[cur_x][cur_y] + 1);
				visit[new_x][new_y] = visit[cur_x][cur_y] + 1;
				//printf("%d : %d -> %d\n", new_x, new_y, visit[new_x][new_y]);
				q.push(mp(-(cur_dist + 1), mp(new_x, new_y)));
			}
		}
	}

	printf("%d\n", visit[n - 1][m - 1]);

	return 0;
}
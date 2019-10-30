#include <iostream>
#include <algorithm>
#include <queue>
#define mp make_pair
#define INF 1000040
using namespace std;

struct SHARK {
	int x, y, size, exp = 0;
};

struct FISH {
	int x, y, size, live = 1;

	bool operator < (const FISH fi) const {
		return this->size < fi.size;
	}
};

int n, map[22][22], fish_cnt(0), d[22][22];
SHARK shark;
FISH fish[405];

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

void make_distance() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			d[i][j] = INF;
		}
	}

	priority_queue<pair<int, pair<int, int>>> pq;
	int shark_size = shark.size;
	pq.push(mp(0, mp(shark.x, shark.y)));
	d[shark.x][shark.y] = 0;

	while (!pq.empty()) {
		int cur_d = -pq.top().first;
		int cur_x = pq.top().second.first, cur_y = pq.top().second.second;
		pq.pop();
		if (d[cur_x][cur_y] != cur_d) continue;
		for (int dir = 0; dir < 4; dir++) {
			int new_x = cur_x + dx[dir], new_y = cur_y + dy[dir];
			if (new_x < 0 || new_y < 0 || new_x >= n || new_y >= n) continue;
			if (map[new_x][new_y] > shark_size) continue;
			if (d[new_x][new_y] > cur_d + 1) {
				d[new_x][new_y] = cur_d + 1;
				pq.push(mp(-d[new_x][new_y], mp(new_x, new_y)));
			}
		}
	}
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				shark.x = i; shark.y = j; shark.size = 2; shark.exp = 0;
				map[i][j] = 0;
			}
			else if (map[i][j] != 0) {
				fish[fish_cnt].x = i; fish[fish_cnt].y = j; fish[fish_cnt].size = map[i][j];
				fish[fish_cnt].live = 1; fish_cnt++;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < fish_cnt; i++) {
		make_distance();
		int min_idx = INF, min_dis = INF;
		for (int j = 0; j < fish_cnt; j++) {
			if (fish[j].live == 0 || fish[j].size >= shark.size) continue;
			if (min_dis > d[fish[j].x][fish[j].y]) {
				min_dis = d[fish[j].x][fish[j].y];  min_idx = j;
			}
		}
		if (min_idx == INF) break;
		fish[min_idx].live = 0; ans += min_dis; shark.exp++;
		shark.x = fish[min_idx].x; shark.y = fish[min_idx].y;
		map[fish[min_idx].x][fish[min_idx].y] = 0;
		if (shark.exp == shark.size) {
			shark.exp = 0; shark.size += 1;
		}
	}	
	printf("%d\n", ans);

	return 0;
}
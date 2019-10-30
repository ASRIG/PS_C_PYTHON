#include <iostream>
#include <queue>
#define INF 0x7fffffff
#define mp make_pair
using namespace std;

struct FISH {
	int x, y, size, live;
};

int n, map[22][22], shark_x, shark_y, shark_size, shark_exp;
int fish_cnt, d[22][22];
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };
FISH fish[405];

void init_d() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			d[i][j] = INF;
		}
	}
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) continue;
			else if (map[i][j] == 9) {
				map[i][j] = 0;
				shark_x = i; shark_y = j; shark_size = 2; shark_exp = 0;
			}
			else {
				fish[fish_cnt].x = i; fish[fish_cnt].y = j; fish[fish_cnt].size = map[i][j];
				fish[fish_cnt].live = 1; fish_cnt++;
			}
		}
	}
	priority_queue<pair<int, pair<int, int>>>pq;
	pq.push(mp(0, mp(shark_x, shark_y)));
	init_d(); d[shark_x][shark_y] = 0;

	int tim = 0;
	for (;;) {
		while (!pq.empty()) {
			// 전체 거리 탐색
			int cur_x = pq.top().second.first, cur_y = pq.top().second.second;
			int cur_d = -pq.top().first; pq.pop();
			if (d[cur_x][cur_y] != cur_d) continue;
			for (int dir = 0; dir < 4; dir++) {
				int new_x = cur_x + dx[dir], new_y = cur_y + dy[dir];
				if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= n) continue;
				if (map[new_x][new_y] > shark_size) continue;
				else {
					if (d[new_x][new_y] > cur_d + 1) {
						d[new_x][new_y] = cur_d + 1;
						pq.push(mp(-d[new_x][new_y], mp(new_x, new_y)));
					}
				}
			}
		}

		int min_distance = 0x7fffffff, min_idx = -1;
		for (int ia = 0; ia < fish_cnt; ia++) {
			if (fish[ia].live == 0) continue;
			if (fish[ia].size >= shark_size) continue;
			if (min_distance > d[fish[ia].x][fish[ia].y]) {
				min_distance = d[fish[ia].x][fish[ia].y]; min_idx = ia;
				//printf("min : %d\n", min_distance);
			}
		}

		if (min_idx == -1) break;
		else {
			int cur_x = fish[min_idx].x, cur_y = fish[min_idx].y;
			map[cur_x][cur_y] = 0; fish[min_idx].live = 0;
			tim += d[cur_x][cur_y];
			shark_x = cur_x; shark_y = cur_y; shark_exp += 1;
			if (shark_exp == shark_size) {
				shark_size += 1; shark_exp = 0;
			}
		}

		pq.push(mp(0, mp(shark_x, shark_y)));
		// D 초기화
		init_d(); d[shark_x][shark_y] = 0;
	}

	printf("%d\n", tim);

	return 0;
}
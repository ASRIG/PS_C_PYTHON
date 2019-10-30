#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;

int n, l, r, map[55][55], team_cnt;
int team_sum[2500], team_num[2500];
const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, -1, 0, 1 };

struct TEAM {
	int x, y, team_idx;
	TEAM(int tx = 0, int ty = 0, int tteam = 0) {
		x = tx; y = ty; team_idx = tteam;
	}
};

int abs(int aa) {
	return aa < 0 ? -aa : aa;
}

int main(void) {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	int team_[55][55];
	queue<TEAM> q;
	int tim = 0;
	for (;;) {
		memset(team_, 0, sizeof(team_));
		memset(team_sum, 0, sizeof(team_sum));
		memset(team_num, 0, sizeof(team_num));
			
		// 이동
		int tc = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (team_[i][j] == 0) {
					tc++;
					team_[i][j] = tc; team_num[tc] += 1;
					team_sum[tc] += map[i][j];
					q.push(TEAM(i, j, tc));

					while (!q.empty()) {
						TEAM cur = q.front(); q.pop();
						for (int dir = 0; dir < 4; dir++) {
							int new_x = cur.x + dx[dir], new_y = cur.y + dy[dir];
							if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= n) continue;
							if (team_[new_x][new_y] != 0) continue;
							int distance_ = abs(map[new_x][new_y] - map[cur.x][cur.y]);
							if (distance_ >= l && distance_ <= r) {
								team_[new_x][new_y] = tc;
								team_sum[tc] += map[new_x][new_y];
								team_num[tc] += 1;
								q.push(TEAM(new_x, new_y, tc));
							}
						}
					}

				}
			}
		}

		// 분배
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				map[i][j] = team_sum[team_[i][j]] / team_num[team_[i][j]];
			}
		}
		if (tc == n * n) break;

		tim++;
	}
	
	printf("%d\n", tim);

	return 0;
}
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct BALL {
	int red_x, red_y, idx, blue_x, blue_y, cnt = 0;
	BALL(int idx_tmp = -1, int cntt = 0) : idx(idx_tmp), cnt(cntt) {}
	BALL(int rx, int ry, int ix, int bx, int by, int cntt) {
		red_x = rx; red_y = ry; idx = ix; blue_x = bx; blue_y = by;
		cnt = cntt;
	}
};

int n, m, answer = 11;
char map[15][15];
BALL ball;
queue<BALL> q;

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, -1, 0, 1 };

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				map[i][j] = '.'; ball.red_x = i; ball.red_y = j;
			}
			else if (map[i][j] == 'B') {
				map[i][j] = '.'; ball.blue_x = i; ball.blue_y = j;
			}
		}
	}
	q.push(ball);
	while (!q.empty()) {
		BALL cur_ = q.front(); q.pop();
		if (cur_.cnt >= answer) continue;
		for (int dir = 0; dir < 4; dir++) {
			if (cur_.idx != -1 && (cur_.idx % 2 == dir % 2)) continue;
			// 빨간 공 옮기기
			int new_rx = cur_.red_x, new_ry = cur_.red_y;
			int red_cnt = 0;
			bool red_goal = false;
			while (1) {
				red_cnt++; new_rx += dx[dir]; new_ry += dy[dir];
				if (map[new_rx][new_ry] == '#') break;
				else if (map[new_rx][new_ry] == 'O') {
					red_goal = true; break;
				}
			} red_cnt--; new_rx -= dx[dir]; new_ry -= dy[dir];
			
			// 파란 공 옮기기
			int new_bx = cur_.blue_x, new_by = cur_.blue_y;
			int blue_cnt = 0;
			bool blue_goal = false;
			while (1) {
				blue_cnt++; new_bx += dx[dir]; new_by += dy[dir];
				if (map[new_bx][new_by] == '#') break;
				else if (map[new_bx][new_by] == 'O') {
					blue_goal = true; break;
				}
			} blue_cnt--; new_bx -= dx[dir]; new_by -= dy[dir];

			// 위치가 같을 경우 누가 더 많이 이동했나?
			if (red_goal == true && blue_goal == true) continue;
			if (new_rx == new_bx && new_ry == new_by) {
				if (blue_cnt > red_cnt) {
					new_bx -= dx[dir]; new_by -= dy[dir];
				}
				else {
					new_rx -= dx[dir]; new_ry -= dy[dir];
				}
			}
			if (blue_goal == true) continue;
			if (red_goal) {
				answer = min(answer, cur_.cnt + 1);
				continue;
			}
			q.push(BALL(new_rx, new_ry, dir, new_bx, new_by, cur_.cnt + 1));
		}
	}

	if (answer == 11) answer = -1;
	printf("%d\n", answer);

	return 0;
}
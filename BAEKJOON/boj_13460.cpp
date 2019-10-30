#include <iostream>
#include <queue>

#define min(a, b) a < b ? a : b
#define mp make_pair

using namespace std;

struct BALL {
	int bx, by, rx, ry, cnt, idx = 0;
	BALL(int a = 1, int b = 1, int c = 1, int d = 1, int cntt = 0, int idxx = 3) {
		bx = a; by = b; rx = c; ry = d; cnt = cntt; idx = idxx;
	}
	~BALL() {}
};

BALL b;
int N, M, answer = 11;
const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };
char map[13][13];

queue<BALL> q;

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'B') {
				b.bx = i; b.by = j;
			}
			else if (map[i][j] == 'R') {
				b.rx = i; b.ry = j;
			}
		}
	}

	q.push(b);
	while (!q.empty()) {
		BALL cur = q.front(); q.pop();
		//printf("%d %d %d %d %d\n", cur.bx, cur.by, cur.rx, cur.ry, cur.cnt);
		if (cur.cnt >= answer) continue;
		for (int dir = 0; dir < 4; dir++) {
			if (cur.idx == dir % 2) continue;
			int next_bx = cur.bx, next_by = cur.by, blue_move = 0;
			bool blue_goal = false;
			while (map[next_bx][next_by] != '#') {
				if (map[next_bx][next_by] == 'O') {
					blue_goal = true; break;
				}
				blue_move++;
				next_bx += dx[dir]; next_by += dy[dir];
			}next_bx -= dx[dir]; next_by -= dy[dir];

			int red_move = 0;
			int next_rx = cur.rx, next_ry = cur.ry;

			bool red_goal = false;
			while (map[next_rx][next_ry] != '#') {
				if (map[next_rx][next_ry] == 'O') {
					red_goal = true; break;
				}
				red_move++;
				next_rx += dx[dir]; next_ry += dy[dir];
			}next_rx -= dx[dir]; next_ry -= dy[dir];
			if (next_rx == next_bx && next_ry == next_by) {
				if (red_move > blue_move) {
					next_rx -= dx[dir]; next_ry -= dy[dir];
				}
				else {
					next_bx -= dx[dir]; next_by -= dy[dir];
				}
			}

			//if (next_bx == cur.bx && next_by == cur.by && next_rx == cur.rx && next_ry == cur.ry) continue;

			if (red_goal == true && blue_goal == false) {
				answer = min(answer, cur.cnt + 1); continue;
			}
			else if (blue_goal == true) continue;


			q.push(BALL(next_bx, next_by, next_rx, next_ry, cur.cnt + 1, dir % 2));
		}
	}
	if (answer == 11) answer = -1;
	printf("%d\n", answer);
	return 0;
}
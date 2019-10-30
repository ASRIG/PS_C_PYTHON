#include <iostream>
#include <queue>

using namespace std;

struct ROBOT {
	int x, y, d;
	// 0 ºÏ, 1 µ¿ 2 ³² 3 ¼­

	ROBOT() { x = 0; y = 0; d = 0; };
	ROBOT(int a, int b, int c) {
		x = a; y = b; d = c;
	}
};

int map[52][52], n, m, r, c, d;
const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	cin >> n >> m;
	cin >> r >> c >> d;
	ROBOT ro(r, c, d);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	queue<ROBOT> q;
	q.push(ro);

	while (!q.empty()) {
		ROBOT cur = q.front(); q.pop();
		int cur_x = cur.x, cur_y = cur.y, cur_d = cur.d;
		map[cur_x][cur_y] = 2;
		bool rotate_sw = true;
		for (int dir = 0; dir < 4; dir++) {
			cur_d = (cur_d + 3) % 4;
			int new_x = cur_x + dx[cur_d], new_y = cur_y + dy[cur_d];
			if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m) continue;
			if (map[new_x][new_y] == 0) {
				rotate_sw = false;
				q.push(ROBOT(new_x, new_y, cur_d));
				break;
			}
		}
		if (rotate_sw) {
			int new_x = cur_x - dx[cur_d], new_y = cur_y - dy[cur_d];
			if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m) break;
			if (map[new_x][new_y] == 1) break;
			else {
				q.push(ROBOT(new_x, new_y, cur_d));
			}
		}
	}
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 2) answer++;
		}
	}

	printf("%d\n", answer);

	return 0;
}
#include <iostream>
#include <queue>
using namespace std;

struct ROBOT{
	int x, y, dir;
	ROBOT(int a, int b, int c) {
		x = a; y = b; dir = c;
	}
};

int n, m, r, c, d, map[55][55];
const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };

void view_() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", map[i][j]);
		}printf("\n");
	}
}

int main(void) {
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	queue<ROBOT> q;
	q.push(ROBOT(r, c, d));
	int clean_cnt = 1;
	while (!q.empty()) {
		ROBOT cur = q.front(); q.pop();
		map[cur.x][cur.y] = 2;

		int cur_dir = cur.dir;
		int new_x = cur.x, new_y = cur.y;
		bool break_sw = false;
		for (int dir = 0; dir < 4; dir++) {
			cur_dir = (cur_dir + 3) % 4;
			new_x = cur.x + dx[cur_dir], new_y = cur.y + dy[cur_dir];
			if (map[new_x][new_y] == 0) {
				clean_cnt++;
				break_sw = true; break;
			}
		}
		if (break_sw) {
			q.push(ROBOT(new_x, new_y, cur_dir));
		}else {
			// ÈÄÁø
			new_x = cur.x - dx[cur_dir]; new_y = cur.y - dy[cur_dir];
			if (map[new_x][new_y] == 1) break;
			q.push(ROBOT(new_x, new_y, cur_dir));
		}
		//printf("\n");
		//view_();
	}

	printf("%d\n", clean_cnt);
	return 0;
}
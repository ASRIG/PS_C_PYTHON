#include <iostream>

using namespace std;

struct ZU {
	int up, down, front, back, left, right;

	void turn_front() {
		int tmp = up;
		up = back; back = down; down = front; front = tmp;
	}
	void turn_back() {
		int tmp = up;
		up = front; front = down; down = back; back = tmp;
	}
	void turn_left() {
		int tmp = up;
		up = right; right = down; down = left; left = tmp;
	}
	void turn_right() {
		int tmp = up;
		up = left; left = down; down = right; right = tmp;
	}

};

ZU z;
int n, m, x, y, k;
int map[22][22], cmd;
const int dx[] = { 0, 0, -1, 1 };
const int dy[] = { 1, -1, 0, 0 };

int main(void) {
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	int cur_x = x, cur_y = y;
	for (int i = 0; i < k; i++) {
		cin >> cmd; cmd -= 1;
		// µ¿ 1, ¼­ 2, ºÏ 3, ³² 4
		int new_x = cur_x + dx[cmd], new_y = cur_y + dy[cmd];
		if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m) continue;
		if (cmd == 0) {
			z.turn_right();
		}
		else if (cmd == 1) {
			z.turn_left();
		}
		else if (cmd == 2) {
			z.turn_back();
		}
		else if (cmd == 3) {
			z.turn_front();
		}

		if (map[new_x][new_y] == 0) {
			map[new_x][new_y] = z.down;
		}else {
			z.down = map[new_x][new_y]; map[new_x][new_y] = 0;
		}
		cur_x = new_x; cur_y = new_y;
		printf("%d\n", z.up);
	}



	return 0;
}
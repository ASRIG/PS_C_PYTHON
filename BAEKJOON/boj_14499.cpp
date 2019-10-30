#include <iostream>

using namespace std;

struct DICE {
	int up, down, left, right, front, back;

	void move_left() {
		int tmp = up;
		up = right; right = down; down = left; left = tmp;
	}
	
	void move_right() {
		int tmp = up;
		up = left; left = down; down = right; right = tmp;
	}

	void move_front() {
		int tmp = up;
		up = back; back = down; down = front; front = tmp;
	}

	void move_back() {
		int tmp = up;
		up = front; front = down; down = back; back = tmp;
	}
};

int N, M, x, y, K, map[22][22], cmd;
const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { 1, -1, 0, 0 };


int main(void) {
	DICE d;
	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	d.up = 0; d.back = 0; d.down = 0; d.front = 0; d.left = 0; d.right = 0;
	for (int i = 0; i < K; i++) {
		cin >> cmd; cmd -= 1;
		// 1 µ¿, 2 ¼­, 3 ºÏ, 4 ³²
		int new_x = x + dx[cmd], new_y = y + dy[cmd];
		if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= M) continue;
		//printf("x : %d y : %d cmd : %d\n", new_x, new_y, cmd);
		if (cmd == 0) {
			d.move_right();
		}
		else if (cmd == 1) {
			d.move_left();
		}
		else if (cmd == 2) {
			d.move_back();
		}
		else {
			d.move_front();
		}
		if (map[new_x][new_y] == 0) {
			map[new_x][new_y] = d.down;
		}
		else {
			d.down = map[new_x][new_y]; map[new_x][new_y] = 0;
		}
		x = new_x; y = new_y;
		printf("%d\n", d.up);
	}

	return 0;
}
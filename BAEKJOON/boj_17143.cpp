#include <iostream>
#include <algorithm>
using namespace std;

struct SHARK {
	int x, y, speed, dir, size, live = 1;

	SHARK() {}
	SHARK(int aa, int bb, int cc, int dd, int ee, int ll = 1) {
		x = aa; y = bb; speed = cc; dir = dd; size = ee; live = ll;
	}
};

SHARK shark[10015];
int r, c, m, map[110][110];
int x, y, s, d, z;
// 1 : up, 2 : down, 3 : right, 4 : left
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,1,0,-1 };

bool comp(SHARK &sha_a, SHARK &sha_b) {
	return sha_a.size > sha_b.size;
}

void map_zero() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			map[i][j] = 0;
		}
	}
}

void view_() {
	printf("\n");
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("%d ", map[i][j]);
		}printf("\n");
	}
}

int main(void) {
	cin >> r >> c >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> s >> d >> z; d -= 1; x -= 1; y -= 1;
		
		if (d == 1) d = 2;
		else if (d == 2) d = 1;

		if (d == 0 || d == 2) s %= (2 * (r - 1));
		else s %= (2 * (c - 1));
		
		SHARK tmp(x, y, s, d, z); shark[i] = tmp;
	}

	sort(shark, shark + m, comp);
	map_zero();
	for (int i = 0; i < m; i++) {
		map[shark[i].x][shark[i].y] = i + 1;
	}
	

	int answer = 0;
	for (int p = 0; p < c; p++) {
		//printf("[잡기 전 && 이동 후]\n");
		//view_();

		// 상어 잡기
		for (int i = 0; i < r; i++) {
			if (map[i][p] != 0) {
				shark[map[i][p] - 1].live = 0;
				answer += shark[map[i][p] - 1].size;
				break;
			}
		}
		//printf("[잡은 후]\n");
		//view_();

		// 맵 초기화
		map_zero();

		// 상어 이동
		for (int i = 0; i < m; i++) {
			if (shark[i].live == 0) continue;
			int new_x = shark[i].x, new_y = shark[i].y;
			int dir = shark[i].dir;
			bool dir_change = false;
			if (dir == 0 && new_x == 0) dir_change = true;
			else if (dir == 1 && new_y == c - 1) dir_change = true;
			else if (dir == 2 && new_x == r - 1) dir_change = true;
			else if (dir == 3 && new_y == 0) dir_change = true;

			if (dir_change) {
				dir = (dir + 2) % 4;
				shark[i].dir = dir;
			}

			for (int spd = 0; spd < shark[i].speed; spd++) {
				new_x += dx[dir]; new_y += dy[dir];
				if ((dir == 0 || dir == 2) && (new_x == 0 || new_x == r - 1)) {
					dir = (dir + 2) % 4;
					shark[i].dir = dir;
				}
				if ((dir == 1 || dir == 3) && (new_y == 0 || new_y == c - 1)) {
					dir = (dir + 2) % 4;
					shark[i].dir = dir;
				}
			}

			shark[i].x = new_x; shark[i].y = new_y;
			if (map[new_x][new_y] != 0) {
				shark[i].live = 0;
			}
			else map[new_x][new_y] = i + 1;
		}
	}

	printf("%d\n", answer);


	return 0;
}
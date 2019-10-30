#include <iostream>

using namespace std;

const int dx[] = { 0, -1, 0, 1 };
const int dx2[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };

int r, c, t, map[55][55],clean_cnt = 0;
int cleaner[2], tmp[55][55];

void fill_zero(int arr[55][55]) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			arr[i][j] = 0;
		}
	}
}

void copy_map(int src[55][55], int des[55][55]) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			des[i][j] = src[i][j];
		}
	}
	des[cleaner[0]][0] = -1; des[cleaner[1]][0] = -1;
}

void view_() {
	printf("\n\n");
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("%d ", map[i][j]);
		}printf("\n");
	}
}

int main(void) {
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) cleaner[clean_cnt++] = i;
		}
	}

	for (int time_ = 0; time_ < t; time_++) {
		// 확산

		fill_zero(tmp);

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (map[i][j] != 0 && map[i][j] != -1) {
					int baby_cnt = 0;
					for (int dir = 0; dir < 4; dir++) {
						int new_x = i + dx[dir], new_y = j + dy[dir];
						if (new_x < 0 || new_x >= r || new_y < 0 || new_y >= c) continue;
						if (map[new_x][new_y] == -1) continue;
						tmp[new_x][new_y] += map[i][j] / 5;
						baby_cnt++;
					}
					tmp[i][j] += map[i][j] - ((map[i][j] / 5) * baby_cnt);
				}
			}
		}
		
		copy_map(tmp, map);
		//view_();

		int tmp_a = 0, tmp_b = 0;
		int new_x = cleaner[0], new_y = 0;
		// 작동
		for (int dir = 0; dir < 4; dir++) {
			while (1) {
				new_x += dx[dir]; new_y += dy[dir];
				if (new_x < 0 || new_x >= r || new_y < 0 || new_y >= c) break;
				if (dir == 3 && map[new_x][new_y] == -1) break;
				tmp_a = map[new_x][new_y]; map[new_x][new_y] = tmp_b; tmp_b = tmp_a;
			} new_x -= dx[dir]; new_y -= dy[dir];
		}

		tmp_a = 0, tmp_b = 0;
		new_x = cleaner[1], new_y = 0;
		for (int dir = 0; dir < 4; dir++) {
			while (1) {
				new_x += dx2[dir]; new_y += dy[dir];
				if (new_x < 0 || new_x >= r || new_y < 0 || new_y >= c) break;
				if (dir == 3 && map[new_x][new_y] == -1) break;
				tmp_a = map[new_x][new_y]; map[new_x][new_y] = tmp_b; tmp_b = tmp_a;
			} new_x -= dx2[dir]; new_y -= dy[dir];
		}

		//view_();
	}
	
	int answer = 2;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			answer += map[i][j];
		}
	}

	printf("%d\n", answer);

	return 0;
}
#include <iostream>
#include <memory.h>

using namespace std;

int n, answer = 0;
int map[11][11];

void copy_map(int src[11][11], int dest[11][11]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dest[i][j] = src[i][j];
		}
	}
}

void dfs(int idx, int cnt) {
	if (cnt == n) {
		answer++;
		return;
	}

	for (int j = 0; j < n; j++) {
		int i = idx;
		if (map[i][j] == -1) continue;
		// ¸Ê º¹»ç
		int tmp[11][11];
		copy_map(map, tmp);
		// Äý ³õ±â
		map[i][j] = 1;
		bool SUCCESS_ = true;
		for (int ia = i + 1; ia < n; ia++) {
			if (map[ia][j] == 1) {
				SUCCESS_ = false; break;
			}
			map[ia][j] = -1;
		}
		for (int ia = i - 1; ia >= 0; ia--) {
			if (map[ia][j] == 1) {
				SUCCESS_ = false; break;
			}
			map[ia][j] = -1;
		}
		for (int ia = j + 1; ia < n; ia++) {
			if (map[i][ia] == 1) {
				SUCCESS_ = false; break;
			}
			map[i][ia] = -1;
		}
		for (int ia = j - 1; ia >= 0; ia--) {
			if (map[i][ia] == 1) {
				SUCCESS_ = false; break;
			}
			map[i][ia] = -1;
		}

		int next_x = i, next_y = j;
		while (1) {
			next_x += 1; next_y += 1;
			if (next_x >= n || next_y >= n) break;
			if (map[next_x][next_y] == 1) {
				SUCCESS_ = false; break;
			}
			map[next_x][next_y] = -1;
		}

		next_x = i, next_y = j;
		while (1) {
			next_x -= 1; next_y -= 1;
			if (next_x < 0 || next_y < 0) break;
			if (map[next_x][next_y] == 1) {
				SUCCESS_ = false; break;
			}
			map[next_x][next_y] = -1;
		}

		next_x = i, next_y = j;
		while (1) {
			next_x -= 1; next_y += 1;
			if (next_x < 0 || next_y >= n) break;
			if (map[next_x][next_y] == 1) {
				SUCCESS_ = false; break;
			}
			map[next_x][next_y] = -1;
		}

		next_x = i, next_y = j;
		while (1) {
			next_x += 1; next_y -= 1;
			if (next_x >= n || next_y < 0) break;
			if (map[next_x][next_y] == 1) {
				SUCCESS_ = false; break;
			}
			map[next_x][next_y] = -1;
		}

		if (SUCCESS_) {
			//printf("what? x : %d, y : %d cnt : %d\n", i, j, cnt);
			dfs(i + 1, cnt + 1);
		}
			
		// ¸Ê ¿øº¹
		copy_map(tmp, map);
	}
}


int main(void) {
	int t;
	cin >> t;
	for (int te = 1; te <= t; te++) {
		cin >> n; answer = 0;
		memset(map, 0, sizeof(map));
		dfs(0, 0);
		printf("#%d %d\n", te, answer);
	}
	return 0;
}
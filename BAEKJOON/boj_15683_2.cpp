#include <iostream>
#define min(a, b) a < b ? a : b
using namespace std;

struct CAMERA {
	int x, y, idx;
};

int n, m, map[10][10], camera_cnt = 0, answer = 100;
const int ddir[] = { 4,2,4,4,1 };
const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };
CAMERA camera[10];

int calculate() {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) ret++;
		}
	}
	return ret;
}

void copy_map(int src[10][10], int dest[10][10]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dest[i][j] = src[i][j];
		}
	}
}

void map_update(int idx, int dix) {
	dix %= 4;
	int cur_x = camera[idx].x, cur_y = camera[idx].y;
	int new_x = cur_x, new_y = cur_y;
	while (1) {
		new_x += dx[dix]; new_y += dy[dix];
		if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m) break;
		if (map[new_x][new_y] == 6) break;
		else if (map[new_x][new_y] != 0) continue;
		map[new_x][new_y] = -1;
	}
}

void view_() {
	printf("\n[CCTV ¿€µø¡ﬂ]\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", map[i][j]);
		}printf("\n");
	}
}

void dfs(int cnt_) {
	if (cnt_ == camera_cnt) {
		// ªÁ∞¢¡ˆ¥Î ∞≥ºˆ ±∏«œ±‚
		//view_();
		int tmp = calculate();
		answer = min(answer, tmp);
		return;
	}

	int tmp[10][10];
	for (int rot = 0; rot < ddir[camera[cnt_].idx - 1]; rot++) {
		if (camera[cnt_].idx == 1) {
			// ∏  ∫π¡¶
			copy_map(map, tmp);
			// ∏  æ˜µ•¿Ã∆Æ
			map_update(cnt_, rot);
			dfs(cnt_ + 1);
			// ∏  ∫πø¯
			copy_map(tmp, map);
		}
		else if (camera[cnt_].idx == 2) {
			// ∏  ∫π¡¶
			copy_map(map, tmp);
			// ∏  æ˜µ•¿Ã∆Æ
			map_update(cnt_, rot);
			map_update(cnt_, rot + 2);
			dfs(cnt_ + 1);
			// ∏  ∫πø¯
			copy_map(tmp, map);
		}
		else if (camera[cnt_].idx == 3) {
			// ∏  ∫π¡¶
			copy_map(map, tmp);
			// ∏  æ˜µ•¿Ã∆Æ
			map_update(cnt_, rot);
			map_update(cnt_, rot + 1);
			dfs(cnt_ + 1);
			// ∏  ∫πø¯
			copy_map(tmp, map);
		}
		else if (camera[cnt_].idx == 4) {
			// ∏  ∫π¡¶
			copy_map(map, tmp);
			// ∏  æ˜µ•¿Ã∆Æ
			map_update(cnt_, rot);
			map_update(cnt_, rot + 1);
			map_update(cnt_, rot + 3);
			dfs(cnt_ + 1);
			// ∏  ∫πø¯
			copy_map(tmp, map);
		}
		else if (camera[cnt_].idx == 5) {
			// ∏  ∫π¡¶
			copy_map(map, tmp);
			// ∏  æ˜µ•¿Ã∆Æ
			map_update(cnt_, rot);
			map_update(cnt_, rot + 1);
			map_update(cnt_, rot + 2);
			map_update(cnt_, rot + 3);
			dfs(cnt_ + 1);
			// ∏  ∫πø¯
			copy_map(tmp, map);
		}
	}
	
	
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 6) {
				camera[camera_cnt].x = i; camera[camera_cnt].y = j;
				camera[camera_cnt].idx = map[i][j]; camera_cnt++;
			}
		}
	}
	
	dfs(0);
	printf("%d\n", answer);

	return 0;
}
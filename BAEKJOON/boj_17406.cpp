#include <iostream>

#define min(a, b) a < b ? a : b 
#define PRINT_ false

using namespace std;

/*
	1. 순열 만들기
	2. 게임 시작하기
*/

struct CMD_ {
	int r, c, s;
};

CMD_ cmd[8];
int n, m, k, arr[52][52], r, c, s;
int rotate_[6], answer = 0x7fffffff;
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };


int game_start() {
	//printf("[GAME START]\n");
	int tmp[52][52];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			tmp[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		int cur = rotate_[i];
		int cur_x = cmd[cur].r, cur_y = cmd[cur].c, cur_s = cmd[cur].s;
		int xx[4], yy[4];
		for (int ia = 1; ia <= cur_s; ia++) {
			// 가장 가까운 배열부터 돌리기
			xx[0] = cur_x - ia, yy[0] = cur_y - ia, xx[1] = cur_x - ia, yy[1] = cur_y + ia;
			xx[2] = cur_x + ia, yy[2] = cur_y + ia, xx[3] = cur_x + ia, yy[3] = cur_y - ia;
			int tmp_val = tmp[xx[0]][yy[0]], tmp_val2 = 0;
			
			int new_x = xx[0], new_y = yy[0];
			for (int dir = 0; dir < 4; dir++) {
				bool break_sw = false;
				int dir_break_ = (dir + 1) % 4;
				//printf("dir : %d,  dir_break_ : %d\n", dir, dir_break_);
				while (1) {
					int new_x2 = new_x + dx[dir], new_y2 = new_y + dy[dir];
					//printf("new_x : %d, new_y : %d, new_x2 : %d, new_y2 : %d\n", new_x, new_y, new_x2, new_y2);

					if (new_x2 == xx[dir_break_] && new_y2 == yy[dir_break_]) {
						break_sw = true;
					}
					tmp_val2 = tmp[new_x2][new_y2];
					tmp[new_x2][new_y2] = tmp_val;
					tmp_val = tmp_val2;
					new_x = new_x2; new_y = new_y2;
					if (break_sw) break;
				} 
			}
		}
	}

	// 배열의 값 찾기
	int min_val = 0x7fffffff;
	for (int i = 1; i <= n; i++) {
		int tmp_sum = 0;
		for (int j = 1; j <= m; j++) {
			tmp_sum += tmp[i][j];
		}
		min_val = min(min_val, tmp_sum);
	}

	return min_val;
}

void dfs(int cnt) {
	if (cnt == k) {
		if (PRINT_) {
			printf("\n");
			for (int i = 0; i < k; i++) {
				printf("%d ", rotate_[i]);
			}printf("\n");
		}

		// GAME START
		int tmp = game_start();
		answer = min(answer, tmp);
		return;
	}

	for (int i = 0; i < k; i++) {
		bool break_sw = false;
		for (int j = 0; j < k; j++) {
			if (rotate_[j] == i) {
				break_sw = true; break;
			}
		}
		if (break_sw) continue;
		rotate_[cnt] = i;
		dfs(cnt + 1);
		rotate_[cnt] = -1;
	}

}

int main(void) {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i < k; i++) {
		cin >> r >> c >> s;
		cmd[i].r = r; cmd[i].c = c; cmd[i].s = s;
		rotate_[i] = -1;
	}

	dfs(0);
	printf("%d\n", answer);
	return 0;
}
#include <iostream>
#include <queue>
#define mp make_pair
using namespace std;

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };

struct VIRUS {
	int x, y;
};

int m, n, map[55][55];
int virus_cnt = 0, pick[15], answer = 0x7fffffff;
VIRUS virus[15];

void copy_map(int src[55][55], int dest[55][55]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dest[i][j] = src[i][j];
		}
	}
}

void dfs(int idx_, int cnt) {
	if (cnt == m) {
		// 연구소 계산
		int tmp[55][55];
		copy_map(map, tmp);

		int zero_cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 0) zero_cnt++;
			}
		}
		int cnt_tmp = zero_cnt;

		queue<pair<int, int>> q;
		queue<pair<int, int>> nxt_q;
		
		for (int i = 0; i < virus_cnt; i++) {
			if (pick[i] == 1) {
				q.push(mp(virus[i].x, virus[i].y));
			}
		}

		int time_ = 0;
		if (zero_cnt == 0) {
			if (cnt_tmp == 0) answer = min(answer, time_);
			return;
		}
		while (1) {
			time_++;
			while (!q.empty()) {
				int cur_x = q.front().first, cur_y = q.front().second;
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int next_x = cur_x + dx[dir], next_y = cur_y + dy[dir];
					if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n) continue;
					if (map[next_x][next_y] == 1 || map[next_x][next_y] == -1) continue;
					if(map[next_x][next_y] == 0) zero_cnt -= 1;
					map[next_x][next_y] = -1;
					nxt_q.push(mp(next_x, next_y));
				}
			}

			while (!nxt_q.empty()) {
				q.push(nxt_q.front()); nxt_q.pop();
			}

			if (zero_cnt == 0) break;
			else {
				if (zero_cnt == cnt_tmp) break;
				cnt_tmp = zero_cnt;
			}
		}

		if(zero_cnt == 0) answer = min(answer, time_);
		copy_map(tmp, map);
		return;
	}
	for (int i = idx_; i < virus_cnt; i++) {
		pick[i] = 1;
		dfs(i + 1, cnt + 1);
		pick[i] = 0;
	}
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) {
				virus[virus_cnt].x = i; virus[virus_cnt].y = j;
				virus_cnt++; map[i][j] = -2;
			}
		}
	}

	dfs(0, 0);
	if (answer == 0x7fffffff) answer = -1;
	printf("%d\n", answer);

	return 0;
}
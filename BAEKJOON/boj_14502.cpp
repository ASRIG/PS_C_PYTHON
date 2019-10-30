#include <iostream>
#include <queue>
#define max(a, b) a < b ? b :a
#define mp make_pair
using namespace std;

struct VIRUS {
	int x, y;
};

int n, m, map[10][10], virus_cnt = 0;
int answer = 0;
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };
VIRUS v[11];

int test_() {
	int tmp_map[10][10], res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp_map[i][j] = map[i][j];
		}
	}
	queue<pair<int, int>> q;
	for (int i = 0; i < virus_cnt; i++) {
		q.push(mp(v[i].x, v[i].y));
	}

	while (!q.empty()) {
		int cur_x = q.front().first, cur_y = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int new_x = cur_x + dx[dir], new_y = cur_y + dy[dir];
			if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m) continue;
			if (tmp_map[new_x][new_y] == 0) {
				tmp_map[new_x][new_y] = 2;
				q.push(mp(new_x, new_y));
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmp_map[i][j] == 0) res++;
		}
	}
	return res;
}

void dfs(int idx, int jdx, int cnt) {
	if (cnt == 3) {
		int tmp = test_();
		answer = max(answer, tmp);
		return;
	}

	for (int i = idx; i < n; i++) {
		for (int j = jdx; j < m; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				dfs(i, j + 1, cnt + 1);
				map[i][j] = 0;
			}
		}
		jdx = 0;
	}
}


int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				v[virus_cnt].x = i; v[virus_cnt].y = j;
				virus_cnt++;
			}
		}
	}
	dfs(0, 0, 0);
	printf("%d\n", answer);


	return 0;
}

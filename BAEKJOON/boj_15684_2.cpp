#include <iostream>

using namespace std;

int n, m, h, map[32][12], a, b, answer = 4;

bool go_game() {
	for (int i = 1; i <= n; i++) {
		int cur = i;
		for (int j = 1; j <= h; j++) {
			if (map[j][cur] == 1) cur += 1;
			else if (map[j][cur - 1] == 1) cur -= 1;
		}
		if (cur != i) return false;
	}
	return true;
}

void dfs(int idx, int idy, int cnt_) {
	if (cnt_ < answer) {
		bool tmp = go_game();
		if (tmp == true) answer = cnt_;
	}if (cnt_ == 3) return;

	for (int i = idx; i <= h; i++) {
		for (int j = idy; j <= n - 1; j++) {
			if (map[i][j] == 1) continue;
			if (map[i][j + 1] == 1 || map[i][j - 1] == 1) continue;
			map[i][j] = 1;
			dfs(i, j + 1, cnt_ + 1);
			map[i][j] = 0;
		}
		idy = 1;
	}
}


int main(void) {
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		map[a][b] = 1;
	}
	dfs(1, 1, 0);
	if (answer == 4) answer = -1;
	printf("%d\n", answer);
	return 0;
}
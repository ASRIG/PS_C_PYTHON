#include <iostream>
#include <algorithm>
using namespace std;

int n, answer = 0;
char map[52][52];
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

void swap(int &aa, int &bb) {
	int tmp = aa; aa = bb; bb = tmp;
}

int game_start(int a, int b) {
	int ret = 0;
	for (int dir = 0; dir < 4; dir++) {
		int new_x = a + dx[dir], new_y = b + dy[dir];
		if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= n) continue;
		swap(map[a][b], map[new_x][new_y]);
		char cur = map[a][b];
		int idx = a, cnt1 = -1, cnt2 = -1;
		// 아래쪽 찾기
		while (1) {
			char new_cur = map[idx][b];
			if (cur == new_cur) {
				idx += 1; cnt1 += 1;
				if (idx < 0 || idx >= n) break;
			}
			else break;
		}

		idx = a;
		// 위쪽 찾기
		while (1) {
			char new_cur = map[idx][b];
			if (cur == new_cur) {
				idx -= 1; cnt1 += 1;
				if (idx < 0 || idx >= n) break;
			}
			else break;
		}

		idx = b;
		// 오른쪽 찾기
		while (1) {
			char new_cur = map[a][idx];
			if (cur == new_cur) {
				idx += 1; cnt2 += 1;
				if (idx < 0 || idx >= n) break;
			}
			else break;
		}

		idx = b;
		// 왼쪽 찾기
		while (1) {
			char new_cur = map[a][idx];
			if (cur == new_cur) {
				idx -= 1; cnt2 += 1;
				if (idx < 0 || idx >= n) break;
			}
			else break;
		}

		ret = max({cnt1, cnt2, ret});
		swap(map[new_x][new_y], map[a][b]);
	}
	return ret;
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp = game_start(i, j);
			answer = max(answer, tmp);
		}
	}

	printf("%d\n", answer);
	return 0;
}
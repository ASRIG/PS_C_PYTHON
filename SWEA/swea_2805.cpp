#include <iostream>

using namespace std;

int t, answer, n;
const int dx = 1;
const int dy[] = { -1, 1 };
bool team_[51][51];
char arr[51][51];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> t;
	for (int tes = 1; tes <= t; tes++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j]; team_[i][j] = 0;
			}
		}
		
		int cur_x = 0, cur_y = n / 2;
		team_[cur_x][cur_y] = 1;

		int new_x1 = cur_x, new_y1 = cur_y;
		while (1) {
			new_x1 += dx, new_y1 += dy[0];
			if (new_y1 < 0 || new_y1 >= n) break;
			team_[new_x1][new_y1] = 1;
		}new_x1 -= dx; new_y1 -= dy[0];

		int new_x2 = cur_x, new_y2 = cur_y;
		while (1) {
			new_x2 += dx, new_y2 += dy[1];
			if (new_y2 < 0 || new_y2 >= n) break;
			team_[new_x2][new_y2] = 1;
		}new_x2 -= dx; new_y2 -= dy[1];

		int new_x3 = new_x1, new_y3 = new_y1;
		while (1) {
			new_x3 += dx, new_y3 += dy[1];
			if (new_x3 < 0 || new_x3 >= n) break;
			team_[new_x3][new_y3] = 1;
		}new_x3 -= dx; new_y3 -= dy[1];

		int new_x4 = new_x2, new_y4 = new_y2;
		while (1) {
			new_x4 += dx, new_y4 += dy[0];
			if (new_x4 < 0 || new_x4 >= n) break;
			team_[new_x4][new_y4] = 1;
		}new_x4 -= dx; new_y4 -= dy[0];

		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n; j++) {
				if (team_[i][j]) {
					int cur_i = i;
					while (1) {
						cur_i += 1;
						if (team_[cur_i][j]) break;
						team_[cur_i][j] = 1;
					}
				}
			}
		}

		answer = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (team_[i][j] == 1) answer += (arr[i][j] - '0');
			}
		}

		
		printf("#%d %d\n", tes, answer);
	}

	return 0;
}
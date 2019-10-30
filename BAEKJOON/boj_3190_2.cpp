#include <iostream>

using namespace std;

int n, k, map[105][105], tx, ty, l, tc;
int head_x = 0, head_y = 0, dir = 0;
int tail_x = 0, tail_y = 0, tail_time = 0, tail_dir = 0;
char cmd[10500], tcd;

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };

int main(void) {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> tx >> ty; tx -= 1; ty -= 1;
		map[tx][ty] = 2;
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		cin >> tc >> tcd;
		cmd[tc] = tcd;
	}

	map[head_x][head_y] = 1;

	int tim = 0;
	for (;;) {
		tim++;
		head_x += dx[dir]; head_y += dy[dir];
		// 呕免 炼扒
		if (head_x < 0 || head_x >= n || head_y < 0 || head_y >= n) break;
		if (map[head_x][head_y] == 1) break;

		// 瘤贩捞 框流捞扁
		if (map[head_x][head_y] == 2) {
			map[head_x][head_y] = 1;
		}
		else {
			// 部府 贸府
			map[head_x][head_y] = 1; map[tail_x][tail_y] = 0;
			tail_x += dx[tail_dir]; tail_y += dy[tail_dir];
			tail_time++;
			if (cmd[tail_time] == 'L') tail_dir = (tail_dir + 3) % 4;
			else if (cmd[tail_time] == 'D') tail_dir = (tail_dir + 1) % 4;
		}

		// cmd 贸府
		if (cmd[tim] == 'L') dir = (dir + 3) % 4;
		else if (cmd[tim] == 'D') dir = (dir + 1) % 4;
	}

	printf("%d\n", tim);
	return 0;
}
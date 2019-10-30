#include <iostream>

using namespace std;


int head_x, head_y, tail_x, tail_y;
int size_ = 1;
int N, K, a, b, L;
char c;
int map[102][102];
char cmd[10005];

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

void show() {
	printf("\n");
	for (int i = 0; i < N;i++) {
	for (int j = 0; j < N; j++) {
	printf("%d", map[i][j]);
	}printf("\n");
	}
}

int main(void) {
	cin >> N; cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> a >> b;
		map[a - 1][b - 1] = 2;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		cin >> a >> c;
		cmd[a] = c;
	}

	head_x = 0; head_y = 0; tail_x = 0; tail_y = 0; size_ = 1;
	int time_ = 0, cur_idx = 1, tail_cnt = 0, tail_idx = 1;
	map[head_x][head_y] = 1;

	while (1) {
		time_++;
		//printf("time_ : %d -> %d %d %d\n", time_, head_x, head_y, cur_idx);

		head_x += dx[cur_idx]; head_y += dy[cur_idx];
		if (head_x < 0 || head_x >= N || head_y < 0 || head_y >= N) break;
		if (map[head_x][head_y] == 1) break;
		else if (map[head_x][head_y] == 2) {
			map[head_x][head_y] = 1;
		}
		else {
			map[tail_x][tail_y] = 0; map[head_x][head_y] = 1;
			
			tail_x += dx[tail_idx]; tail_y += dy[tail_idx];
			tail_cnt++;
			if (cmd[tail_cnt] == 'D') {
				tail_idx = (tail_idx + 1) % 4;
			}
			else if (cmd[tail_cnt] == 'L') {
				tail_idx = (tail_idx + 3) % 4;
			}
		}

		if (cmd[time_] == 'D') {
			cur_idx = (cur_idx + 1) % 4;
		}
		else if (cmd[time_] == 'L') {
			cur_idx = (cur_idx + 3) % 4;
		}
		//show();
	}
	printf("%d\n", time_);
	return 0;
}

#include <iostream>
#include <stack>
using namespace std;

struct MAL {
	int x, y, dir, up_;
	bool bottom_ = true;
};
MAL d[12];
int map[15][15], n, k, move_[15][15];
const int dx[] = { 0,0,-1,1 };
const int dy[] = { 1,-1,0,0 };

void view_move_() {
	printf("\n");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", move_[i][j]);
		}printf("\n");
	}

	printf("\n");
	for (int i = 1; i <= k; i++) {
		printf("i : %d, up_ = %d\n", i, d[i].up_);
	}
}

int main(void) {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= k; i++) {
		cin >> d[i].x >> d[i].y >> d[i].dir;
		d[i].dir -= 1; d[i].bottom_ = true; d[i].up_ = 0;
		move_[d[i].x][d[i].y] = i;
	}

	int answer = -1;
	for (int time_ = 1; time_ < 1000; time_++) {
		for (int i = 1; i <= k; i++) {
			if (d[i].bottom_ == false) continue;
			bool red_sw = false;
			int cur_i = d[i].x, cur_j = d[i].y;
			int new_i = d[i].x  + dx[d[i].dir], new_j = d[i].y + dy[d[i].dir];
			//printf("test001\n");
			//printf("[i : %d]\n", i);
			//view_move_();
			// 파란색
			if ((new_i < 1 || new_i > n || new_j < 1 || new_j > n) || map[new_i][new_j] == 2) {
				if (d[i].dir == 1 || d[i].dir == 0) {
					d[i].dir = 1 - d[i].dir;
				}
				else {
					d[i].dir = 5 - d[i].dir;
				}
				new_i = d[i].x + dx[d[i].dir], new_j = d[i].y + dy[d[i].dir];
				// 다시한번 벽에 부딪힐 경우
				if ((new_i < 1 || new_i > n || new_j < 1 || new_j > n) || map[new_i][new_j] == 2) {
					new_i = d[i].x; new_j = d[i].y;
					continue;
				}
				else {
					// 가능한 경우
				}
			}
			// 빨간색
			else if (map[new_i][new_j] == 1) {
				red_sw = true;
			}
			// 흰색
			else {
				//
			}
			//printf("test002\n");

			// 합치는 과정
			if (red_sw == false && move_[new_i][new_j] > 0) {
				move_[cur_i][cur_j] = 0;
				// 현재 바닥에서 가장 위에 있는 말을 찾음
				int cur_bot = move_[new_i][new_j];
				while (1) {
					int tmp = d[cur_bot].up_;
					if (tmp == 0) break;
					cur_bot = tmp;
				}

				d[cur_bot].up_ = i;
				// 새 드론이 움직이는 곳에 모든걸 다 옮겨야함
				int cur_tmp = i;
				d[cur_tmp].x = new_i; d[cur_tmp].y = new_j;
				while (1) {
					int tmp = d[cur_tmp].up_;
					if (tmp == 0) break;
					cur_tmp = tmp;
					d[cur_tmp].x = new_i; d[cur_tmp].y = new_j;
				}

				d[i].bottom_ = false;

				// 4개가 되었는지 확인
				int cnt = 1;
				cur_bot = move_[new_i][new_j];
				while (1) {
					int tmp = d[cur_bot].up_;
					if (tmp == 0) break;
					cur_bot = tmp;
					cnt++;
				}

				if (cnt == 4) {
					printf("%d\n", time_); return 0;
				}
			}
			else {
				// 내꺼 전체 이동
				move_[cur_i][cur_j] = 0;
				move_[new_i][new_j] = i;
				int cur_tmp = i;
				d[cur_tmp].x = new_i; d[cur_tmp].y = new_j;
				
				while (1) {
					int tmp = d[cur_tmp].up_;
					//printf("tmp : %d\n", tmp);
					if (tmp == 0) break;
					cur_tmp = tmp;
					d[cur_tmp].x = new_i; d[cur_tmp].y = new_j;
				}
			}
			
			if (red_sw && move_[new_i][new_j] == 0) {
				// 순서를 바꿔준다.
				stack<int> s;
				int cur_k = move_[new_i][new_j];
				s.push(cur_k);	

				while (1) {
					int tmp = d[cur_k].up_;
					if (tmp == 0) break;
					cur_k = tmp;
					s.push(cur_k);
				}
				d[cur_k].up_ = 0;

				d[s.top()].bottom_ = true; d[move_[new_i][new_j]].bottom_ = false;
				d[move_[new_i][new_j]].up_ = 0;
				move_[new_i][new_j] = s.top();

				while (!s.empty()) {
					int k = s.top(); s.pop();
					if (s.empty()) break;
					int k2 = s.top();
					d[k].up_ = k2;
				}
			}
			else if (red_sw && move_[new_i][new_j] > 0) {
				move_[cur_i][cur_j] = 0;
				// 현재 바닥에서 가장 위에 있는 말을 찾음
				int cur_bot = move_[new_i][new_j];
				while (1) {
					int tmp = d[cur_bot].up_;
					if (tmp == 0) break;
					cur_bot = tmp;
				}

				// 지금꺼 순서 바꿔서 만든다.
				stack<int> s;
				int cur_k = i;
				s.push(cur_k);
				while (1) {
					int tmp = d[cur_k].up_;
					if (tmp == 0) break;
					cur_k = tmp;
					s.push(cur_k);
				}
				int tmp_top = s.top();
				d[cur_k].up_ = 0;

				d[i].bottom_ = false; d[i].up_ = 0;
				while (!s.empty()) {
					int k = s.top(); s.pop();
					if (s.empty()) break;
					int k2 = s.top();
					d[k].up_ = k2;
				}

				// 새로만든 배열을 대입
				d[cur_bot].up_ = tmp_top;
				// 새 드론이 움직이는 곳에 모든걸 다 옮겨야함
				int cur_tmp = tmp_top;
				d[cur_tmp].x = new_i; d[cur_tmp].y = new_j;
				while (1) {
					int tmp = d[cur_tmp].up_;
					printf("tmp : %d\n", tmp);
					if (tmp == 0) break;
					cur_tmp = tmp;
					d[cur_tmp].x = new_i; d[cur_tmp].y = new_j;
				}
			}
		}
	}
	printf("%d\n", answer);

	return 0;
}


#include <iostream>
#include <queue>
#include <cstdlib>
#define mp make_pair
using namespace std;

char hyuck[21][21];
bool quest_[21][21];
int path_[21][21][4][16];
int t, r, c, cur_d, cur_x, cur_y, cur_mem;

const int dx[] = { 0, 0, 1, -1 };
const int dy[] = { 1, -1, 0, 0 };

struct GO{
	int x, y, d, mem;
	GO() {};
	GO(int a, int b, int c, int dd) {
		x = a; y = b; d = c; mem = dd;
	}
};

int main(void) {
	cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		bool SUCCES = false;
		cin >> r >> c;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> hyuck[i][j];
			}
		}
		memset(path_, -1, sizeof(path_));

		queue<GO> q;
		q.push(GO(0, 0, 0, 0));
		while (!q.empty()) {
			GO cur_go = q.front(); q.pop();
			cur_d = cur_go.d; cur_x = cur_go.x; 
			cur_y = cur_go.y; cur_mem = cur_go.mem;

			//if (path_[cur_x][cur_y][cur_d][cur_mem] == 1) continue;
			//path_[cur_x][cur_y][cur_d][cur_mem] = 1;
			//printf("cur_x : %d cur_y : %d\n", cur_x, cur_y);

			// 현재 위치의 일을 실행
			if (hyuck[cur_x][cur_y] == '<') {
				cur_d = 1;
			}
			else if (hyuck[cur_x][cur_y] == '>') {
				cur_d = 0;
			}
			else if (hyuck[cur_x][cur_y] == '^') {
				cur_d = 3;
			}
			else if (hyuck[cur_x][cur_y] == 'v') {
				cur_d = 2;
			}
			else if (hyuck[cur_x][cur_y] == '_') {
				if (cur_mem == 0) cur_d = 0;
				else cur_d = 1;
			}
			else if (hyuck[cur_x][cur_y] == '|') {
				if (cur_mem == 0) cur_d = 2;
				else cur_d = 3;
			}
			else if (hyuck[cur_x][cur_y] == '?') {
				for (int dir = 0; dir < 4; dir++) {
					int new_x = cur_x + dx[dir], new_y = cur_y + dy[dir];
					if (new_x < 0) new_x = r - 1;
					else if (new_x >= r) new_x = 0;
					else if (new_y < 0) new_y = c - 1;
					else if (new_y >= c) new_y = 0;
					q.push(GO(new_x, new_y, dir, cur_mem));
				}
				continue;
				// 처리
			}
			else if (hyuck[cur_x][cur_y] == '@') {
				SUCCES = true;
				break;
			}
			else if (hyuck[cur_x][cur_y] == '.') {
				//
			}
			else if (hyuck[cur_x][cur_y] == '+') {
				cur_mem++;
				if (cur_mem == 16) cur_mem = 0;
			}
			else if (hyuck[cur_x][cur_y] == '-') {
				cur_mem--;
				if (cur_mem == -1) cur_mem = 15;
			}
			else{
				cur_mem = hyuck[cur_x][cur_y] - '0';
			}
			
			// 다음 장소로 이동
			int new_x = cur_x + dx[cur_d], new_y = cur_y + dy[cur_d];
			if (new_x < 0) new_x = r - 1;
			else if (new_x >= r) new_x = 0;
			else if (new_y < 0) new_y = c - 1;
			else if (new_y >= c) new_y = 0;
			q.push(GO(new_x, new_y, cur_d, cur_mem));
		}

		while (!q.empty()) q.pop();

		if (SUCCES) printf("#%d YES\n", tt);
		else  printf("#%d NO\n", tt);
	}
	return 0;
}
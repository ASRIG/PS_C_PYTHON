#include <iostream>
#include <queue>
using namespace std;

struct PIPE {
	int type;
	int x1, x2, x3, x4, y1, y2, y3, y4;
	PIPE(int i_type, int a, int b, int c, int d, int a2 = 0, int b2 = 0, int c2 = 0, int d2 = 0) {
		type = i_type; x1 = a; y1 = b; x2 = c; y2 = d;
		x3 = a2; y3 = b2; x4 = c2; y4 = d2;
	}
};

const int dir[] = { 2, 2, 3 };
int n, map[18][18], answer = 0;

int main(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			// 0 바닥, 1 벽
			cin >> map[i][j];
		}
	}
	PIPE p(0, 1, 1, 1, 2);
	queue<PIPE> q;
	q.push(p);
	
	while (!q.empty()) {
		PIPE cur = q.front(); q.pop();
		if (cur.type == 0) {
			// 첫번째 경우
			int new_x1 = cur.x1, new_y1 = cur.y1 + 1;
			int new_x2 = cur.x2, new_y2 = cur.y2 + 1;
			if (new_y2 > n) continue;
			if (map[new_x2][new_y2] == 1) continue;
			if (new_x2 == n && new_y2 == n) {
				answer += 1; continue;
			}
			q.push(PIPE(0, new_x1, new_y1, new_x2, new_y2));


			// 두번째 경우
			new_x1 = cur.x1; new_y1 = cur.y1 + 1;
			new_x2 = cur.x2 + 1; new_y2 = cur.y2 + 1;
			int new_x3 = cur.x2, new_y3 = cur.y2 + 1;
			int new_x4 = cur.x2 + 1, new_y4 = cur.y2;
			if (new_y2 > n || new_x2 > n)continue;
			if (map[new_x2][new_y2] == 1 || map[new_x3][new_y3] == 1 || map[new_x4][new_y4] == 1) continue;
			if (new_x2 == n && new_y2 == n) {
				answer += 1; continue;
			}
			q.push(PIPE(2, new_x1, new_y1, new_x2, new_y2, new_x3, new_y3, new_x4, new_y4));
		}
		else if (cur.type == 1) {
			// 첫번째 경우
			int new_x1 = cur.x1 + 1, new_y1 = cur.y1;
			int new_x2 = cur.x2 + 1, new_y2 = cur.y2;
			if (new_x2 > n) continue;
			if (map[new_x2][new_y2] == 1) continue;
			if (new_x2 == n && new_y2 == n) {
				answer += 1; continue;
			}
			q.push(PIPE(1, new_x1, new_y1, new_x2, new_y2));

			// 두번째 경우
			new_x1 = cur.x1 + 1; new_y1 = cur.y1;
			new_x2 = cur.x2 + 1; new_y2 = cur.y2 + 1;
			int new_x3 = cur.x2, new_y3 = cur.y2 + 1;
			int new_x4 = cur.x2 + 1, new_y4 = cur.y2;
			if (new_y2 > n || new_x2 > n)continue;
			if (map[new_x2][new_y2] == 1 || map[new_x3][new_y3] == 1 || map[new_x4][new_y4] == 1) continue;
			if (new_x2 == n && new_y2 == n) {
				answer += 1; continue;
			}
			q.push(PIPE(2, new_x1, new_y1, new_x2, new_y2, new_x3, new_y3, new_x4, new_y4));
		}
		else if (cur.type == 2) {
			// 첫번째 경우
			int new_x1 = cur.x1 + 1, new_y1 = cur.y1 + 1;
			int new_x2 = cur.x2, new_y2 = cur.y2 + 1;
			if (new_y2 <= n && map[new_x2][new_y2] != 1) {
				if (new_x2 == n && new_y2 == n) {
					answer += 1; continue;
				}
				q.push(PIPE(0, new_x1, new_y1, new_x2, new_y2));
			}
			

			
			// 두번째 경우
			new_x1 = cur.x1 + 1, new_y1 = cur.y1 + 1;
			new_x2 = cur.x2 + 1, new_y2 = cur.y2;
			if (new_x2 <= n && map[new_x2][new_y2] != 1) {
				if (new_x2 == n && new_y2 == n) {
					answer += 1; continue;
				}
				q.push(PIPE(1, new_x1, new_y1, new_x2, new_y2));
			}

			// 세번째 경우
			new_x1 = cur.x1 + 1; new_y1 = cur.y1 + 1;
			new_x2 = cur.x2 + 1; new_y2 = cur.y2 + 1;
			int new_x3 = cur.x2, new_y3 = cur.y2 + 1;
			int new_x4 = cur.x2 + 1, new_y4 = cur.y2;
			if (new_y2 > n || new_x2 > n)continue;
			if (map[new_x2][new_y2] == 1 || map[new_x3][new_y3] == 1 || map[new_x4][new_y4] == 1) continue;
			if (new_x2 == n && new_y2 == n) {
				answer += 1; continue;
			}
			q.push(PIPE(2, new_x1, new_y1, new_x2, new_y2, new_x3, new_y3, new_x4, new_y4));
		}
	}


	printf("%d\n", answer);

	return 0;
}
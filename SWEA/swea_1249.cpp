#include <iostream>
#include <algorithm>
#include <queue>
#define mp make_pair
#define INF 10000000
using namespace std;

int t, n,  answer = 0x7fffffff, d[101][101], map[101][101];
char tmp[101][101];
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0,0,-1,1 };

int main(void) {
	cin >> t;
	for (int tes = 1; tes <= t; tes++) {
		answer = 0x7fffffff;
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> tmp[i][j]; d[i][j] = INF;
				map[i][j] = tmp[i][j] - '0';
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d ", map[i][j]);
			}printf("\n");
		}
		printf("\n");

		priority_queue<pair<int, pair<int, int>>> q;
		q.push(mp(0, mp(0, 0))); d[0][0] = 0;

		while (!q.empty()) {
			int cur_x = q.top().second.first, cur_y = q.top().second.second;
			int cur_d = -q.top().first; q.pop();
			//printf("x : %d y : %d d : %d\n", cur_x, cur_y, cur_d);
			if (d[cur_x][cur_y] != cur_d) continue;
			for (int dir = 0; dir < 4; dir++) {
				int new_x = cur_x + dx[dir], new_y = cur_y + dy[dir];
				if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= n) continue;
				int new_d = cur_d + map[new_x][new_y];
				if (d[new_x][new_y] > new_d) {
					d[new_x][new_y] = new_d;
					q.push(mp(-new_d, mp(new_x, new_y)));
				}
			}
		}


		answer = d[n - 1][n - 1];
		printf("#%d %d\n", tes, answer);
	}


	return 0;
}
#include <iostream>
#include <queue>
#include <algorithm>
#define mp make_pair
using namespace std;

int n, m, k, a[15][15], x, y, z;
int map[15][15]; 
const int dx[] = { -1, 0, 1, 0, 1, 1, -1, -1 };
const int dy[] = { 0, -1, 0, 1, -1, 1, -1, 1 };

struct TREE {
	int x, y, age;
	TREE(int a = 0, int b = 0, int c = 0):x(a), y(b), age(c){}
	
	bool operator < (const TREE &tre) const {
		return this->age < tre.age;
	}
};

int main(void) {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j]; map[i][j] = 5;
		}
	}
	
	TREE tmp[102];
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z; x -= 1; y -= 1;
		TREE temp_(x, y, z); tmp[i] = temp_;
	}
	sort(tmp, tmp + m);

	queue<TREE> q;
	for (int i = 0; i < m; i++) {
		q.push(tmp[i]);
	}

	queue<TREE> dead_q, spring_q, tmp_q;
	for (int tim = 0; tim < k; tim++) {
		// 봄
		while (!q.empty()) {
			TREE cur = q.front(); q.pop();
			if (map[cur.x][cur.y] < cur.age) {
				dead_q.push(cur);
			}
			else {
				map[cur.x][cur.y] -= cur.age;
				cur.age += 1; spring_q.push(cur);
			}
		}

		// 여름
		while (!dead_q.empty()) {
			TREE cur = dead_q.front(); dead_q.pop();
			map[cur.x][cur.y] += (cur.age / 2);
		}

		// 가을
		while (!spring_q.empty()) {
			TREE cur = spring_q.front(); spring_q.pop();
			tmp_q.push(cur);
			if (cur.age % 5 != 0) continue;
			for (int dir = 0; dir < 8; dir++) {
				int new_x = cur.x + dx[dir], new_y = cur.y + dy[dir];
				if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= n) continue;
				q.push(TREE(new_x, new_y, 1));
			}
		}

		while (!tmp_q.empty()) {
			q.push(tmp_q.front()); tmp_q.pop();
		}

		// 겨울
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				map[i][j] += a[i][j];
			}
		}
	}

	printf("%d\n", q.size());

	return 0;
}
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct TREE {
	int x, y, age;

	TREE() {}
	TREE(int a, int b, int c) : x(a), y(b), age(c) {}

	bool operator < (const TREE &tre) const {
		return this->age < tre.age;
	}
};

int n, m, k, map[15][15], a[15][15];
TREE tree[105];
const int dx[] = { 0,0,1,-1, -1,1,-1,1 };
const int dy[] = { -1,1,0,0, 1,1,-1,-1 };

int main(void) {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			map[i][j] = 5;
		}
	}

	int x, y, z;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z; x -= 1; y -= 1;
		tree[i].x = x; tree[i].y = y; tree[i].age = z;
	}

	sort(tree, tree + m);
	queue<TREE> q, spring_q, dead_q, new_q, fall_q;

	for (int i = 0; i < m; i++) {
		q.push(tree[i]);
	}

	for (int i = 1; i <= k; i++) {
		// 봄
		while (!q.empty()) {
			TREE cur_tree = q.front(); q.pop();
			if (map[cur_tree.x][cur_tree.y] >= cur_tree.age) {
				map[cur_tree.x][cur_tree.y] -= cur_tree.age;
				cur_tree.age += 1; spring_q.push(cur_tree);
			}
			else {
				// dead
				dead_q.push(cur_tree);
			}
		}

		// 여름
		while (!dead_q.empty()) {
			TREE cur_tree = dead_q.front(); dead_q.pop();
			map[cur_tree.x][cur_tree.y] += (cur_tree.age / 2);
		}

		// 가을
		while (!spring_q.empty()) {
			TREE cur_tree = spring_q.front(); spring_q.pop();
			fall_q.push(cur_tree);
			if (cur_tree.age % 5 != 0) continue;
			for (int dir = 0; dir < 8; dir++) {
				int new_x = cur_tree.x + dx[dir], new_y = cur_tree.y + dy[dir];
				if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= n) continue;
				new_q.push(TREE(new_x, new_y, 1));
			}
		}

		// 겨울
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				map[i][j] += a[i][j];

		while (!new_q.empty()) {
			TREE cur_tree = new_q.front(); new_q.pop();
			q.push(cur_tree);
		}
		while (!fall_q.empty()) {
			TREE cur_tree = fall_q.front(); fall_q.pop();
			q.push(cur_tree);
		}
	}

	printf("%d\n", q.size());


	return 0;
}
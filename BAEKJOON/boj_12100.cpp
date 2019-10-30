#include <iostream>
#include <queue>

#define max(a, b) a < b ? b : a
using namespace std;

struct MAP {
	int a[21][21], n, cnt;

	void rotate() {
		int b[21][21];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				b[i][j] = a[i][j];
			}
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = b[j][n - 1 - i];
			}
		}
	}

	void up() {
		int tmp[21][21];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				tmp[i][j] = 0;
			}
		}

		for (int j = 0; j < n; j++) {
			int cnt = 0, index_ = 0;
			for (int i = 0; i < n; i++) {
				if (a[i][j] == 0) continue;
				tmp[cnt++][j] = a[i][j];

				if (index_ == 1) {
					if (tmp[cnt - 1][j] == tmp[cnt - 2][j]) {
						tmp[cnt - 1][j] = 0; tmp[cnt - 2][j] *= 2; index_ = 0;
						cnt--;
					}
				}
				else {
					index_ = 1;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = tmp[i][j];
			}
		}
	}

	void print() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d ", a[i][j]);
			}printf("\n");
		}
	}
};

int num, answer = 0;
MAP m;

void dfs(int cnt, MAP c) {
	if (cnt == 5) {
		int max_num = 0;
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				max_num = max(max_num, c.a[i][j]);
			}
		}
		answer = max(answer, max_num);
		return;
	}

	
	for (int i = 0; i < 4; i++) {
		MAP tmp = c;
		tmp.up();
		dfs(cnt + 1, tmp);
		c.rotate();
	}
}

int main(void) {
	cin >> num;
	m.n = num;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			cin >> m.a[i][j];
		}
	}

	dfs(0, m);

	printf("%d\n", answer);

	return 0;
}
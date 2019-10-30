#include <iostream>
#define max(a, b) a < b ? b : a
using namespace std;

struct MAP {
	int a[21][21], n;

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
		int tmp[22][22];

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
					if (tmp[cnt - 2][j] == tmp[cnt - 1][j]) {
						tmp[cnt - 2][j] *= 2; tmp[cnt - 1][j] = 0;
						cnt -= 1; index_ = 0;
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

	

	void view() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d ", a[i][j]);
			}printf("\n");
		}
	}
};

MAP mm;
int num, answer = 0;

void dfs(int cnt, MAP cur) {
	if (cnt == 5) {
		int max_num = 0;
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				max_num = max(max_num, cur.a[i][j]);
			}
		}
		answer = max(answer, max_num);
		return;
	}

	for (int dir = 0; dir < 4; dir++) {
		MAP tmp = cur;
		tmp.up();
		dfs(cnt + 1, tmp);
		cur.rotate();

	}
}

int main(void) {
	cin >> num; mm.n = num;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			cin >> mm.a[i][j];
		}
	}
	dfs(0, mm);

	printf("%d\n", answer);
	return 0;
}
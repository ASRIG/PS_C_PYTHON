#include <iostream>
#define INF 105050
using namespace std;

int n, m, a[105][105], c, d;

int min(int a, int b) {
	if (a < b) return a;
	else return b;
}

int main(void) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = INF;
	for (int i = 0; i < m; i++) {
		cin >> c >> d;
		a[c][d] = 1; a[d][c] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				a[i][j] = min(a[i][k] + a[k][j], a[i][j]);
			}
		}
	}
	int answer = 7899, idx_ = 0;
	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		for (int j = 1; j <= n; j++) {
			tmp += a[i][j];
		}
		if (answer > tmp) {
			answer = tmp; idx_ = i;
		}
	}

	printf("%d\n", idx_);

	return 0;
}
#include <iostream>
#include <algorithm>

#define INF 505050
using namespace std;

int n, i, a, b;
int m[55][55];

int main(void) {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if(i != j) m[i][j] = INF;


	for (i = 0; ;i++) {
		cin >> a >> b;
		if (a == -1 && b == -1) break;
		m[a][b] = 1; m[b][a] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n;i++) {
			for (int j = 1; j <= n; j++) {
				m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
			}
		}
	}

	int answer[55], minn = 80000;
	for (int i = 1; i <= n;i++) {
		int this_max = 0;
		for (int j = 1; j <= n; j++) {
			this_max = max(this_max, m[i][j]);
		}
		answer[i] = this_max;
		if (this_max < minn) minn = this_max;
	}
	int cnt = 0;
	for (int i = 1; i <= n;i++) {
		if (minn == answer[i]) cnt++;
	}

	printf("%d %d\n", minn, cnt);
	for (int i = 1; i <= n;i++) {
		if (minn == answer[i]) printf("%d ", i);
	}printf("\n");
	return 0;
}
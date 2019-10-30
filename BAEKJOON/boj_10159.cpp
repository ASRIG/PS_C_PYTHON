#include <iostream>
#include <algorithm>
#define INF 1586486
using namespace std;

int N, M, a, b, m[105][105], m2[105][105];

int main(void) {
	cin >> N; cin >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j) m[i][j] = INF, m2[i][j] = INF;
		}
	}

	for (int i = 1; i <= M; i++) {
		cin >> a >> b;
		// a > b
		m[a][b] = 1; m2[b][a] = 1;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
				m2[i][j] = min(m2[i][j], m2[i][k] + m2[k][j]);
			}
		}
	}
	
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (m[i][j] == INF && m2[i][j] == INF) cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
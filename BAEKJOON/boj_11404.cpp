#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define mp make_pair
using namespace std;

int n, m, a, b, c;
long arr[105][105];
int INF = 100000000;

int main(void) {
	cin >> n; cin >> m;
	for (int i = 1; i <= n;i++) {
		for (int j = 1; j <= n;j++) {
			if (i == j) arr[i][j] = 0;
			else arr[i][j] = INF;
		}
	}

	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		if(arr[a][b] > c) arr[a][b] = c;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n;j++) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n;j++) {
			if (arr[i][j] == INF) printf("0 ");
			else printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
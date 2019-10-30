#include <iostream>

using namespace std;

int T, a, b, dp0[105][105], dp1[105][105];

int main(void) {
	cin >> T;
	// n, k
	dp0[1][0] = 1; dp1[1][0] = 1;
	for (int i = 2; i <= 100; i++) {
		for (int j = 0; j <= i - 1; j++) {
			dp0[i][j] = dp0[i - 1][j] + dp1[i - 1][j];
			if (j == 0) {
				dp1[i][j] = dp0[i - 1][j];
			}
			else {
				dp1[i][j] = dp0[i - 1][j] + dp1[i - 1][j - 1];
			}
		}
	}
	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		printf("%d\n", dp0[a][b] + dp1[a][b]);
	}

	return 0;
}
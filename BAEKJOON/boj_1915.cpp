#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int n, m, answer = 0;
char map[1005][1005];
int dp[1005][1005];

int main(void) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == '0') dp[i][j] = 0;
			else {
				dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j - 1], dp[i - 1][j])) + 1;
				if (answer < dp[i][j]) answer = dp[i][j];
			}
		}
	}

	printf("%d\n", answer* answer);
	return 0;
}
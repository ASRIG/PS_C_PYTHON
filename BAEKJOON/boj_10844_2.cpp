#include <iostream>
#define E9 (int)1e9
using namespace std;

int dp[102][10], n;

int main(void) {
	cin >> n;
	for (int j = 1; j < 10; j++) dp[1][j] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) dp[i][j] = dp[i - 1][j + 1];
			else if (j == 9) dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = dp[i - 1][j - 1] % E9 + dp[i - 1][j + 1] % E9;
			dp[i][j] %= E9;
		}
	}

	int ans = 0;
	for (int i = 0; i < 10; i++) {
		ans = (ans + dp[n][i]) % E9;
	}
	printf("%d\n", ans);

	return 0;
}
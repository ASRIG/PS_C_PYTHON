#include <iostream>

using namespace std;

int dp[1001][1001], n, k;

int main(void) {
	cin >> n >> k;
	// 초기값 설정 (nC0 = 1)
	for (int i = 0; i <= 1000; i++) dp[i][0] = 1, dp[i][1] = i;
	// 이항계수의 성질을 이용 nCk = (n-1)Ck + (n-1)C(k-1)
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 10007;
		}
	}

	printf("%d\n", dp[n][k]);

	return 0;
}
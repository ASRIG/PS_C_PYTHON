#include <iostream>

using namespace std;

int n, dp[1001][10];

int main(void) {
	cin >> n;
	for (int j = 0; j < 10; j++) dp[1][j] = 1;
	// 오름수 전체를 확인
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 10007;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 10; i++) ans = (ans + dp[n][i]) % 10007;
	printf("%d\n", ans);
	return 0;
}
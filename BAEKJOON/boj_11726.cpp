#include <iostream>
#define max(a, b) a < b ? b : a
#define min(a, b) a < b ? a : b

using namespace std;

int n, dp[3][1005];
int dp2[1005];

int main(void) {
	cin >> n;
	dp[1][1] = 1; dp[0][1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[0][i] = dp[0][i - 1] % 10007 + dp[2][i - 1] % 10007;
		dp[1][i] = dp[0][i - 1] % 10007 + dp[2][i - 1] % 10007;
		dp[2][i] = dp[1][i - 1] % 10007;
	}


	printf("%d\n", (dp[0][n] + dp[2][n]) % 10007);

	return 0;
}
#include <iostream>

using namespace std;

int k;
int dp[2][50];

int main(void) {
	cin >> k;
	// 0 A, 1 B
	dp[0][0] = 1; dp[1][0] = 0;
	for (int i = 1; i <= k; i++) {
		dp[0][i] = dp[1][i - 1];
		dp[1][i] = dp[0][i - 1] + dp[1][i - 1];
	}

	printf("%lld %lld\n", dp[0][k] , dp[1][k]);
	return 0;
}
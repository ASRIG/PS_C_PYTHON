#include <iostream>

using namespace std;

int n, k, tmp;
int dp[1001][1001];

int main(void) {
	cin >> n >> k;
	if (n - k < k) k = n - k;

	dp[1][0] = 1; dp[1][1] = 1;
	for (int i = 2; i <= 1000; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) dp[i][j] = 1;
			else {
				dp[i][j] = dp[i - 1][j - 1] % 10007 + dp[i - 1][j] % 10007;
			}
		}
	}
	printf("%d\n", dp[n][k] % 10007);

	return 0;
}
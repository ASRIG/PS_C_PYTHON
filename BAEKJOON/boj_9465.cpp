#include <iostream>
#include <algorithm>
using namespace std;

int t, n, arr[2][100002], dp[2][100002];

int main(void) {
	ios::sync_with_stdio(0); cin.tie(nullptr);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < 2; i++)
			for (int j = 1; j <= n; j++)
				cin >> arr[i][j];

		dp[0][1] = arr[0][1]; dp[1][1] = arr[1][1];
		// DP 설계
		for (int i = 2; i <= n; i++) {
			// 현재를 기준으로 봤을 때, 전의 것을 사용하는지 안하는지 판별
			dp[0][i] = max({ dp[1][i - 2], dp[0][i - 2], dp[1][i - 1] }) + arr[0][i];
			dp[1][i] = max({ dp[1][i - 2], dp[0][i - 2], dp[0][i - 1] }) + arr[1][i];
		}

		printf("%d\n", max(dp[0][n], dp[1][n]));
	}

	return 0;
}
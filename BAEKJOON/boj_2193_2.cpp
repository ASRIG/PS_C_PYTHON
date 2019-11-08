#include <iostream>

using namespace std;

long long dp[2][91], n;

int main(void) {
	cin >> n;
	dp[0][1] = 0; dp[1][1] = 1;
	// ��õ���� ������ �̿��Ͽ� �������� �����Ѵ�.
	for (int i = 2; i <= n; i++) {
		dp[0][i] = dp[1][i - 1] + dp[0][i - 1];
		dp[1][i] = dp[0][i - 1];
	}

	printf("%lld\n", dp[0][n] + dp[1][n]);
	return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[1003][3];
int dp[1005][3];

int main() {
	cin >> n;
	for (int i = 1; i <= n;i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
		// R G B
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
	}
	int result_ = min(min(dp[n][0], dp[n][1]), dp[n][2]);
	printf("%d\n", result_);
	return 0;
}
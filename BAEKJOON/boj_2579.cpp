#include <iostream>
#include <algorithm>
using namespace std;

int dp[3][305], n, arr[305];

int main(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	dp[1][1] = arr[1];
	for (int i = 2; i <= n; i++) {
		dp[1][i] = max(dp[1][i - 2], dp[2][i - 2]) + arr[i];
		dp[2][i] = dp[1][i - 1] + arr[i];
	}

	int answer = max(dp[1][n], dp[2][n]);
	printf("%d\n", answer);

	return 0;
}
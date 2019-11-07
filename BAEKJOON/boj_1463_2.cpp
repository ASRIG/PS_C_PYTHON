#include <iostream>
#include <algorithm>
using namespace std;

int n, dp[1000001];

int main(void) {
	ios::sync_with_stdio(0); cin.tie(nullptr);
	dp[0] = 99999999;
	dp[1] = 0; dp[2] = 1; dp[3] = 1;

	cin >> n;
	for (int i = 4; i <= n; i++) {
		dp[i] = min({ dp[(i % 3 ? 0 : i / 3)], dp[(i & 1 ? 0 : i / 2)], dp[i - 1] }) + 1;
	}

	printf("%d\n", dp[n]);

	return 0;
}
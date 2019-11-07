#include <iostream>
#include <algorithm>
#define INF 100000000
using namespace std;

int n, k, coin_[1001], dp[100011];

int main(void) {
	ios::sync_with_stdio(0); cin.tie(nullptr);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> coin_[i];

	for (int i = 1; i <= k; i++) {
		dp[i] = INF;
	} dp[0] = 0;

	// 코인을 사용할 지 안할지를 결정한다.
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			if (i >= coin_[j]) {
				dp[i] = min(dp[i], dp[i - coin_[j]] + 1);
			}
		}
	}

	int ans = ((dp[k] == INF) ? -1 : dp[k]);
	printf("%d\n", ans);
	return 0;
}
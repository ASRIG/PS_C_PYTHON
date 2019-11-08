#include <iostream>
#define max(a, b) a < b ? b : a
using namespace std;

int n, k, w[101], v[101], dp[100001];

int main(void) {
	ios::sync_with_stdio(0); cin.tie(nullptr);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
	// 기본적인 배낭싸기 알고리즘 (단, 물품이 1개)
	for (int i = 0; i < n; i++) {
		for (int j = k; j >= w[i]; j--) {
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	printf("%d\n", dp[k]);
	return 0;
}
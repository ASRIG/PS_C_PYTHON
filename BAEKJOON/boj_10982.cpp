#include <iostream>
#include <algorithm>

#define INF 1001000
using namespace std;

int t, n, a[1005], b[1005], dp[100100];

int main(void) {
	ios::sync_with_stdio(0); cin.tie(nullptr);
	cin >> t;
	while (t--) {
		cin >> n;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i] >> b[i];	sum += a[i];
		}
		for (int i = 1; i <= sum; i++) dp[i] = INF;
		for (int i = 0; i < n; i++) {
			for (int j = sum; j - a[i] >= 0; j--) {
				dp[j] = min(dp[j], dp[j - a[i]] + b[i]);
			}
		}
		int ans = INF;
		for (int i = sum; i >= 0; i--) {
			ans = min(ans, max(dp[i], sum - i));
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
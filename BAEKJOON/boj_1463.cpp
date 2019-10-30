#include <iostream>
#include <algorithm>

using namespace std;

int n, cnt_ = 0;
int dp[1000005];

int main(void) {
	cin >> n;
	dp[0] = 99999999;
	dp[2] = 1; dp[3] = 1; dp[4] = 2;
	for (int i = 5; i <= n; i++) {
		int tmp1 = 0, tmp2 = 0, tmp3 = i - 1;
		if (i % 3 == 0) tmp1 = i / 3;
		if (i % 2 == 0) tmp2 = i / 2;
		dp[i] = min(min(dp[tmp1], dp[tmp2]), dp[tmp3]) + 1;
	}
	printf("%d\n", dp[n]);
	return 0;
}
#include <iostream>
#include <algorithm>
#include <math.h>
#define INF 99000000
using namespace std;

int n, dp[100002];

int main(void) {
	cin >> n;
	dp[1] = 1; dp[2] = 2; dp[3] = 3;
	for (int i = 4; i <= n; i++) dp[i] = INF;

	for (int i = 1; i <= sqrt(n); i++) {
		for (int j = i * i; j <= n; j++) {
			int tmp = i * i;
			dp[j] = min(dp[j], dp[j - tmp] + 1);
		}
	}

	printf("%d\n", dp[n]);
	return 0;
}
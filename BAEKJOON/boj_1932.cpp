#include <iostream>
#include <algorithm>

using namespace std;

int num[505], dp[505][505];
int n, tmp = 1, result_=0;

int main(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> num[j];
		}
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i - 1][j - 1] + num[j], dp[i - 1][j] + num[j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		result_ = max(result_, dp[n][i]);
	}
	printf("%d\n", result_);
	return 0;
}
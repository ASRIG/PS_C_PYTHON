#include <iostream>
#include <algorithm>

using namespace std;

long answer = 0;
long dp[101][10];
int n;

int main(void) {
	cin >> n; answer = 0;
	int e9 = (int)1e9;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (i == 1) {
				if (j == 0) dp[i][j] = 0;
				else dp[i][j] = 1;
			}
			else {
				if (j == 0) dp[i][j] = dp[i - 1][j + 1];
				else if (j == 9) dp[i][j] = dp[i - 1][j - 1];
				else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % e9;
			}
			if (i == n) {
				answer = (answer + dp[i][j]) % e9;
			}
		}
	}
	printf("%ld\n", answer);
	

	return 0;
}
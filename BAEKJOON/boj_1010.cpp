#include <iostream>
#include <algorithm>

using namespace std;

int T, N, M;
int answer = 0;
int dp[35][35] = { 0, };

int main(void) {
	cin >> T;
	for (int i = 0; i < 30; i++)dp[0][i] = 1;

	for (int i = 1; i < 30; i++) {
		for (int j = 1; j < 30; j++) {
			if (i > j) continue;
			else if (i == j) dp[i][j] = 1;
			else {
				dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
				//printf("%d\n", dp[i][j]);
			}
		}
	}

	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		answer = dp[N][M];
		printf("%d\n", answer);
	}
	
	return 0;
}
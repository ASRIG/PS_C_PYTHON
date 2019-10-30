#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K, cnt = 1;
int dp[16][16], dp2[16][16], map[16][16];

int main(void) {
	cin >> N >> M >> K;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M;j++) {

			map[i][j] = cnt;

			if (cnt == K) {
				dp2[i][j] = 1;
			}
			else {
				dp2[i][j] = dp2[i - 1][j] + dp2[i][j - 1];
			}


			if (i == 1 && j == 1) dp[i][j] = 1;
			else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

			cnt++;
		}
	}

	if (K == 0) printf("%d\n", dp[N][M]);
	else printf("%d\n", dp[(K-1)/M + 1][(K-1) %M + 1] * dp2[N][M]);
	
	return 0;
}
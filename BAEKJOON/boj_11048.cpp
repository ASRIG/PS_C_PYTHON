#include <iostream>
#define INF 9897978
using namespace std;

int N, M, arr[1005][1005], dp[1005][1005];
const int dx[] = { 0, 1, 1 };
const int dy[] = { 1, 0, 1 };

int _max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int main(void) {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (i == 1 && j == 1) dp[i][j] = arr[i][j];
			else dp[i][j] = _max(dp[i - 1][j], _max(dp[i - 1][j - 1], dp[i][j - 1])) + arr[i][j];
		}
	}

	printf("%d\n", dp[N][M]);

	return 0;
}
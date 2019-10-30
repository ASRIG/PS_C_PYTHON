#include <iostream>
#include <algorithm>

#define MAXN 999999
using namespace std;

int i, j, k, answer, N, M;
int a, b;
int arr[501][501];
int output[501];

int main(void) {
	cin >> N >> M;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (i == j) arr[i][j] = 0;
			else arr[i][j] = MAXN;
		}
		output[i] = 0;
	}

	for (i = 1; i <= M; i++) {
		cin >> a >> b;
		arr[a][b] = 1;
	}

	for (k = 1; k <= N; k++) {
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (arr[i][j] < MAXN || arr[j][i] < MAXN) output[i]++;
		}
	}

	answer = 0;
	for (i = 1; i <= N; i++) {
		if (output[i] == N) answer++;
	}

	printf("%d\n", answer);

	return 0;
}
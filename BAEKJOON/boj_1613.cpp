#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int a, b, answer;
int N, K, S, arr[401][401];
const int INF = 1000001;

int main(void) {
	


	scanf("%d%d", &N, &K);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j) arr[i][j] = INF;
		}
	}


	for (int i = 1; i <= K; i++) {
		scanf("%d%d", &a, &b);
		arr[a][b] = 1;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	scanf("%d", &S);
	for (int i = 1; i <= S; i++) {
		scanf("%d%d", &a, &b);
		if (arr[a][b] < INF) printf("-1\n");
		else if (arr[b][a] < INF) printf("1\n");
		else printf("0\n");
	}

	return 0;
}
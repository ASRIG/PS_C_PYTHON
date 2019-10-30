#include <iostream>

using namespace std;

int N, M, A[101], B[101][101], C[101];

int main(void) {
	cin >> N; cin >> M;
	for (int i = 1; i <= M; i++) cin >> A[i];
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> B[i][j];  // 게임 사람
		}
	}

	for (int i = 1; i <= M; i++) {
		int target_ = A[i], cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (B[i][j] == target_) cnt++, C[j]++;
		}
		C[A[i]] += N - cnt;
		//printf("A[i] : %d, C[A[i]] : %d\n", A[i], C[A[i]]);
	}

	for (int i = 1; i <= N; i++) printf("%d\n", C[i]);

	
	
	return 0;
}
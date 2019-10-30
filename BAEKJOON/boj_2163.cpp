#include <iostream>

using namespace std;

int N, M, answer = 0;

int main(void) {
	cin >> N >> M;
	if (M > N) {
		int tmp = N; N = M; M = tmp;
	}
	answer += M - 1;
	answer += (N - 1) * M;

	printf("%d\n", answer);
	return 0;
}
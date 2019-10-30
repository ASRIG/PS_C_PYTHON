#include <iostream>

using namespace std;

int T, N, M;

int main(void) {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N >> M;
		int answer = M * 2 - N;
		printf("%d %d\n", answer, M - answer);
	}
	return 0;
}
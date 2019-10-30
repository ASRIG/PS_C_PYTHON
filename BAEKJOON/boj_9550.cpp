#include <iostream>

using namespace std;

int T, N, K, candy;

int main(void) {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N >> K;
		int answer = 0;
		for (int j = 0; j < N; j++) {
			cin >> candy;
			answer += candy / K;
		}
		printf("%d\n", answer);
	}

	return 0;
}
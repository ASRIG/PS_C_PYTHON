#include <iostream>

using namespace std;

int N, a[500001];
long long answer;

int main(void) {
	cin >> N;
	for (int i = 0; i < N;i++) cin >> a[i];
	for (int i = 0; i < N; i++) {
		if (i != N - 1)answer += a[i] - 1;
		else answer += a[i];
	}
	printf("%lld\n", answer);
	return 0;
}
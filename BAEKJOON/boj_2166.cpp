#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N, a, b;
int x[10005], y[10005];

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i];
	}

	int tmp_a = 0, tmp_b = 0;
	for (int i = 0; i < N; i++) {
		int j = i % N + 1;
		tmp_a += x[i] * y[j];
		tmp_b += x[j] * y[i];
	}

	long long answer = abs((tmp_a - tmp_b));
	printf("%lld.%d\n", answer / 2, answer % 2 == 0 ? 0 : 5);
	return 0;
}

#include <iostream>

using namespace std;

int n, answer = 0;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int tmp = i, tmp_sum = i;
		while (tmp != 0) {
			tmp_sum += tmp % 10;
			tmp /= 10;
		}
		if (tmp_sum == n) { answer = i; break; }
	}
	printf("%d\n", answer);
	return 0;
}
#include <iostream>
#define max(a, b) a < b ? b : a

using namespace std;

int n, answer, a, dp;

int main(void) {
	ios::sync_with_stdio(0); cin.tie(nullptr);
	cin >> n;
	cin >> a;
	dp = a; answer = a;
	for (int i = 2; i <= n;i++) {
		cin >> a;
		dp = max(dp + a, a);
		answer = max(answer, dp);
	}

	printf("%d\n", answer);
	return 0;
}
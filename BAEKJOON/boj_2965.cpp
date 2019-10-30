#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int dp[2][105], k[3];

int main(void) {
	for (int i = 0; i < 3; i++) {
		cin >> k[i];
	}
	sort(k, k + 3);
	int len_1 = abs(k[0] - k[1]) - 1, len_2 = abs(k[2] - k[1]) - 1;
	int ans = max(len_1, len_2);
	printf("%d\n", ans);

	return 0;
}
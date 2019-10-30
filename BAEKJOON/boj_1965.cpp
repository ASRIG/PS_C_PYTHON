#include <iostream>
#include <algorithm>

using namespace std;

int dp[1005], n, tmp;

int main(void) {
	int answer = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		if (i == 1) dp[i] = tmp;
		if (tmp > dp[answer]) dp[++answer] = tmp;
		else if (tmp < dp[answer]) {
			int cur = 1;
			while (cur <= answer) {
				if (dp[cur] >= tmp) {
					dp[cur] = tmp; break;
				}cur++;
			}
		}
	}

	printf("%d\n", answer);

	return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

int n, p[1002], dp[1002];

int main(void) {
	ios::sync_with_stdio(0); cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> p[i];
	
	// �ش��ϴ� ī�带 ��°� �̵����� dp�� �Ǻ�
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			dp[j] = max(dp[j], dp[j - i] + p[i]);
		}
	}

	printf("%d\n", dp[n]);

	return 0;
}

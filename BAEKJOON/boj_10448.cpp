#include <iostream>

using namespace std;

bool dp[1001];
int tes, t[50], tmp;


void dfs(int idx, int cnt, int sum) {
	if (cnt == 3) {
		if (sum > 1000) return;
		dp[sum] = true;
		return;
	}
	
	for (int i = idx; i < 50; i++) {
		dfs(i, cnt + 1, sum + t[i]);
	}
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(nullptr);
	t[1] = 1;
	for (int i = 2; i < 50; i++) t[i] = t[i - 1] + i;
	for (int i = 0; i <= 1000; i++) dp[i] = false;
	dfs(1, 0, 0);

	cin >> tes;
	for (int i = 0; i < tes; i++) {
		cin >> tmp;
		printf("%d\n", dp[tmp]);
	}
	return 0;
}
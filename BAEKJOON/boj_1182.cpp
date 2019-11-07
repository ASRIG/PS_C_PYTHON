#include <iostream>

using namespace std;

int n, s, arr[21], pick[21], answer = 0;

void dfs(int idx, int sum) {
	// 부분집합들의 합을 판별하여 값을 구함.
	if (sum == s) answer++;
	if (idx == n) return;

	for (int i = idx; i < n; i++) {
		pick[i] = 1;
		dfs(i + 1, sum + arr[i]);
		pick[i] = 0;
	}
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(nullptr);
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> arr[i];
	dfs(0, 0);
	if (s == 0) answer--;
	printf("%d\n", answer);
	return 0;
}
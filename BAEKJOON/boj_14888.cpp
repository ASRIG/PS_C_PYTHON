#include <iostream>
#define max(a, b) a < b ? b : a
#define min(a, b) a < b ? a : b
using namespace std;

int n, a[15], b[4], answer_max = -0x7fffffff, answer_min = 0x7fffffff;

void dfs(int cnt, int ret) {
	if (cnt == n - 1) {
		answer_max = max(answer_max, ret);
		answer_min = min(answer_min, ret);
		return;
	}
	// + - x /
	if (b[0] != 0) {
		b[0] -= 1;
		dfs(cnt + 1, ret + a[cnt + 1]);
		b[0] += 1;
	}
	if (b[1] != 0) {
		b[1] -= 1;
		dfs(cnt + 1, ret - a[cnt + 1]);
		b[1] += 1;
	}
	if (b[2] != 0) {
		b[2] -= 1;
		dfs(cnt + 1, ret * a[cnt + 1]);
		b[2] += 1;
	}
	if (b[3] != 0) {
		b[3] -= 1;
		dfs(cnt + 1, ret / a[cnt + 1]);
		b[3] += 1;
	}
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < 4; i++)cin >> b[i];

	dfs(0, a[0]);
	printf("%d\n%d\n", answer_max, answer_min);
	return 0;
}
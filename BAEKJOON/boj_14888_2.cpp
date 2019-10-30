#include <iostream>
#define max(a, b) a < b ? b : a
#define min(a, b) a < b ? a : b
using namespace std;

int n, a[12], answer_min = 0x7fffffff, answer_max = -0x7fffffff;
int cal[4];

void dfs(int cnt, int res) {
	if (cnt == n - 1) {
		answer_min = min(answer_min, res);
		answer_max = max(answer_max, res);
		return;
	}

	if(cal[0] > 0){
		cal[0] -= 1;
		dfs(cnt + 1, res + a[cnt + 1]);
		cal[0] += 1;
	}
	if (cal[1] > 0) {
		cal[1] -= 1;
		dfs(cnt + 1, res - a[cnt + 1]);
		cal[1] += 1;
	}
	if (cal[2] > 0) {
		cal[2] -= 1;
		dfs(cnt + 1, res * a[cnt + 1]);
		cal[2] += 1;
	}
	if (cal[3] > 0) {
		cal[3] -= 1;
		dfs(cnt + 1, res / a[cnt + 1]);
		cal[3] += 1;
	}
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> cal[i];
	}

	dfs(0, a[0]);

	printf("%d\n", answer_max);
	printf("%d\n", answer_min);
	return 0;
}
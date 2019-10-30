#include <iostream>
#define min(a, b) a < b ? a : b
using namespace std;

int n, s[22][22], n_2;
int pick_[22], answer = 0x7fffffff;

int abs(int aa) {
	if (aa < 0) return aa * -1;
	else return aa;
}

int calculate() {
	int ret1 = 0, ret2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (pick_[i] == 1 && pick_[j] == 1) ret1 += s[i][j];
			else if (pick_[i] == 0 && pick_[j] == 0) ret2 += s[i][j];
		}
	}
	int ret = abs(ret1 - ret2);
	return ret;
}

void dfs(int idx, int cnt) {
	if (cnt == n_2) {
		int tmp = calculate();
		answer = min(answer, tmp);
		return;
	}
	for (int i = idx; i < n; i++) {
		pick_[i] = 1;
		dfs(i + 1, cnt + 1);
		pick_[i] = 0;
	}
}

int main(void) {
	cin >> n;
	n_2 = n / 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}

	dfs(0, 0);
	printf("%d\n", answer);

	return 0;
}
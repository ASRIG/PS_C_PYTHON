#include <iostream>
#define min(a, b) a < b ? a : b
using namespace std;

int n, m, h, a, b, answer = 4;
int arr[305][15];

int check() {
	int ret = 1, cur_ = 0;
	for (int j = 0; j < n; j++) {
		cur_ = j;
		for (int i = 0; i < h; i++) {
			if (arr[i][cur_] == 1) {
				cur_ += 1;
			}
			else if (cur_ > 0 && arr[i][cur_ - 1] == 1) {
				cur_ -= 1;
			}
		}
		if (j != cur_) {
			ret = 0; break;
		}
	}
	return ret;
}

void print() {
	printf("\n[테스트용]\n");
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", arr[i][j]);
		}printf("\n");
	}
}

void dfs(int idx, int idy, int cnt) {
	if (cnt <= answer) {
		// Check
		
		//print();
		int tmp = check();
		if (tmp == 1) answer = min(answer, cnt);
	}
	if (cnt == 3) {
		return;
	}
	for (int i = idx; i < h; i++) {
		for (int j = idy; j < n - 1; j++) {
			if (arr[i][j] == 1) continue;
			if (j > 0 && arr[i][j - 1] == 1) continue;
			if (j < m - 1 && arr[i][j + 1] == 1) continue;
			arr[i][j] = 1;
			dfs(i, j + 1, cnt + 1);
			arr[i][j] = 0;
		}
		idy = 0;
	}
}

int main(void) {
	cin >> n >> m >> h;
	for (int i = 0; i < m;i++) {
		cin >> a >> b; a -= 1; b -= 1;
		arr[a][b] = 1;
	}

	dfs(0, 0, 0);
	if (answer == 4) answer = -1;
	printf("%d\n", answer);

	return 0;
}
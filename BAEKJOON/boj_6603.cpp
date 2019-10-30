#include <iostream>

using namespace std;

int k, a[14], b[14];

void dfs(int idx_, int cnt_) {
	if (cnt_ == 6) {
		for (int i = 0; i < k; i++) {
			if (b[i] == 1) printf("%d ", a[i]);
		}printf("\n");
	}
	for (int i = idx_; i < k; i++) {
		b[i] = 1;
		dfs(i + 1, cnt_ + 1);
		b[i] = 0;
	}
}

int main(void) {
	while (1) {
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; i++) cin >> a[i];
		dfs(0, 0);
		printf("\n");
		fill(b, b + k, 0);
	}

	return 0;
}
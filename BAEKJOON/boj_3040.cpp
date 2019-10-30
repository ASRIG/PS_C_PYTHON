#include <iostream>

using namespace std;

int a[10], b[10];

void dfs(int idx_, int cnt_, int sum) {
	if (sum > 100) return;
	if(cnt_ == 7){
		if (sum == 100) {
			for (int i = 0; i < 9; i++) {
				if (b[i] == 1) printf("%d\n", a[i]);
			}
		}
		return;
	}
	for (int i = idx_; i < 9; i++) {
		b[i] = 1;
		dfs(i + 1, cnt_ + 1, sum + a[i]);
		b[i] = 0;
	}
}
int main(void) {
	for (int i = 0; i < 9; i++) {
		cin >> a[i];
	}
	dfs(0, 0, 0);

	return 0;
}
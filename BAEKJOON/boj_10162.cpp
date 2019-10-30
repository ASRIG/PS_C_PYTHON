#include <iostream>

using namespace std;

int t;
const int timer_[] = { 300, 60, 10 };

int main(void) {
	cin >> t;
	int ans[3] = { 0, 0, 0 };
	for (int i = 0; i < 3; i++) {
		ans[i] += t / timer_[i];
		t %= timer_[i];
	}
	if (t == 0) printf("%d %d %d\n", ans[0], ans[1], ans[2]);
	else printf("-1\n");
	return 0;
}
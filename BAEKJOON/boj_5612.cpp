#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a, b, cnt, max_ = 0;

int main(void) {
	scanf("%d%d", &n, &m); cnt = m;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		cnt += a; cnt -= b;
		max_ = max(cnt, max_);
		if (cnt < 0) {
			max_ = 0; break;
		}
	}

	printf("%d\n", max_);

	return 0;
}
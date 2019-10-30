#include <iostream>

using namespace std;

int n, m, a[1001], b[1001], c[1001];

int main(void) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++)cin >> b[i];

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (b[i] >= a[j]) {
				c[j]++; break;
			}
		}
	}

	int tmp_max = 0, tmp_index = 0;
	for (int i = 1; i <= n; i++) {
		if (tmp_max < c[i]) tmp_max = c[i], tmp_index = i;
	}
	printf("%d\n", tmp_index);
	return 0;
}
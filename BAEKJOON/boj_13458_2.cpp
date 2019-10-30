#include <iostream>

using namespace std;

long long ans = 0;
int n, a[1000001], b, c;

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> b >> c;
	for (int i = 0; i < n; i++) {
		ans += 1; a[i] -= b;
		if (a[i] <= 0) continue;
		ans += (a[i] / c);
		a[i] %= c;
		if (a[i] > 0) ans += 1;
	}
	printf("%lld\n", ans);
	return 0;
}
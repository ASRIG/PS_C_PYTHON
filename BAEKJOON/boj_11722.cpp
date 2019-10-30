#include <iostream>
#include <algorithm>

using namespace std;

int n, cnt, tmp, s, e, m;
int a[1005];

int main(void) {
	cin >> n;
	a[0] = 1005; cnt = 1;

	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		if (i == 1) {
			a[i] = tmp;
		}
		else {
			if (a[cnt] > tmp) {
				a[++cnt] = tmp;
			}
			else {
				s = 1; e = cnt;
				while (e - s >= 0) {
					m = (s + e) / 2;
					if (tmp >= a[m] && tmp < a[m - 1]) {
						a[m] = tmp; break;
					}
					else if (a[m] < tmp) e = m - 1;
					else s = m + 1;
				}
			}
		}
	}

	printf("%d\n", cnt);

	return 0;
}
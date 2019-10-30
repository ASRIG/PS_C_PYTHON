#include <iostream>
#include <algorithm>
#include <queue>
#define MAXN 100000
using namespace std;

int n, k, a[100005];

int main(void) {
	cin >> n >> k;
	int cur = n;
	for (int i = 0; i <= 100000; i++) {
		a[i] = 9999999;
	}
	queue<int> q;
	q.push(n);
	a[n] = 0;

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		
		if (cur + 1 <= MAXN && a[cur + 1] > a[cur] + 1) {
			a[cur + 1] = a[cur] + 1;
			q.push(cur + 1);
		}

		if (cur - 1 >= 0 && a[cur - 1] > a[cur] + 1) {
			a[cur - 1] = a[cur] + 1;
			q.push(cur - 1);
		}

		if (2 * cur <= MAXN && a[2 * cur] > a[cur] + 1) {
			a[2 * cur] = a[cur] + 1;
			q.push(2 * cur);
		}
	}

	printf("%d\n", a[k]);

	return 0;
}
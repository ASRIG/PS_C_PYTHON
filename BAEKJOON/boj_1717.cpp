#include <iostream>
#include <algorithm>

using namespace std;

int N, M, i, answer, x, y;
int q, a, b;
int d1, d2;
int p[1000001];

int find(int n) {
	if (p[n] < 0) return n;
	p[n] = find(p[n]);
	return p[n];
}

void merge(int a, int b) {
	x = find(a);
	y = find(b);
	if (x == y) return;
	p[y] = x;
}

int main(void) {
	cin >> N >> M;
	for (i = 0; i <= N; i++) {
		p[i] = -1;
	}
	for (i = 1; i <= M; i++) {
		cin >> q >> a >> b;
		if (q == 0) merge(a, b);
		else {
			d1 = find(a);
			d2 = find(b);
			if (d1 == d2) printf("YES");
			else printf("NO");
			printf("\n");
		}
	}
	return 0;
}
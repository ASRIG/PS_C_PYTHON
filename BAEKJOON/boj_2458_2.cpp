#include <iostream>

using namespace std;

int n, m, a, b, c, p[1000001];

int find(int a) {
	if (p[a] < 0) return a;
	p[a] = find(p[a]);
	return p[a];
}

void merge(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return;
	p[b] = a;
}


int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++) p[i] = -1;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &c, &a, &b);
		if (c == 0) {
			// 합집합
			merge(a, b);
		}
		else {
			// 공통 부모 찾기
			int d1 = find(a), d2 = find(b);
			if (d1 == d2) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
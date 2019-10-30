#include <iostream>

using namespace std;

int n, m, a, b, c, p[1000005];

int find(int num) {
	if (p[num] < 0) return num;
	p[num] = find(p[num]);
	return p[num];
}

void merge(int aa, int bb) {
	int x = find(aa);
	int y = find(bb);

	if (x == y) return;
	p[y] = x;
}

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++)p[i] = -1;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &c, &a, &b);
		if (c == 0) {
			// 자식 생성
			merge(a, b);
		}
		else {
			// 자식 찾아서 확인
			int x = find(a);
			int y = find(b);
			if (x == y) printf("YES\n");
			else printf("NO\n");
		}
	}

	return 0;
}
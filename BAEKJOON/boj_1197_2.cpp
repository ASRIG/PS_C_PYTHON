#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define mp make_pair


int v, e, a, b, c, p[10005];
long long answer = 0;
vector < pair<int, pair<int, int>>> vec;

int find(int num) {
	if (p[num] < 0) return num;
	p[num] = find(p[num]);
	return p[num];
}

void merge(int aa, int bb) {
	int x = find(aa), y = find(bb);
	if (x == y) return;
	p[y] = x;
}

int main(void) {
	scanf("%d %d", &v, &e);
	for (int i = 0; i <= v; i++)p[i] = -1;
	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &a, &b, &c);
		vec.push_back(mp(c, mp(a, b)));
	}
	sort(vec.begin(), vec.end());

	for (int i = 0; i < e; i++) {
		int x = find(vec[i].second.first), y = find(vec[i].second.second);
		if (x == y) continue;
		else {
			merge(x, y);
			answer += vec[i].first;
		}
	}

	printf("%lld\n", answer);

	return 0;
}
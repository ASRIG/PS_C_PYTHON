#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n, m;
vector<int> vc;
bool visit[10];

void dfs() {
	if (vc.size() == m) {
		for (auto i : vc)
			printf("%d ", i);
		printf("\n");
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			vc.push_back(i);
			dfs();
			vc.pop_back();
			visit[i] = false;
		}
	}
}

int main(void) {
	cin >> n >> m;
	dfs();
	return 0;
}
/*
	LCA 알고르즘 (Lowest Common Ancestor)
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define MAXN 50005
#define sz(v) ((int)(v).size())

int T, N, Q, M;
int par[17][MAXN], dep[MAXN], visit[MAXN];
int x, y;
long answer;
vector <int> con[MAXN];

int lca(int a, int b) {
	if (dep[a] < dep[b]) swap(a, b);
	int diff = dep[a] - dep[b];
	int cnt = 0;
	while (0 < diff) {
		if (diff % 2 == 1) a = par[cnt][a];
		diff /= 2; cnt++;
	}

	if (a == b) return a;
	for (int i = 16; i >= 0; i--) {	// 가장 루트에 가까운 것부터 비교
		if (par[i][a] != par[i][b]) {
			a = par[i][a]; b = par[i][b];
		}
	}
	return par[0][a];
}

int main(void) {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		con[i].clear(); visit[i] = 0;
	}
	for (int i = 2; i <= N; i++) {
		scanf("%d %d", &x, &y);
		con[x].push_back(y); con[y].push_back(x);
	}

	queue<int> que;
	que.push(1); // 루트 번호 셋팅, 루트의 깊이는 0이므로 별도 계산하지않고 패스

	while (!que.empty()) {
		int q = que.front(); que.pop();
		visit[q] = 1;
		for (int i = sz(con[q]); i--;) {
			int t = con[q][i];
			if (visit[t] == 0) {
				dep[t] = dep[q] + 1; que.push(t);
				par[0][t] = q;
			}
		}
	}

	for (int i = 1; i < 17; i++) {
		for (int j = 1; j <= N; j++) {
			par[i][j] = par[i - 1][par[i - 1][j]];
		}
	}

	scanf("%d", &M);

	for (int i = 1; i <= M; i++) {
		scanf("%d %d", &x, &y);
		int temp = lca(x, y);
		printf("%d\n", temp);
	}

	return 0;
}
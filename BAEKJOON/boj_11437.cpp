#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAXN 50005
#define pb push_back
#define sz(v) ((int)(v).size())

// 모르겠수요...

int T, N, Q, M;
int par[17][MAXN], dep[MAXN], visit[MAXN];
int x, y;
long answer;
vector<int> con[MAXN];

int lca(int a, int b) {
	if (dep[a] < dep[b]) swap(a, b);
	int diff = dep[a] - dep[b];
	int cnt = 0;
	while (0 < diff) {
		if (diff % 2 == 1) a = par[cnt][a];
		diff /= 2; cnt++;
	}
	if (a == b) return a;
	for (int i = 16; i >= 0; i--) {
		if (par[i][a] != par[i][b]) {
			a = par[i][a];
			b = par[i][b];
		}
	}
	return par[0][a];
}

int main(void) {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		con[i].clear(); visit[i] = 0;
	}
	for (int i = 2; i <= N; i++) {
		cin >> x >> y;
		con[x].pb(y); con[y].pb(x);
	}

	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int qa = q.front(); q.pop();
		visit[qa] = 1;
		for (int i = sz(con[qa]); i--;) {
			int t = con[qa][i];
			if (visit[t] == 0) {
				dep[t] = dep[qa] + 1; q.push(t);
				par[0][t] = qa;
			}
		}
	}

	for (int i = 1; i < 17; i++)
		for (int j = 1; j <= N; j++)
			par[i][j] = par[i - 1][par[i - 1][j]];

	cin >> M;

	for (int i = 1; i <= M; i++) {
		cin >> x >> y;
		int temp = lca(x, y);
		printf("%d\n", temp);
	}


	return 0;
}
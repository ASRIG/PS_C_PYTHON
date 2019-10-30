#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define mp make_pair
#define MAXN 32005
using namespace std;

int n, m, a, b;
vector <int> con[MAXN];
int cnt_[MAXN], d[MAXN];

int main(void) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		con[i].clear(); cnt_[i] = 0;
	}

	for (int i = 1; i <= m; i++) {
		cin >> a >> b;	//a가 b앞에 서야한다.
		con[a].push_back(b); cnt_[b]++;
	}

	for (int i = 1; i <= n; i++) d[i] = 0;
	vector<int> order;
	queue<int> que;
	for (int i = 1; i <= n; i++) {
		if (cnt_[i] == 0) que.push(i);
	}

	while (!que.empty()) {
		int q = que.front(); que.pop();
		order.push_back(q);	// 뽑은거 쌓음
		for (int i = 0; i<con[q].size(); i++) {
			int k = con[q][i]; cnt_[k]--;
			if (cnt_[k] == 0) que.push(k);
		}
	}

	for (int i = 0; i < n; i++) {
		int n = order[i];
		printf("%d", n);
		if (i < n - 1) printf(" ");
		else printf("\n");
	}

	return 0;
}
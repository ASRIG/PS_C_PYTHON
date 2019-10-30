#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define MAXN 1005
#define sz(v) ((int)(v).size())

int N, M, ans, pd;
int D[MAXN], in_[MAXN], input_[MAXN];
vector<int> con[MAXN];

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		con[i].clear();
	}

	for (int i = 1; i <= M; i++) {
		cin >> pd;
		for (int j = 1; j <= pd; j++) {
			cin >> input_[j];

			if (j > 1) {
				con[input_[j - 1]].push_back(input_[j]);
				in_[input_[j]]++;
			}
		}
	}

	vector<int> order;
	queue<int> que;
	for (int i = 1; i <= N; i++) {
		if (in_[i] == 0) {
			que.push(i);
		}
	}

	while (!que.empty()) {
		int q = que.front(); que.pop();
		order.push_back(q);
		for (int i = sz(con[q]); i--;) {
			int k = con[q][i];
			in_[k]--;
			if (in_[k] == 0) que.push(k);
		}
	}

	if (order.size() == N) {
		for (int i = 0; i < N; i++) {
			printf("%d\n", order[i]);
		}
	}
	else {
		printf("0\n");
	}

	return 0;
}
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N, M, a, b;
vector<int> con[32005];
int inn[32005];
priority_queue<int> pq;

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		con[a].push_back(b);
		inn[b]++;
		// a를 b보다 먼저 풀어야한다.
	}
	
	vector<int> order;
	for (int i = 1; i <= N; i++) {
		if (inn[i] == 0) pq.push(-i);
	}

	while (!pq.empty()) {
		int cur_x = -pq.top(); pq.pop();
		order.push_back(cur_x);

		int count_ = 0, index_ = 0;
		for (int i = 0; i < con[cur_x].size(); i++) {
			int k = con[cur_x][i];
			inn[k]--;
			if (inn[k] == 0) pq.push(-k);
		}
	}

	for (int i = 0; i < N; i++) {
		printf("%d ", order[i]);
	}
	printf("\n");

	return 0;
}
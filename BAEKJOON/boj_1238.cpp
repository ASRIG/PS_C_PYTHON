#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define mp make_pair
using namespace std;

int N, M, X, a, b, c, answer = 0;
int go_[1005], back_[1005];
vector<int> con[1005], conv[1005];
queue<pair<int, int>> q;
priority_queue<pair<int, pair<int, int>>> pq;

int main(void) {
	pq.push(mp(0, mp(0, 0)));
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		con[a].push_back(b); conv[a].push_back(c);
	}
	for (int i = 1; i <= N; i++) {
		go_[i] = 0x7fffffff; back_[i] = 0x7fffffff;
	}

	// 파티장에 가기
	for (int i = 1; i <= N; i++) {
		if (i == X) {
			go_[i] = 0; continue;
		}
		q.push(mp(i, 0));
		while (!q.empty()) {
			int cur_a = q.front().first, cur_d = q.front().second;
			//printf("cur_a : %d, d : %d, go_i : %d \n", cur_a, cur_d, go_[i]);
			q.pop();
			if (go_[i] <= cur_d) continue;
			for (int j = 0; j < con[cur_a].size(); j++) {
				if (con[cur_a][j] == X) {
					if(go_[i] > cur_d + conv[cur_a][j]) go_[i] = cur_d + conv[cur_a][j]; 
					continue;
				}
				q.push(mp(con[cur_a][j], cur_d + conv[cur_a][j]));
			}
		}
	}

	// 파티장에서 돌아오기
	q.push(mp(X, 0)); 
	while (!q.empty()) {
		int cur_a = q.front().first, cur_d = q.front().second;
		q.pop();
		if (back_[cur_a] <= cur_d - 1) continue;
		for (int j = 0; j < con[cur_a].size(); j++) {
			if (back_[con[cur_a][j]] > cur_d + conv[cur_a][j]) {
				back_[con[cur_a][j]] = cur_d + conv[cur_a][j];
			}
			q.push(mp(con[cur_a][j], cur_d + conv[cur_a][j]));
		}
	}
	back_[X] = 0;

	for (int i = 1; i <= N; i++) {
		int temp = go_[i] + back_[i];
		if (temp > answer) answer = temp;
	}

	printf("%d\n", answer);


	return 0;
}
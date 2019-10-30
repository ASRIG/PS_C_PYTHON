#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define mp make_pair
using namespace std;

int v, e, k, a, b, c;
vector<int> con[20001], conv[20001];
queue<pair<int, int>> q;

int main(void) {
	cin >> v >> e;
	cin >> k;
	for (int i = 0; i < e;i++) {
		cin >> a >> b >> c;
		con[a].push_back(b); conv[a].push_back(c);
	}

	for (int i = 1; i <= v; i++) {
		bool true_sw = false;
		q.push(mp(k, 0));
		while (!q.empty()) {
			int cur_a = q.front().first, cur_b = q.front().second;
			q.pop();
			if (cur_a == i) {
				true_sw = true;
				printf("%d\n", cur_b); break;
			}
			for (int j = 0; j < con[cur_a].size(); j++) {
				int new_a = con[cur_a][j], new_b = conv[cur_a][j] + cur_b;
				q.push(mp(new_a, new_b));
			}
		}
		while (!q.empty()) q.pop();
		if (true_sw == false) printf("INF\n");
	}

	return 0;
}
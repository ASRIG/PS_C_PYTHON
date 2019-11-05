#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, a, b, c, aa, bb;
int d[1005];
vector<int> con[1005], conv[1005];

int main(void) {
	ios::sync_with_stdio(0); cin.tie(nullptr);
	cin >> n; cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c; a -= 1; b -= 1;
		con[a].push_back(b); conv[a].push_back(c);
	}
	cin >> aa >> bb; aa -= 1; bb -= 1;
	for (int i = 0; i < n; i++) d[i] = 0x7fffffff;
	
	priority_queue<pair<int, int>> q;
	q.push(make_pair(0, aa)); d[aa] = 0;

	while (!q.empty()) {
		int cur_d = -q.top().first, cur = q.top().second; q.pop();
		if (cur_d != d[cur]) continue;
		for (int i = 0; i < (int)con[cur].size(); i++) {
			int t = con[cur][i], k = conv[cur][i];
			if (d[t] > cur_d + k) {
				d[t] = cur_d + k; q.push(make_pair(-d[t], t));
			}
		}
	}
	printf("%d\n", d[bb]);
	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define mp make_pair
using namespace std;

int n, m;
long a, b, c, aa, bb;
long long answer = 0x7fffffff;
long long D[1005];
vector<long> con[1005], conv[1005];
priority_queue<pair<long, long>> q;

int main(void) {
	cin >> n; cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		con[a].push_back(b); conv[a].push_back(c);
	}

	for (int i = 0; i <= n; i++) {
		D[i] = 2e9;
	}

	cin >> aa >> bb;
	D[aa] = 0;
	q.push(mp(0, aa));

	while (!q.empty()) {
		long qq = q.top().second, dd = -q.top().first;
		q.pop();
		if (D[qq] != dd) continue;
		for (int i = 0; i < con[qq].size(); i++) {
			long t = con[qq][i], v = conv[qq][i];
			if (D[t] > D[qq] + v) {
				D[t] = D[qq] + v, q.push(mp(-D[t], t));
			}
		}
	}
	printf("%lld\n", D[bb]);
	return 0;
}
#include <iostream>
#include <queue>
#include <cmath>
#include <vector>

using namespace std;

#define MAXN 805
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;

int n, e, a, b, c, answer;
vector<int> con[805], conv[805];
int D[MAXN], D1[MAXN], D2[MAXN];

int main(void) {
	cin >> n >> e;
	for (int i = 1; i <= n; i++) {
		con[i].clear(); conv[i].clear();
		D[i] = 200010000;
		D2[i] = 200010000;
		D1[i] = 200010000;
	}
	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &a, &b, &c);
		con[a].push_back(b); conv[a].push_back(c);
		con[b].push_back(a); conv[b].push_back(c);
	}
	
	priority_queue<pii> que;
	D[1] = 0;
	que.push(mp(0, 1));

	while (!que.empty()) {
		int q = que.top().second, d = -que.top().first;
		que.pop();
		if (D[q] != d) continue;
		for (int i = 0; i < con[q].size(); i++) {
			int t = con[q][i], v = conv[q][i];
			if (D[t] > D[q] + v) {
				D[t] = D[q] + v, que.push(mp(-D[t], t));
			}
		}
	}

	cin >> a >> b;

	priority_queue<pii> que1;
	D1[a] = 0;
	que1.push(mp(0, a));

	while (!que1.empty()) {
		int q = que1.top().second, d = -que1.top().first;
		que1.pop();
		if (D1[q] != d) continue;
		for (int i = 0; i < con[q].size(); i++) {
			int t = con[q][i], v = conv[q][i];
			if (D1[t] > D1[q] + v) {
				D1[t] = D1[q] + v, que1.push(mp(-D1[t], t));
			}
		}
	}


	priority_queue<pii> que2;
	D2[a] = 0;
	que2.push(mp(0, b));

	while (!que2.empty()) {
		int q = que2.top().second, d = -que2.top().first;
		que2.pop();
		if (D2[q] != d) continue;
		for (int i = 0; i < con[q].size(); i++) {
			int t = con[q][i], v = conv[q][i];
			if (D2[t] > D2[q] + v) {
				D2[t] = D2[q] + v, que2.push(mp(-D2[t], t));
			}
		}
	}

	answer = min(D[a] + D1[b] + D2[n], D[b] + D2[a] + D1[n]);
	if (answer >= 200010000) answer = -1;
	printf("%d\n", answer);
	return 0;
}
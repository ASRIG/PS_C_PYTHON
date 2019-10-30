#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, a, b;
vector<int> v[105];
int virus_[105];

int main(void) {
	cin >> n;  cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b); v[b].push_back(a);
	}
	int answer = 0;
	queue<int> q;
	q.push(1); virus_[1] = 1;

	while (!q.empty()) {
		int cur_q = q.front(); q.pop();
		for (int i = 0; i < v[cur_q].size(); i++) {
			if (virus_[v[cur_q][i]] == 0) {
				//printf("v[cur_q][i] : %d\n", v[cur_q][i]);
				virus_[v[cur_q][i]] = 1; q.push(v[cur_q][i]); answer++;
			}
		}
	}
	printf("%d\n", answer);
	
	return 0;
}
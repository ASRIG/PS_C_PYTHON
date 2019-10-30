#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, tmp, root_, c;
vector<int> v[55];
queue<int> q;

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp == -1) root_ = i;
		else {
			v[tmp].push_back(i);
		}
	}

	cin >> c;
	if (c != root_) {
		q.push(root_);
	}
	
	int answer = 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		int cnt = 0;
		for (int j = 0; j < (int)v[cur].size();j++) {
			if (v[cur][j] == c) continue;
			cnt++;
			q.push(v[cur][j]);
		}
		if (cnt == 0) answer++;
	}
	
	printf("%d\n", answer);

}
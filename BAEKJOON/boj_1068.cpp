#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, tmp, E, answer;
int arr[55];
vector<int> con[55];
queue<int> q;

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		con[i].clear();
		cin >> arr[i];
	}
	cin >> E;
	
	for (int i = 0; i < N; i++) {
		if (arr[i] >= 0) {
			if (i != E && arr[i] != E) {	// 끊을 애면 아무것도 안함
				con[arr[i]].push_back(i);	// 자식표시
			}
		}
		else q.push(i);
	}

	while (!q.empty()) {
		int qq = q.front(); q.pop();
		for (int i = size(con[qq]); i--;) {
			int t = con[qq][i];
			if (t != E) q.push(t);
		}
		if (sizeof(con[qq]) == 0 && arr[qq] >= 0) {
			answer++;
		}
	}

	printf("%d\n", answer);
	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 201

// A와 B의 정점의 개수
int n, m;
// adj[i][j] = Ai와 Bj가 연결이 되었는가?
bool adj[MAX_N][MAX_N];
// 각 정점에 매칭된 상대 정점의 번호를 지정한다.
vector<int> aMatch, bMatch;
// dfs()의 방문 여부
vector<bool> visited;

// A의 정점인 a에서 B의 매칭되지 않은 정점으로 가는 경로를 찾기.
bool dfs(int a) {
	if (visited[a]) return false;
	visited[a] = true;
	for (int b = 0; b < m; b++) {
		if (adj[a][b]) {
			// b가 매칭되어 있지 않다면 bMatch[b]에서부터 시작해 증가 경로를 찾는다.
			// 매칭되어 있다면 dfs에서 매칭되어 있는 A정점이 다른 곳을 매칭 할 수 있는지 확인한다.
			if (bMatch[b] == -1 || dfs(bMatch[b])) {
				// 증가 경로를 발견하였을 때, a와 b를 연결한다.
				aMatch[a] = b; bMatch[b] = a;
				return true;
			}
		}
	}
	return false;
}

// aMatch, bMatch 배열을 계산하고 최대 매칭 크기를 반환한다.
int bipartiteMatch() {
	// -1로 초기화
	aMatch = vector<int>(n, -1);
	bMatch = vector<int>(m, -1);

	int size = 0;
	for (int start = 0; start < n; start++) {
		visited = vector<bool>(n, false);

		// dfs를 이용하여 start에서 시작하는 증가경로를 찾는다.
		if (dfs(start)) size++;
	}
	return size;
}

int main() {
	n = 4; m = 4;
	adj[0][0] = 1;
	adj[0][1] = 1;
	adj[0][3] = 1;

	adj[1][0] = 1;
	adj[1][1] = 1;

	adj[2][0] = 1;
	adj[2][2] = 1;

	adj[3][2] = 1;
	adj[3][3] = 1;

	cout << bipartiteMatch() << endl;
	return 0;
}
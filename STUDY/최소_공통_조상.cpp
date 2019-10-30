#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1001
#define LOG 11 // 전체 노드의 갯수는 2^10이하

using namespace std;

int n, m, parent[MAX][LOG], d[MAX];
bool c[MAX];
vector<int> a[MAX];

// 바로 윗 부모와 연결하는 함수입니다.
void dfs(int x, int depth) {
	c[x] = true; d[x] = depth;
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (c[y]) continue;
		parent[y][0] = x;
		dfs(y, depth + 1);
	}
}

// 전체 부모 관계를 설정하는 함수
void setParent() {
	dfs(0, 0);	// 루트를 0으로 설정
	for (int j = 1; j < LOG; j++) {
		for (int i = 0; i < n; i++) {
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
		}
	}
}

// 최소 공통 조상을 찾는 함수
int LCA(int x, int y) {
	// y가 더 깊도록 설정.
	if (d[x] > d[y]) swap(x, y);
	// 두 노드의 깊이를 동일하도록 맞춘다.
	for (int i = LOG - 1; i >= 0;i--) {
		if (d[y] - d[x] >= (1 << i)) y = parent[y][i];
	}
	// 부모가 같은 경우 반환합니다.
	if (x == y) return x;
	for (int i = LOG - 1; i >= 0; i--) {
		// 조상을 향해 거슬러 올라가기
		if (parent[x][i] != parent[y][i]) {
			x = parent[x][i];
			y = parent[y][i];
		}
	}
	// 바로 부모가 찾고자하는 조상
	return parent[x][0];
}

int main(void) {

	//...
	setParent();
	LCA(5, 7);
	LCA(15, 20);

	return 0;
}
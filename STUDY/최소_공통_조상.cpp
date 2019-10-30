#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1001
#define LOG 11 // ��ü ����� ������ 2^10����

using namespace std;

int n, m, parent[MAX][LOG], d[MAX];
bool c[MAX];
vector<int> a[MAX];

// �ٷ� �� �θ�� �����ϴ� �Լ��Դϴ�.
void dfs(int x, int depth) {
	c[x] = true; d[x] = depth;
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (c[y]) continue;
		parent[y][0] = x;
		dfs(y, depth + 1);
	}
}

// ��ü �θ� ���踦 �����ϴ� �Լ�
void setParent() {
	dfs(0, 0);	// ��Ʈ�� 0���� ����
	for (int j = 1; j < LOG; j++) {
		for (int i = 0; i < n; i++) {
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
		}
	}
}

// �ּ� ���� ������ ã�� �Լ�
int LCA(int x, int y) {
	// y�� �� ���� ����.
	if (d[x] > d[y]) swap(x, y);
	// �� ����� ���̸� �����ϵ��� �����.
	for (int i = LOG - 1; i >= 0;i--) {
		if (d[y] - d[x] >= (1 << i)) y = parent[y][i];
	}
	// �θ� ���� ��� ��ȯ�մϴ�.
	if (x == y) return x;
	for (int i = LOG - 1; i >= 0; i--) {
		// ������ ���� �Ž��� �ö󰡱�
		if (parent[x][i] != parent[y][i]) {
			x = parent[x][i];
			y = parent[y][i];
		}
	}
	// �ٷ� �θ� ã�����ϴ� ����
	return parent[x][0];
}

int main(void) {

	//...
	setParent();
	LCA(5, 7);
	LCA(15, 20);

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 201

// A�� B�� ������ ����
int n, m;
// adj[i][j] = Ai�� Bj�� ������ �Ǿ��°�?
bool adj[MAX_N][MAX_N];
// �� ������ ��Ī�� ��� ������ ��ȣ�� �����Ѵ�.
vector<int> aMatch, bMatch;
// dfs()�� �湮 ����
vector<bool> visited;

// A�� ������ a���� B�� ��Ī���� ���� �������� ���� ��θ� ã��.
bool dfs(int a) {
	if (visited[a]) return false;
	visited[a] = true;
	for (int b = 0; b < m; b++) {
		if (adj[a][b]) {
			// b�� ��Ī�Ǿ� ���� �ʴٸ� bMatch[b]�������� ������ ���� ��θ� ã�´�.
			// ��Ī�Ǿ� �ִٸ� dfs���� ��Ī�Ǿ� �ִ� A������ �ٸ� ���� ��Ī �� �� �ִ��� Ȯ���Ѵ�.
			if (bMatch[b] == -1 || dfs(bMatch[b])) {
				// ���� ��θ� �߰��Ͽ��� ��, a�� b�� �����Ѵ�.
				aMatch[a] = b; bMatch[b] = a;
				return true;
			}
		}
	}
	return false;
}

// aMatch, bMatch �迭�� ����ϰ� �ִ� ��Ī ũ�⸦ ��ȯ�Ѵ�.
int bipartiteMatch() {
	// -1�� �ʱ�ȭ
	aMatch = vector<int>(n, -1);
	bMatch = vector<int>(m, -1);

	int size = 0;
	for (int start = 0; start < n; start++) {
		visited = vector<bool>(n, false);

		// dfs�� �̿��Ͽ� start���� �����ϴ� ������θ� ã�´�.
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
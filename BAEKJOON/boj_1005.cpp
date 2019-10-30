#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

#define MAXN 1005

int T, N, K, t, ans;
int D[MAXN], in_[MAXN], input_[MAXN];
vector<int> con[MAXN];

int main() {
	cin >> T;
	for (t = 1; t <= T; t++) {
		cin >> N >> K;
		for (int i = 1; i <= N; i++) {
			con[i].clear(); in_[i] = 0; cin >> input_[i];
		}
		for (int i = 1; i <= K; i++) {
			int a, b; cin >> a >> b;	// �������� �Է�
			con[a].push_back(b); in_[b]++;
		}
		for (int i = 1; i <= N; i++) {
			D[i] = 0;
		}

		queue<int> que;
		for (int i = 1; i <= N; i++) {
			if (in_[i] == 0) {	// ������ ���� 0�ΰ� ��� q�� �ֱ�
				que.push(i); D[i] = input_[i];
			}
		}

		while (!que.empty()) {
			int q = que.front(); que.pop(); // �湮 ���� �̾�

			for (int i = 0; i < con[q].size(); i++) {
				int k = con[q][i];	// ���� �̾�
				D[k] = max(D[k], D[q] + input_[k]);
				in_[k]--;
				if (in_[k] == 0) que.push(k);
			}
		}

		cin >> ans;
		printf("%d\n", D[ans]);
	}
}
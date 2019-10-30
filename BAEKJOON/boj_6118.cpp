#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define MAXN 20005
#define MAXD 100001
#define pb push_back
#define mp make_pair
#define sz(v) ((int)v.size())
typedef pair<int, int> pii;

int N, M;
int D[MAXN];
vector<int> con[MAXN], conv[MAXN];

int main(void) {
	cin >> N >> M;
	for (int i = 1; i <= N; i++)con[i].clear(), conv[i].clear();
	for (int i = 1; i <= N; i++) D[i] = MAXD;

	// �������� �Է�
	for (int i = 1; i <= M; i++) {
		int Ai, Bi; cin >> Ai >> Bi;
		con[Ai].push_back(Bi); conv[Ai].push_back(1);
		con[Bi].push_back(Ai); conv[Bi].push_back(1);
	}

	priority_queue<pii> que;

	D[1] = 0;	// ��������� �Ÿ��� 0���� ����
	que.push(mp(0, 1));	// ���ڸ� ���� �Ÿ�, ���ڸ� ���� ������ ���

	while (!que.empty()) {
		// �켱���� ť���� �� �̾Ƽ� �ְ�
		int q = que.top().second, d = -que.top().first;
		que.pop();
		if (D[q] != d) continue;

		for (int i = 0; i < con[q].size(); i++) {
			int t = con[q][i], v = conv[q][i];
			if (D[t] > D[q] + v) {
				D[t] = D[q] + v;
				que.push(mp(-D[t], t));
			}
		}
	}

	int answer1 = 0, answer2 = 0, answer3 = 0;
	for (int i = 1; i <= N; i++) {
		if (D[i] > answer2) {
			answer2 = D[i]; answer1 = i; answer3 = 1;
		}
		else if (D[i] == answer2) answer3++;
	}


	return 0;
}
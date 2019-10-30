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

	// 간선정보 입력
	for (int i = 1; i <= M; i++) {
		int Ai, Bi; cin >> Ai >> Bi;
		con[Ai].push_back(Bi); conv[Ai].push_back(1);
		con[Bi].push_back(Ai); conv[Bi].push_back(1);
	}

	priority_queue<pii> que;

	D[1] = 0;	// 출발지점의 거리를 0으로 셋팅
	que.push(mp(0, 1));	// 앞자리 값은 거리, 뒷자리 값은 목적지 노드

	while (!que.empty()) {
		// 우선순위 큐에서 값 뽑아서 넣고
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
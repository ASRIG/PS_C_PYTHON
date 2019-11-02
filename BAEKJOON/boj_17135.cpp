#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

/*
	1. 궁수의 위치 (DFS)
	2. 게임 진행 (cnt == 3)
	3. 가장 가까운 적 찾기
	4. 몬스터 제거
	5. 한칸 이동
*/

int n, m, map[20][20], d, pick_[20], mob_cnt(0);
int answer = 0;

struct MOB {
	int x, y;
	bool live = true;
	MOB() {}
	MOB(int a, int b, bool c = true) {
		x = a; y = b; live = c;
	}
};
MOB mob[230];

int abs(int aa) {
	if (aa < 0) return (aa * -1);
	else return aa;
}

int game_start() {
	// 가장 가까운 적 찾기
	int ret = 0, dis_ret = 0;
	MOB tmp[230];

	for (int i = 0; i < mob_cnt; i++) {
		tmp[i] = mob[i];
	}

	for (int ia = 0; ia < n; ia++) {
		//printf("[day : %d]\n", ia + 1);
		queue<int> q;
		for (int i = 0; i < m; i++) {
			if (pick_[i] == 1) {
				int min_dist = 100, min_idx = 0;
				for (int j = 0; j < mob_cnt; j++) {
					if (tmp[j].live) {
						int tmp_distance = abs(n - tmp[j].x) + abs(i - tmp[j].y);
						if (tmp_distance <= d && min_dist > tmp_distance) {
							min_dist = tmp_distance; min_idx = j;
						}
					}
				}
				if(min_dist != 100) q.push(min_idx);
			}
		}
		// 몬스터 제거
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			if (tmp[cur].live) {
				//printf("cur : %d 죽음\n", cur);
				ret++;
				tmp[cur].live = false;
			}
		}

		// 몬스터 이동
		for (int j = 0; j < mob_cnt; j++) {
			if (tmp[j].live) {
				tmp[j].x += 1;
				if (tmp[j].x == n) {
				//	printf("j : %d 사라짐\n", j);
					dis_ret++;
					tmp[j].live = false;
				}
			}
		}
		if (ret + dis_ret == mob_cnt) break;
	}
	
	return ret;
}

void dfs(int idx, int cnt) {
	if (cnt == 3) {
		// GAME START
		//printf("pick : ");
		//for (int i = 0; i < m; i++)printf("%d ", pick_[i]);
		//printf("\n");
		int tmp = game_start();
		//printf("[tmp : %d]\n", tmp);
		answer = max(answer, tmp);
		return;
	}

	for (int i = idx; i < m; i++) {
		pick_[i] = 1;
		dfs(i + 1, cnt + 1);
		pick_[i] = 0;
	}


}

int main(void) {
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[j][i] == 1) {
				mob[mob_cnt].x = j; mob[mob_cnt].y = i;
				mob[mob_cnt].live = true; mob_cnt++;
			}
		}
	}

	dfs(0, 0);

	printf("%d\n", answer);
	return 0;
}
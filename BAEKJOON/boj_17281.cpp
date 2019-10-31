#include <iostream>
#define max(a, b) a < b ? b : a
using namespace std;

int team_[10], n, cmd[51][10], answer = 0;

int game_start() {
	int ret = 0, cnt = 1;
	int arr[5];
	for (int ining = 1; ining <= n; ining++) {
		int out_count = 0;
		for (int i = 0; i < 5; i++) arr[i] = 0;
		while (1) {
			int cur = cmd[ining][team_[cnt]];
			//printf("team_[cnt] : %d, cmd[ining][team_[cnt]] : %d\n", team_[cnt], cmd[ining][team_[cnt]]);
			if (cur == 0) {
				out_count += 1;
			}
			else if (cur == 1 || cur == 2 || cur == 3) {
				// 안타
				arr[0] = 1;
				for (int i = 3; i >= 0; i--) {
					if (arr[i] == 1) {
						if (i + cur >= 4) {
							// 도착한 경우
							arr[i] = 0;
							ret++; 
						}else {
							// 아닌 경우
							arr[i] = 0; arr[i + cur] = 1;
						}
						
					}
				}
			}
			else if (cur == 4) {
				// 홈런
				arr[0] = 1;
				for (int i = 0; i < 4; i++) {
					if (arr[i] == 1) {
						arr[i] = 0; ret += 1;
					}
				}
			}

			cnt += 1;
			if (cnt == 10) cnt = 1;
			if (out_count == 3) break;
		}
	}
	return ret;
}


void dfs(int cnt_) {
	if (cnt_ == 10) {
		// GAME START
		//for(int i=1; i<10; i++) printf("%d ", team_[i]);
		//printf("\n");
		int tmp = game_start();
		if (answer < tmp) answer = tmp;
		return;
	}

	if (cnt_ == 4) {
		team_[cnt_] = 1;
		dfs(cnt_ + 1);
	}
	else {
		for (int peo = 2; peo <= 9; peo++) {
			bool false_sw = true;
			for (int k = 1; k <= 9; k++) {
				if (team_[k] == peo) {
					false_sw = false; break;
				}
			}
			if (false_sw) {
				team_[cnt_] = peo;
				dfs(cnt_ + 1);
				team_[cnt_] = 0;
			}
		}
	}
}


int main(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> cmd[i][j];
		}
	}
	dfs(1);
	printf("%d\n", answer);
	return 0;
}
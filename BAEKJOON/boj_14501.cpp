#include <iostream>
#define min(a, b) a < b ? a : b
using namespace std;

int pick[25], n, stat_[25][25];
int team_cnt, answer = 0x7fffffff;

int calculate() {
	int team1_pow = 0, team2_pow = 0;
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			if (pick[k] == 0 && pick[i] == 0) team1_pow += stat_[i][k];
			else if(pick[k] == 1 && pick[i] == 1)team2_pow += stat_[i][k];
		}
	}
	int ret;
	ret = team2_pow - team1_pow; if (ret < 0) ret *= -1; 
	return ret;
}

void dfs(int idx, int cnt_) {
	if (cnt_ == team_cnt) {
		int tmp = calculate();
		answer = min(answer, tmp);
		return;
	}
	
	for (int i = idx; i < n; i++) {
		pick[i] = 1;
		dfs(i + 1, cnt_ + 1);
		pick[i] = 0;
	}
}

int main(void) {
	scanf("%d", &n);
	team_cnt = n / 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//cin >> stat_[i][j];
			scanf("%d", &stat_[i][j]);
		}
	}

	dfs(0, 0);

	printf("%d\n", answer);
	return 0;
}
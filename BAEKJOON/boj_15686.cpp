#include <iostream>
#define min(a, b) a < b ? a : b
using namespace std;

int abs(int a) {
	if (a < 0) return (a * -1);
	else return a;
}

struct BUILD {
	int x, y;
};

BUILD chick[15];
BUILD house[105];

int n, m, chick_cnt = 0, house_cnt = 0, map[55][55];
int pick_[15], answer;

int cal() {
	int ret = 0;
	int temp_data[105];
	for (int i = 0; i < house_cnt; i++) temp_data[i] = 0x7fffffff;
	for (int i = 0; i < chick_cnt; i++) {
		if (pick_[i] == 0) continue;
		for (int j = 0; j < house_cnt; j++) {
			temp_data[j] = min(temp_data[j] , abs(chick[i].x - house[j].x) + abs(chick[i].y - house[j].y));
		}
	}
	for (int i = 0; i < house_cnt; i++) ret += temp_data[i];


	return ret;
}

void dfs(int idx, int cnt) {
	if (cnt <= m && cnt >= 1) {
		//cal
		int tmp = cal();
		if (tmp < answer) {
			//printf("tmp : %d, answer : %d cnt : %d\n", tmp, answer, cnt);
			answer = tmp;
		}
	}
	if (cnt == m) return;

	for (int i = idx; i < chick_cnt; i++) {
		pick_[i] = 1;
		dfs(i + 1, cnt + 1);
		pick_[i] = 0;
	}
}

int main(void) {
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				chick[chick_cnt].x = i;  chick[chick_cnt].y = j;
				chick_cnt++;
			}
			else if (map[i][j] == 1) {
				house[house_cnt].x = i;  house[house_cnt].y = j;
				house_cnt++;
			}
		}
	}
	answer = 0x7fffffff;
	dfs(0, 0);

	printf("%d\n", answer);

	return 0;
}
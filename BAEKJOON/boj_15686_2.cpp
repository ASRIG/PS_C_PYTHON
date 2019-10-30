#include <iostream>
#include <algorithm>
using namespace std;

struct BUILDING {
	int x, y;
};

int n, m, map[52][52], pick[14], chick_cnt(0), house_cnt = 0;
int answer = 0x7fffffff;
BUILDING chick[14];
BUILDING house[105];

int abs(int aa) {
	if (aa < 0) return aa * -1;
	else return aa;
}

int calculate() {
	int ret = 0;
	int D[105];
	for (int i = 0; i < house_cnt; i++) D[i] = 9999999;
	for (int i = 0; i < chick_cnt; i++) {
		if (pick[i] == 0) continue;
		for (int j = 0; j < house_cnt; j++) {
			int dist = abs(house[j].x - chick[i].x) + abs(house[j].y - chick[i].y);
			if (D[j] > dist) D[j] = dist;
		}
	}
	for (int i = 0; i < house_cnt; i++) {
		ret += D[i];
	}
	return ret;
}

void dfs(int idx, int cnt) {
	if (cnt <= m && cnt != 0) {
		int tmp = calculate();
		//printf("tmp : %d\n", tmp);
		answer = min(answer, tmp);
		if (cnt == m) return;
	}
	for (int i = idx; i < chick_cnt; i++) {
		pick[i] = 1;
		dfs(i + 1, cnt + 1);
		pick[i] = 0;
	}
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				chick[chick_cnt].x = i; chick[chick_cnt].y = j; chick_cnt++;
			}
			else if (map[i][j] == 1) {
				house[house_cnt].x = i; house[house_cnt].y = j; house_cnt++;
			}
		}
	}

	dfs(0, 0);

	printf("%d\n", answer);

	return 0;
}
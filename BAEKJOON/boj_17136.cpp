#include <iostream>
#include <algorithm>

using namespace std;
// 1x1, 2x2, 3x3, 4x4, 5x5 각 5개
int cnt[6] = { 0, 5, 5, 5, 5, 5 };
int map[11][11], answer = 0x7fffffff;

bool is_okay(int a, int b, int k, bool visited[11][11]) {
	/*
		해당하는 종이를 넣을 수 있는지 판별
		a, b	::	x값, y값
		k		::	종이의 크기
	*/
	for (int i = a; i < a + k; i++) {
		for (int j = b; j < b + k; j++) {
			if (map[i][j] == 0) return false;
			else if (visited[i][j] == true) return false;
		}
	}
	return true;
}

void copy_array(bool src[11][11], bool dest[11][11]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			dest[i][j] = src[i][j];
		}
	}
}

void map_update_(int a, int b, int k, bool visited[11][11]) {
	/*
		해당하는 종이를 넣을 수 있는지 판별
		a, b	::	x값, y값
		k		::	종이의 크기
	*/
	for (int i = a; i < a + k; i++) {
		for (int j = b; j < b + k; j++) {
			visited[i][j] = true;
		}
	}
}

bool verify_(bool visited[11][11]) {
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (map[i][j] == 1 && visited[i][j] == false) return false;
		}
	}
	return true;
}

void dfs(int idx, int idy, bool visited[11][11], int ans_cnt) {
	bool verify_sw = verify_(visited);
	if (verify_sw) {
		answer = min(ans_cnt, answer);
	}
	bool break_sw = false;
	// 종이를 넣을 수 있는 지 판별
	for (int i = idx; i < 10; i++) {
		for (int j = idy; j < 10; j++) {
			if (map[i][j] == 0) continue;
			else if (visited[i][j] == true) continue;
			for (int k = 5; k >= 1; k--) {
				if (cnt[k] <= 0) continue;
				// 영역 초과 부분 버리기
				if (i > 10 - k || j > 10 - k) continue;
				bool okay_sw = is_okay(i, j, k, visited);
				if (okay_sw == true && cnt[k] > 0) {
					// visited를 복사
					bool tmp[11][11];
					copy_array(visited, tmp);
					// cnt 조정, visited 업데이트 및 dfs 호출
					map_update_(i, j, k, tmp); cnt[k] -= 1;
					dfs(i, j + 1, tmp, ans_cnt + 1);
					cnt[k] += 1;
				}
				break_sw = true;
			}
			if (break_sw) break;
		}
		idy = 0;
		if (break_sw) break;
	}
	
}

int main(void) {
	bool matched_[11][11];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> map[i][j]; matched_[i][j] = false;
		}
	}


	dfs(0,0, matched_, 0);
	if (answer == 0x7fffffff) answer = -1;
	printf("%d\n", answer);
	return 0;
}
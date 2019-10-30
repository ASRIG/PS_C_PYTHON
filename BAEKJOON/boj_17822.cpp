#include <iostream>

using namespace std;

int arr[55][55];
bool tmp_map[55][55];
int x, d, k, n, m, t;

void rotate_arr(int xx, int dir) {
	if (dir == 0) {
		// 시계방향
		int tmp = arr[xx][m];
		for (int i = m; i > 1; i--) {
			arr[xx][i] = arr[xx][i - 1];
		}
		arr[xx][1] = tmp;
	}
	else {
		// 반시계 방향
		int tmp = arr[xx][1];
		for (int i = 1; i < m; i++) {
			arr[xx][i] = arr[xx][i + 1];
		}
		arr[xx][m] = tmp;
	}
}

int main(void) {
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int tt = 0; tt < t; tt++) {
		cin >> x >> d >> k;
		
		// [d] : 0 -> 시계방향, 1 -> 반시계방향
		for (int ia = x; ia <= n; ia += x) {
			// k번 회전
			for (int ib = 0; ib < k; ib++) {
				// 1번 회전
				rotate_arr(ia, d);
			}
		}
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				tmp_map[i][j] = false;
			}
		}

		// 숫자제거하기
		bool is_updated = false;
		// 자기 원 내부에서 확인
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (j == m) {
					if (arr[i][m] != 0 && arr[i][m] == arr[i][1]) {
						is_updated = true;
						tmp_map[i][m] = true; tmp_map[i][1] = true;
					}
				}
				else if (arr[i][j] != 0 && arr[i][j] == arr[i][j + 1]) {
					is_updated = true;
					tmp_map[i][j] = true; tmp_map[i][j + 1] = true;
				}
			}
		}
		// 바깥 원에서 확인
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j < n; j++) {
				if (arr[j][i] != 0 && arr[j][i] == arr[j + 1][i]) {
					is_updated = true;
					tmp_map[j][i] = true; tmp_map[j + 1][i] = true;
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (tmp_map[i][j] == true) arr[i][j] = 0;
			}
		}

		if (is_updated == false) {
			float tmp = 0; int cnt = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (arr[i][j] != 0) {
						tmp += arr[i][j]; cnt += 1;
					}
				}
			}
			float tmpp = tmp / cnt;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (arr[i][j] != 0) {
						if (arr[i][j] < tmpp) {
							arr[i][j] += 1;
						}
						else if (arr[i][j] > tmpp) {
							arr[i][j] -= 1;
						}
					}
				}
			}
		}
	}
	int answer = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (arr[i][j] != 0) answer += arr[i][j];
	

		
	printf("%d\n", answer);
	return 0;
}
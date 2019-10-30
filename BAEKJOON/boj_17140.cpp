#include <iostream>
#define max(a, b) a < b ? b : a
using namespace std;


int cnt_[101];
int r, c, k, a[105][105], b[105][105];
int cur_i = 3, cur_j = 3;

void fill_cnt_zero() {
	for (int i = 0; i <= 100; i++) {
		cnt_[i] = 0;
	}
}

void view_() {
	printf("\n");
	for (int i = 1; i <= cur_i; i++) {
		for (int j = 1; j <= cur_j; j++) {
			printf("%d ", a[i][j]);
		}printf("\n");
	}
}

void copy_arr(int src[105][105], int des[105][105]) {
	for (int i = 1; i <= cur_i; i++) {
		for (int j = 1; j <= cur_j; j++) {
			des[i][j] = src[i][j]; src[i][j] = 0;
		}
	}
}


int main(void) {
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> a[i][j];
		}
	}

	int tim = 0;
	for (tim = 0; tim <= 101; tim++) {
		if (a[r][c] == k || tim == 101) break;

		//view_();
		if (cur_i >= cur_j) {
			// R 연산
			int tmp_ = 1, tmp_max = 1;
			for (int i = 1; i <= cur_i; i++) {
				fill_cnt_zero();
				for (int j = 1; j <= cur_j; j++) {
					cnt_[a[i][j]]++;
				}
				for (int ia = 1; ia <= 100; ia++) {
					for (int ib = 1; ib <= 100; ib++) {
						if (cnt_[ib] == ia) {
							b[i][tmp_++] = ib; b[i][tmp_++] = ia;
						}
					}
				}
				tmp_max = max(tmp_max, tmp_ - 1); tmp_ = 1;
			}
			if (tmp_max > 100) tmp_max = 100;
			cur_j = tmp_max;
			copy_arr(b, a);
		}
		else {
			// C 연산
			int tmp_ = 1, tmp_max = 1;
			for (int j = 1; j <= cur_j; j++) {
				fill_cnt_zero();
				for (int i = 1; i <= cur_i; i++) {
					cnt_[a[i][j]]++;
				}
				for (int ia = 1; ia <= 100; ia++) {
					for (int ib = 1; ib <= 100; ib++) {
						if (cnt_[ib] == ia) {
							b[tmp_++][j] = ib; b[tmp_++][j] = ia;
						}
					}
				}
				tmp_max = max(tmp_max, tmp_ - 1); tmp_ = 1;
			}
			if (tmp_max > 100) tmp_max = 100;
			cur_i = tmp_max;
			copy_arr(b, a);
		}
		//view_();
	}

	if (tim == 101) printf("-1\n");
	else printf("%d\n", tim);

	return 0;
}
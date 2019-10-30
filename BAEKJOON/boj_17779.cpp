#include <iostream>
#include <algorithm>
using namespace std;

int arr[22][22], n, answer= 0x7fffffff;
int team_[22][22], tmp[22][22], tmp2[22][22];

void copy_map(int src[22][22], int dest[22][22]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dest[i][j] =  src[i][j];
		}
	}
}

void print_tmp() {
	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", tmp2[i][j]);
		}printf("\n");
	}
}

void map_init(int src[22][22]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			src[i][j] = 0;
		}
	}
}


int calc(int up_x, int up_y, int left_x, int left_y, int right_x, int right_y, int down_x, int down_y) {
	int x_size = max(left_x, right_x);
	int tmpx = up_x, tmpy = up_y;
	for (;;) {
		tmpx += 1; tmpy += 1;
		tmp2[tmpx][tmpy] = 5;
		if (tmpx == right_x && tmpy == right_y) break;
	}

	tmpx = up_x, tmpy = up_y;
	for (;;) {
		tmpx += 1; tmpy -= 1;
		tmp2[tmpx][tmpy] = 5;
		if (tmpx == left_x && tmpy == left_y) break;
	}

	tmpx = right_x, tmpy = right_y;
	for (;;) {
		tmpx += 1; tmpy -= 1;
		tmp2[tmpx][tmpy] = 5;
		if (tmpx == down_x && tmpy == down_y) break;
	}

	tmpx = left_x, tmpy = left_y;
	for (;;) {
		tmpx += 1; tmpy += 1;
		tmp2[tmpx][tmpy] = 5;
		if (tmpx == down_x && tmpy == down_y) break;
	}

	for (int j = left_y + 1; j < right_y; j++) {
		int tmp_i = -1;
		while (1) {
			tmp_i += 1;
			if (tmp_i >= n) break;
			if (tmp2[tmp_i][j] == 5) {
				int tmpp_i = tmp_i;
				while (1) {
					tmpp_i += 1;
					if (tmp2[tmpp_i][j] == 5) break;
					tmp2[tmpp_i][j] = 5;
				}
				break;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tmp2[i][j] == 5) continue;
			if (i < left_x && j <= up_y) tmp2[i][j] = 1;
			else if (i <= right_x && j > up_y) tmp2[i][j] = 2;
			else if (i >= left_x && j < down_y) tmp2[i][j] = 3;
			else if (i > right_x && j >= down_y) tmp2[i][j] = 4;
		}
	}

	int team1_p(0), team2_p(0), team3_p(0), team4_p(0), team5_p(0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tmp2[i][j] == 1) team1_p += arr[i][j];
			else if (tmp2[i][j] == 2) team2_p += arr[i][j];
			else if (tmp2[i][j] == 3) team3_p += arr[i][j];
			else if (tmp2[i][j] == 4) team4_p += arr[i][j];
			else if (tmp2[i][j] == 5) team5_p += arr[i][j];
		}
	}

	//print_tmp();
	
	int max_team = max({ team1_p , team2_p ,team3_p ,team4_p ,team5_p });
	int min_team = min({ team1_p , team2_p ,team3_p ,team4_p ,team5_p });

	return (max_team - min_team);
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			int cur_i = i, cur_j = j;
			map_init(team_);
			team_[cur_i][cur_j] = 5;

			// left 찾기
			int new_left_i = cur_i, new_left_j = cur_j;
			int left_cnt = 0;
			while (1) {

				new_left_i += 1; new_left_j -= 1;
				if (new_left_j < 0) break;
				left_cnt++;
				copy_map(team_, tmp);

				// right 찾기
				int new_right_i = cur_i, new_right_j = cur_j;
				int right_cnt = 0;
				while (1) {
					new_right_i += 1; new_right_j += 1;
					if (new_right_j >= n) break;
					right_cnt++;
					
					bool false_sw = false;
					// bottom 찾기

					int tmp_bottm_i = new_left_i, tmp_bottm_j = new_left_j;
					for (int ia = 0; ia < right_cnt; ia++) {
						tmp_bottm_i += 1; tmp_bottm_j += 1;
						if (tmp_bottm_i >= n || tmp_bottm_j >= n) {
							false_sw = true; break;
						}
					}
					if (false_sw) continue;

					int tmp_bottm_i2 = new_right_i, tmp_bottm_j2 = new_right_j;
					for (int ia = 0; ia < left_cnt; ia++) {
						tmp_bottm_i2 += 1; tmp_bottm_j2 -= 1;
						if (tmp_bottm_i2 >= n || tmp_bottm_j2 >= n || new_right_j < 0) {
							false_sw = true; break;
						}
					}
					if (false_sw) continue;
					if (tmp_bottm_i != tmp_bottm_i2 || tmp_bottm_j != tmp_bottm_j2) continue;

					copy_map(tmp, tmp2);
					int tmpp = calc(i, j, new_left_i, new_left_j, new_right_i, new_right_j, tmp_bottm_i, tmp_bottm_j);
					answer = min(tmpp, answer);
				}
			}
			

		}
	}

	printf("%d\n", answer);
	return 0;
}
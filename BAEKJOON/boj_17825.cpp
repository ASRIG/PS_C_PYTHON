#include <iostream>
#define max(a, b) a < b ? b : a
using namespace std;

int arr[90], cmd[11], answer = 0;
// 시작 0
// 갈림길 : 5, 10, 15,  
// [31 32 33 ... ], [51, 52 ...], [71,72,73 ...]
// [20 -> 25(도착)]

struct GO_ {
	int x[4];
	GO_(int a, int b, int c, int d) {
		x[0] = a; x[1] = b; x[2] = c; x[3] = d;
	}
};

void dfs(int num, int cnt, int sum, GO_ go) {
	if (cnt == 10) {
		//printf("sum : %d\n", sum);
		answer = max(answer, sum);
		return;
	}

	// 새로운 말을 출격시키는 경우
	if (num < 4) {
		// 그곳에 이미 존재하는 경우
		if (go.x[0] == cmd[cnt] || go.x[1] == cmd[cnt] || go.x[2] == cmd[cnt] || go.x[3] == cmd[cnt]) {
			//
		}
		// 존재하지 않는 경우
		else {
			GO_ tmp = go;
			tmp.x[num] = cmd[cnt];
			dfs(num + 1, cnt + 1, sum + arr[cmd[cnt]], tmp);
		}
	}

	// 이미 있는 말 중에서 한개를 사용하는 경우
	for (int i = 0; i < num; i++) {
		if (go.x[i] == 21 || go.x[i] == 38 || go.x[i] == 57 || go.x[i] == 78) continue;
		int cur_x = go.x[i];
		if (cur_x == 5) {
			cur_x = 30;
		}
		else if (cur_x == 10) {
			cur_x = 50;
		}
		else if (cur_x == 15) {
			cur_x = 70;
		}
		else {
			//
		}

		int tmp_x = cur_x + cmd[cnt];

		if (cur_x <= 20 && tmp_x >= 21) tmp_x = 21;
		else if (cur_x >= 30 && cur_x < 50 && tmp_x >= 38) tmp_x = 38;
		else if (cur_x >= 50 && cur_x < 70 && tmp_x >= 57) tmp_x = 57;
		else if (cur_x >= 70 && cur_x < 90 && tmp_x >= 78) tmp_x = 78;
		
		// 그곳에 이미 존재하는 경우 찾기
		bool false_sw = true;
		for (int i = 0; i < num; i++) {
			if (tmp_x == 20 || tmp_x == 37 || tmp_x == 56 || tmp_x == 77) {
				if (go.x[i] == 20 || go.x[i] == 37 || go.x[i] == 56 || go.x[i] == 77)
					false_sw = false;
			}
			else if (tmp_x == 36 || tmp_x == 55 || tmp_x == 76) {
				if (go.x[i] == 36 || go.x[i] == 55 || go.x[i] == 76) false_sw = false;
			}
			else if (tmp_x == 35 || tmp_x == 54 || tmp_x == 75) {
				if (go.x[i] == 35 || go.x[i] == 54 || go.x[i] == 75) false_sw = false;
			}
			else if (tmp_x == 34 || tmp_x == 53 || tmp_x == 74) {
				if (go.x[i] == 34 || go.x[i] == 53 || go.x[i] == 74) false_sw = false;
			}
			else if (go.x[i] == tmp_x) {
				if (tmp_x == 21 || tmp_x == 38 || tmp_x == 57 || tmp_x == 78) continue;
				false_sw = false;
			}
		}
		if (false_sw == false) {
			continue;
		}
		else {
			GO_ tmp = go;
			tmp.x[i] = tmp_x;
			dfs(num, cnt + 1, sum + arr[tmp_x], tmp);
		}
	}
}


int main(void) {
	for (int i = 0; i <= 20; i++) {
		arr[i] = i * 2;
	}
	arr[0] = 0; arr[21] = 0;
	arr[31] = 13; arr[32] = 16; arr[33] = 19;
	arr[34] = 25; arr[35] = 30; arr[36] = 35; arr[37] = 40; arr[38] = 0;
	arr[51] = 22; arr[52] = 24;
	arr[53] = 25; arr[54] = 30; arr[55] = 35; arr[56] = 40; arr[57] = 0;
	arr[71] = 28; arr[72] = 27; arr[73] = 26;
	arr[74] = 25; arr[75] = 30; arr[76] = 35; arr[77] = 40; arr[78] = 0;

	for (int i = 0; i < 10; i++) {
		cin >> cmd[i];
	}
	GO_ g(0, 0, 0, 0);
	dfs(0, 0, 0, g);

	printf("%d\n", answer);

	return 0;
}
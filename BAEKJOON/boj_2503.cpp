#include <iostream>

using namespace std;

int n, num, strike_, ball_;
bool arr[1001];

bool game_start(int a, int b, int strike, int ball) {
	int tmp_s = 0, tmp_b = 0;
	char char_a[4], char_b[4];
	sprintf(char_a, "%d", a); sprintf(char_b, "%d", b);

	// 스트라이크, 볼 판별
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j && char_a[i] == char_b[j]) tmp_s++;
			if (i != j && char_a[i] == char_b[j]) tmp_b++;
		}
	}

	if (tmp_s == strike && tmp_b == ball) return true;
	else return false;
}


int main(void) {
	ios::sync_with_stdio(0); cin.tie(nullptr);
	cin >> n;
	for (int i = 111; i < 1000; i++) {
		char tmp[4];
		sprintf(tmp, "%d", i);
		arr[i] = true;
		// 0이 들어간 경우 삭제
		for (int ia = 0; ia < 3; ia++)
			if (tmp[ia] == '0') arr[i] = false;
		// 숫자가 같은게 있을 경우 삭제
		if (tmp[0] == tmp[1] || tmp[1] == tmp[2] || tmp[0] == tmp[2]) arr[i] = false;
	}

	while(n--){
		cin >> num >> strike_ >> ball_;
		for (int i = 111; i < 1000; i++)
			if (arr[i] && !game_start(i, num, strike_, ball_)) arr[i] = false;
	}

	int ans = 0;
	for (int i = 111; i < 1000; i++) {
		if (arr[i]) ans++;
	}

	printf("%d\n", ans);
	return 0;
}
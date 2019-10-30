#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

// �𸣰ڼ���..

int i, j, l, t, N;
char input[25]; char bridge[2][105];
int angel[25][105], devil[25][105];
long long answer;
int cnt, cnt_input;

int main(void) {
	cin >> input;
	cnt_input = strlen(input);

	cin >> bridge[0]; cin >> bridge[1];
	cnt = strlen(bridge[0]);

	for (i = 1; i <= cnt_input; i++) {
		for (j = i; j <= cnt; j++) {
			//�Ǹ��� ���ٸ����� ����
			if (bridge[(i - 1) % 2][j - 1] == input[i - 1]) {
				if (i == 1) devil[i][j] = devil[i][j - 1] + 1;
				else devil[i][j] = devil[i - 1][j - 1] + devil[i][j - 1]; // ����
			}
			else {
				devil[i][j] = devil[i][j - 1];
			}
			// õ���� ���ٸ����� ����
			if (bridge[i % 2][j - 1] == input[i - 1]) {
				if (i == 1) angel[i][j] = angel[i][j - 1] + 1;
				else angel[i][j] = angel[i - 1][j - 1] + angel[i][j - 1];
			}
			else {
				angel[i][j] = angel[i][j - 1];
			}
		}
	}
	answer = angel[cnt_input][cnt] + devil[cnt_input][cnt];
	printf("%lld\n", answer);
	return 0;
}
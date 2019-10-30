#include <iostream>
#include <string>
using namespace std;

char map[20][10];
int n, answer;

int main(void) {
	for (int tes = 1; tes <= 10; tes++) {
		cin >> n; answer = 0;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				map[i + 8][j] = map[j][i];
			}
		}

		int cmp_n = n / 2;
		if ((n & (1 << 0)) == 1) cmp_n += 1;

		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 8 - (n - 1); j++) {
				int cnt = 0;
				for (int k = 0; k < n; k++) {
					if (map[i][j + k] == map[i][j + n - 1 - k]) cnt++;
					else break;
				} 
				if (cnt == n) answer++;
			}
		}
		printf("#%d %d\n", tes, answer);
	}

	return 0;
}
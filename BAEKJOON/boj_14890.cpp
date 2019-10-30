#include <iostream>

using namespace std;

int n, l, m[205][105];

int main(void) {
	scanf("%d %d", &n, &l);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &m[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			m[n + i][j] = m[j][i];
		}
	}

	int answer = 0;
	for (int i = 0; i < 2 * n; i++) {
		int tmp_idx = 1, j;
		for (j = 0; j < n - 1; j++) {
			if (m[i][j + 1] - m[i][j] == 1) {
				if(tmp_idx >= l) tmp_idx = 1;
				else break;
			}
			else if (m[i][j] == m[i][j + 1]) {
				tmp_idx++;
			}
			else if(m[i][j + 1] - m[i][j] == -1){
				if (tmp_idx < 0) break;
				tmp_idx = -l + 1;
			}
			else {
				break;
			}
		}
		if (j == n - 1 && tmp_idx >= 0) {
			//printf("answer : %d\n", i);
			answer++;
		}
	}

	printf("%d\n", answer);
	return 0;
}
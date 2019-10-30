#include <iostream>

using namespace std;

int n, l, map[210][105], answer = 0;

int main(void) {
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[n + i][j] = map[j][i];
		}
	}

	for (int i = 0; i < 2 * n; i++) {
		int step_ = 1;
		bool fail_sw = false;
		for (int j = 1; j < n; j++) {
			if (map[i][j - 1] == map[i][j]) {
				step_ += 1;
			}
			else if (map[i][j - 1] < map[i][j]) {
				if (step_ < 0 || step_ < l) {
					fail_sw = true; break;
				}
				step_ = 1;
			}
			else {
				if (step_ < 0) {
					fail_sw = true; break;
				}
				step_ = -l + 1;
			}
		}
		if (fail_sw == false && step_ >= 0) answer++;
	}

	printf("%d\n", answer);
	return 0;
}
#include <iostream>

using namespace std;

int n, m;
char map[11][11], tmp[11][11];

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j]; tmp[i][j] = map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] = tmp[i][m - 1 - j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%c", map[i][j]);
		}printf("\n");
	}

	return 0;
}
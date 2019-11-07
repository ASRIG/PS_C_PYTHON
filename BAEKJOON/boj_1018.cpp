#include <iostream>
#define min(a, b) a < b ? a : b
using namespace std;

int n, m, answer = 50000;
char map[52][52];

int game_start(int a, int b) {
	// ü���ǿ��� �ٲ���ϴ� ���� ������ ã�´�.
	int ret1 = 0, ret2 = 0;
	char start_char = map[a][b];

	// ù��°�� �������� ü������ �����Ѵ�.
	for (int i = a; i < a + 8; i++) {
		for (int j = b; j < b + 8; j++) {
			if ((!((i - a) & 1) && !((j - b) & 1)) && map[i][j] != start_char) ret1++;
			else if ((!((i - a) & 1) && ((j - b) & 1)) && map[i][j] == start_char) ret1++;
			else if ((((i - a) & 1) && !((j - b) & 1)) && map[i][j] == start_char) ret1++;
			else if ((((i - a) & 1) && ((j - b) & 1)) && map[i][j] != start_char) ret1++;
		}
	}

	// ù��°�� Ʋ���� ���� ü������ �����Ѵ�.
	for (int i = a; i < a + 8; i++) {
		for (int j = b; j < b + 8; j++) {
			if ((!((i - a) & 1) && !((j - b) & 1)) && map[i][j] == start_char) ret2++;
			else if ((!((i - a) & 1) && ((j - b) & 1)) && map[i][j] != start_char) ret2++;
			else if ((((i - a) & 1) && !((j - b) & 1)) && map[i][j] != start_char) ret2++;
			else if ((((i - a) & 1) && ((j - b) & 1)) && map[i][j] == start_char) ret2++;
		}
	}
	return min(ret1, ret2);
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			answer = min(game_start(i, j), answer);
		}
	}
	printf("%d\n", answer);
	return 0;
}
#include <iostream>

using namespace std;

int path_[21][21][4][16];

int main(void) {
	memset(path_, -1, sizeof(path_));
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			for (int ia = 0; ia < 4; ia++) {
				for (int ib = 0; ib < 16; ib++) {
					printf("%d ", path_[i][j][ia][ib]);
				}
			}
		}
	}
	return 0;
}
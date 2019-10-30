#include <iostream>

using namespace std;

char map[8][8];
int cnt = 0;

int main(void) {
	int a[8];
	for (int i = 0; i < 8; i++) {
		a[i] = i;
	}

	for (int i = 0; i < 8; i++) {
		printf("i & (1 << 0) : %d \n", i & 1);

		if (i & 1) {
			printf("%d \n", i);
		}else{
			printf("tt %d \n", i);
		}
	}

	return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

int tmp;
char cnt = 'A' - 1; 

int main(void) {
	// 0 배(뒤집), 1 등
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> tmp;
			if (tmp == 0) cnt++;
		}
		if (cnt == 'A' - 1) cnt = 'E';
		printf("%c\n", cnt);
		cnt = 'A' - 1;
	}


	return 0;
}
#include <iostream>

using namespace std;

int arr[10], t;

void move_arr() {
	for (int i = 0; i < 8; i++) {
		arr[i] = arr[i + 1];
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int tes = 1; tes <= 10; tes++) {
		cin >> t;
		bool end_sw = false;
		for (int i = 0; i < 8; i++) cin >> arr[i];
		
		while (1) {
			for (int j = 1; j <= 5; j++) {
				if (arr[0] - j <= 0) {
					arr[8] = 0; end_sw = true; 
					move_arr(); break;
				}
				else {
					arr[8] = arr[0] - j;
				}
				move_arr();
			}
			if (end_sw) break;
		}
		
		printf("#%d ", t);
		for (int i = 0; i < 8; i++) {
			printf("%d", arr[i]);
			if (i != 7) printf(" ");
			else printf("\n");
		}
	}
	return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

long long red_stone, blue_stone;
long long max = (long long)1e16;
int t;

int main(void) {
	cin >> t;
	for (int tes = 1; tes <= t; tes++) {
		cin >> red_stone >> blue_stone;
		bool red_win = false;
		long long min_num = min(red_stone, blue_stone);
		printf("red : %lld, blue : %lld, min_num : %lld\n", red_stone, blue_stone, min_num);

		for (long long i = 1; i <= min_num / 2; i++) {
			bool is_updated = true;
			while (is_updated) {
				printf("red : %lld, blue : %lld, i : %lld\n", red_stone, blue_stone, i);
				is_updated = false;
				red_stone -= 2 * i; blue_stone += i;
				if (red_stone < 0)break;
				red_stone += i; blue_stone -= 2 * i;
				if (blue_stone < 0) { 
					red_win = true;	break;
				}
				is_updated = true;
			}
			if (red_win) break;
		}
		if (red_win) printf("#%d KJ\n", tes);
		else printf("#%d DH\n", tes);
	}


	return 0;
}
#include <iostream>
#include <string>

using namespace std;

string str, cmp_s;
int ans = 0, t;

void find_(int start) {
	int k = str.find(cmp_s, start);
	if (k != -1) {
		ans += 1; find_(k + 1);
	}
}

int main(void) {
	for (int tes = 1; tes <= 10; tes++) {
		ans = 0;
		cin >> t;
		cin >> cmp_s;
		cin >> str;
		find_(0);
		printf("#%d %d\n", t, ans);
	}
	return 0;
}
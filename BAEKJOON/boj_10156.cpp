#include <iostream>

using namespace std;

int k, n, m;

int main(void) {
	cin >> k >> n >> m;
	int need_money = k * n;
	int answer = 0;
	if (need_money > m) {
		answer = need_money - m;
	}
	printf("%d\n", answer);
	return 0;
}
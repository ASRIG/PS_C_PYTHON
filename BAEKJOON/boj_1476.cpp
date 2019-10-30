#include <iostream>

using namespace std;

int E, S, M;

int main(void) {
	cin >> E >> S >> M;
	for (int i = 1; ; i++) {
		int e = i % 15, s = i % 28, m = i % 19;
		if (e == 0) e = 15; if (s == 0) s = 28; if (m == 0) m = 19;
		//printf("%d\n", i);
		if (e == E && s == S && m == M) {
			printf("%d\n", i); break;
		}
	}

	return 0;
}
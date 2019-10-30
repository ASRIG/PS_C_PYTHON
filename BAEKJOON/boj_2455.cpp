#include <iostream>

using namespace std;

int cnt_ = 0, a, b, answer = -1;

int max(int aa, int bb) {
	if (aa > bb) return aa;
	else return bb;
}

int main(void) {
	for (int i = 0; i < 4; i++) {
		scanf("%d%d", &a, &b);
		cnt_ += b; cnt_ -= a;
		answer = max(cnt_, answer);
	}
	printf("%d\n", answer);
	return 0;
}
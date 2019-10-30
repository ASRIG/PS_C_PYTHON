#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n, w, h, tmp, input_;

int main(void) {
	cin >> n >> w >> h;
	tmp = (int)sqrt(w * w + h * h);
	for (int i = 0; i < n; i++) {
		cin >> input_;
		if (input_ <= tmp) printf("DA\n");
		else printf("NE\n");
	}

	return 0;
}
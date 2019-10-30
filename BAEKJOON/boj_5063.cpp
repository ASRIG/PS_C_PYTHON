#include <iostream>

using namespace std;

int n, r, e, c;

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &r, &e, &c);
		if (r < (e - c)) printf("advertise\n");
		else if (r > (e - c)) printf("do not advertise\n");
		else if (r == (e - c)) printf("does not matter\n");
	}
	return 0;
}
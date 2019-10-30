#include <iostream>

using namespace std;

int s, t, tmp;

int main(void) {
	for (int i = 0; i < 4; i++) cin >> tmp, s += tmp;
	for (int i = 0; i < 4; i++) cin >> tmp, t += tmp;
	if (s >= t) printf("%d\n", s);
	else printf("%d\n", t);
	
	return 0;
}
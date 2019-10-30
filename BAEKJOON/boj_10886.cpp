#include <iostream>
#define max(a, b) a < b ? b : a
using namespace std;

int n, yes_cnt = 0, no_cnt = 0, tmp;

int main(void) {
	cin >> n;
	for (int i = 0; i < n;i++) {
		cin >> tmp;
		if (tmp == 0) no_cnt++;
		else yes_cnt++;
	}
	if (yes_cnt > no_cnt) printf("Junhee is cute!\n");
	else printf("Junhee is not cute!\n");
	return 0;
}
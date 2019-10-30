#include <iostream>
#include <algorithm>

using namespace std;
struct CNT {
	int zc = 0, oc = 0;
};

int t, n;
CNT arr[45];

int main(void) {
	cin >> t;
	arr[0].zc = 1; arr[0].oc = 0;
	arr[1].zc = 0; arr[1].oc = 1;
	for (int j = 2; j <= 40; j++) {
		arr[j].oc = arr[j - 1].oc + arr[j - 2].oc;
		arr[j].zc = arr[j - 1].zc + arr[j - 2].zc;
	}

	for (int i = 0; i < t; i++) {
		cin >> n;
		printf("%d %d\n", arr[n].zc, arr[n].oc);
	}
	return 0;
}
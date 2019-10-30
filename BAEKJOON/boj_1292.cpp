#include <iostream>

using namespace std;

int a, b, tmp_a, tmp_b;
int save_[60];
int arr[1005];

int main(void) {
	cin >> a >> b;
	int tmp = 1;
	for (int i = 1; i <= 60; i++) {
		if (a < tmp && tmp_a == 0) tmp_a = i - 1;
		if (b < tmp && tmp_b == 0) tmp_b = i - 1;
		save_[i] = tmp;
		tmp += i;
	}
	int ans = 0;
	for (int i = tmp_a; i <= tmp_b; i++) {
		if (i == tmp_a) {
			ans += (save_[tmp_a + 1] - a) * tmp_a;
		}
		else if (i == tmp_b) {
			ans += (save_[tmp_b] - b + 1) * tmp_b;
		}
		else {
			ans += i * i;
		}
	}

	int cnt = 0, cnt2 = 0;
	while (1) {
		cnt++;
		if (cnt2 > b) break;
		for (int j = 1; j <= cnt; j++) {
			if (cnt2 > b) break;
			cnt2++;
			arr[cnt2] = arr[cnt2 - 1] + cnt;
		}
	}
	printf("%d\n", arr[b] - arr[a - 1]);
	printf("%d\n", ans);



	return 0;
}
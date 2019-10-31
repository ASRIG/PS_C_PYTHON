#include <iostream>
#include <queue>
#define max(a, b) a < b ? b : a
using namespace std;

int n, calc_cnt;
long long answer;
bool arr[22];
int num_arr[22];
char str[22];

long long calc() {
	long long ret = str[0] - '0';
	
	for (int i = 0; i < calc_cnt; i++) {
		if (arr[i]) {
			int cur = 2 * i + 1;
			if (str[cur] == '+') {
				num_arr[i] = (str[cur - 1] - '0') + (str[cur + 1] - '0');
			}
			else if (str[cur] == '-') {
				num_arr[i] = (str[cur - 1] - '0') - (str[cur + 1] - '0');
			}
			else if (str[cur] == '*') {
				num_arr[i] = (str[cur - 1] - '0') * (str[cur + 1] - '0');
			}
		}
	}

	if (arr[0]) ret = num_arr[0];

	for (int i = 0; i < calc_cnt; i++) {
		if (arr[i]) continue;
		if (arr[i + 1]) {
			int cur = 2 * i + 1;
			if (str[cur] == '+') {
				ret += num_arr[i + 1];
			}
			else if (str[cur] == '-') {
				ret -= num_arr[i + 1];
			}
			else if (str[cur] == '*') {
				ret *= num_arr[i + 1];
			}
		}
		else {
			int cur = 2 * i + 1;
			if (str[cur] == '+') {
				ret += (str[cur + 1] - '0');
			}
			else if (str[cur] == '-') {
				ret -= (str[cur + 1] - '0');
			}
			else if (str[cur] == '*') {
				ret *= (str[cur + 1] - '0');
			}
		}
	}
	return ret;
}

void dfs(int idx, int cnt) {
	if (cnt <= calc_cnt) {
		long long tmp = calc();
		answer = max(answer, tmp);
		if (cnt == calc_cnt) return;
	}

	for (int i = idx; i < calc_cnt; i++) {
		// 먼저 계산 할꺼 정하기
		if (i != 0 && arr[i - 1]) continue;
		arr[i] = 1;
		dfs(i + 1, cnt);
		arr[i] = 0;
	}
}

int main(void) {
	int n;
	cin >> n;
	answer = -0x7fffffff;
	for(int i=0; i<n; i++) cin >> str[i];
	calc_cnt = n / 2;
	dfs(0, 0);

	printf("%lld\n", answer);
	return 0;
}
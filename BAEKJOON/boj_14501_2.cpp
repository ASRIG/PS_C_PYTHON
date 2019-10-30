#include <iostream>
#include <algorithm>
using namespace std;

int n, t[20], p[20];
int dp[20];

int cal(int day) {
	// 종료 조건
	if (day == n) return 0;
	else if (day > n) return -999999999;
	if (dp[day] != 0) return dp[day];
	dp[day] = max(cal(day + 1), cal(day + t[day]) + p[day]);
	return dp[day];
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) { 
		cin >> t[i] >> p[i]; dp[i] = 0;
	}
	int tmp = cal(0);
	printf("%d\n", tmp);
	return 0;
}
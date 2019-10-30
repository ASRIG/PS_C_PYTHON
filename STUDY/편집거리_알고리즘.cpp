#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

int dp[1001][1001];

int main(void) {
	string a, b;
	cin >> a >> b;

	a.insert(a.begin(), '0');
	b.insert(b.begin(), '0');

	int len1 = a.size(), len2 = b.size();

	for (int i = 0; i < len1; ++i) dp[i][0] = i;
	for (int i = 0; i < len2; ++i) dp[0][i] = i;

	for (int i = 1; i < len1; ++i) {
		for (int j = 1; j < len2; ++j) {
			if (a[i] == b[j])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = min({ dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j] }) + 1;
		}
	}
	printf("%d\n", dp[len1 - 1][len2 - 1]);
	return 0;
}
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAXN 1005

char a[MAXN], b[MAXN];
int d[MAXN][MAXN];
int len_a, len_b;

int main(void) {
	cin >> a + 1; cin >> b + 1;
	len_a = strlen(a + 1); len_b = strlen(b + 1);
	for (int i = 1; i <= len_a; i++) {
		for (int j = 1; j <= len_b; j++) {
			if (d[i - 1][j] > d[i][j - 1]) d[i][j] = d[i - 1][j];
			else d[i][j] = d[i][j - 1];

			if (a[i] == b[j] && d[i][j] < d[i-1][j-1] + 1) 
				d[i][j] = d[i-1][j-1] +1;
		}
	}

	printf("%d\n", d[len_a][len_b]);
	return 0;
}

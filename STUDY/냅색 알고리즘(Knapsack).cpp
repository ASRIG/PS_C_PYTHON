/*
	jw :: 보석의 무게
	jp :: 보석의 가격
	보석이 무한대로 있을 때 150kg 까지 가방에 담을 수 있을때
	얻을 수 있는 최대 가치는?
*/

#include <iostream>

#define MAXW 101
#define MAXN 31
#define max(a, b) (a > b ? a : b);
int dp1[MAXN];

int n, w;
int jWeight[MAXN] = { 0, 2, 4, 7, 3 };
int jPrice[MAXN] = { 0, 10, 40, 30, 50 };

void knapsack1() {	// 보석이 무한대
	for (int i = 1; i <= w; i++)	// 가방
		for (int j = 1; j <= n; j++)	// 보석
			if (jWeight[j] <= i)	// 가방에 보석을 넣을 공간이 존재한다면
				dp1[i] = max(dp1[i], dp1[i - jWeight[j]] + jPrice[j]);
}

int dp2[MAXN][MAXN];
void knapsack2() {	// 보석이 1개
	for (int i = 1; i <= n; i++)	// 보석
		for (int j = jWeight[i]; j <= w; j++)	// 가방, 어짜피 보석보다 큰 가방부터
			dp2[i][j] = max(dp2[i - 1][j], dp2[i - 1][j - jWeight[i]] + jPrice[i]);
}

int dp3[2][MAXN];
void knapsack3() {	// 보석이 1개
	for(int i=1; i<=n;i++)	// 보석
		for (int j = jWeight[i]; j <= w; j++) {
			dp3[i & 1][j] = max(dp3[(i - 1) & 1][j], dp3[(i - 1) & 1][j - jWeight[i]] + jPrice[i]);
		}
}

int main() {
	n = 4; w = 10;
	knapsack1(); knapsack2(); knapsack3();
	printf("max :: %d\n", dp1[w]);
	printf("max :: %d\n", dp2[n][w]);
	printf("max :: %d\n", dp3[n&1][w]);
	return 0;
}
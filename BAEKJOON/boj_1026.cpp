#include <iostream>
#include <algorithm>

using namespace std;

int N, a[55], b[55];

bool comp(int &a1, int &a2) {
	return a1 > a2;
}

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N;i++) scanf("%d", &a[i]);
	for (int i = 0; i < N; i++) scanf("%d", &b[i]);
	sort(a, a + N); sort(b, b + N, comp);
	int answer = 0;
	for (int i = 0; i < N; i++) answer += a[i] * b[i];
	printf("%d\n", answer);
	
	return 0;
}
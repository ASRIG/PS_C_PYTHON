#include <iostream>

using namespace std;

int N, A[1000000];
int B, C;
long long answer = 0;

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cin >> B >> C;
	
	for (int i = 0; i < N; i++) {
		int tmp = A[i];
		tmp -= B; answer++;
		if (tmp <= 0) continue;
		else {
			answer += tmp / C; tmp %= C;
			if (tmp == 0) continue;
			else {
				answer++;
			}
		}

	}
	printf("%lld\n", answer);
	return 0;
}
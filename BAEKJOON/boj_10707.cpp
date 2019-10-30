#include <iostream>

using namespace std;

int a, b, c, d, p;
int answer_a, answer_b;

int main(void) {
	cin >> a >> b >> c >> d >> p;
	answer_a += a * p;
	if(p > c) answer_b += b + d * (p - c);
	else answer_b = b;
	if (answer_a < answer_b) printf("%d\n", answer_a);
	else printf("%d\n", answer_b);
	return 0;
}
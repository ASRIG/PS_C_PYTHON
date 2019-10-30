#include <iostream>

using namespace std;

int t, a, t2, answer_2;
float b, answer_sum;

int main(void) {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> t2; 
		answer_sum = 0; answer_2 = 0;
		for (int j = 0; j < t2; j++) {
			cin >> a >> b;
			answer_sum += a * b; answer_2 += a;
		}
		printf("%d %.1f\n", answer_2, answer_sum / answer_2);
	}
	
	return 0;
}
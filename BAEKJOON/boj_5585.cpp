#include <iostream>

using namespace std;

int mon, answer;

int main(void) {
	cin >> mon;
	mon = 1000 - mon;
	answer += mon / 500; mon %= 500;
	answer += mon / 100; mon %= 100;
	answer += mon / 50; mon %= 50;
	answer += mon / 10; mon %= 10;
	answer += mon / 5; mon %= 5;
	answer += mon / 1; mon %= 1;
	
	printf("%d\n", answer);
	
	return 0;
}
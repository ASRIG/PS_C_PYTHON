#include <iostream>

using namespace std;


int main(void) {
	int year_, ans = 0;
	cin >> year_; 
	if (year_ % 4 == 0) {
		if (year_ % 400 == 0) ans = 1;
		else if (year_ % 100 == 0) ans = 0;
		else ans = 1;
	}
	printf("%d\n", ans);
	return 0;
}
#include <iostream>

using namespace std;

int a, b, c;

int main(void) {
	cin >> a >> b >> c;
	if (a == 60 && a == b && b == c) printf("Equilateral\n");
	else if (a + b + c == 180 && (a == b || a == c || b == c)) printf("Isosceles\n");
	else if (a + b + c == 180 && (a != b && b != c && a != c)) printf("Scalene\n");
	else if (a + b + c != 180) printf("Error\n");
	return 0;
}
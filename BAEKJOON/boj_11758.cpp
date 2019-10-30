#include <iostream>
#include <algorithm>

using namespace std;

int ax, ay, bx, by, cx, cy;

int main(void) {
	cin >> ax >> ay >> bx >> by >> cx >> cy;
	int answer = (bx - ax) * (cy - ay) - (cx - ax) * (by - ay);
	
	if (answer > 0) printf("1");
	else if (answer < 0) { cout << answer << endl; printf("-1"); }
	else { cout << answer << endl; printf("0"); }
	printf("\n");
	return 0;
}
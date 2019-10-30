#include <iostream>

using namespace std;

void call_by_value(int a) {
	a += 100;
}

void call_by_ref(int &a) {
	a += 100;
}

void call_by_ref2(int *a) {
	*a += 100;
}

int main(void) {
	int a = 100;
	printf("�ʱⰪ : %d\n", a);
	call_by_value(a);	
	printf("val : %d\n", a);
	call_by_ref(a);
	printf("ref : %d\n", a);
	call_by_ref2(&a);
	printf("ref2 : %d\n", a);

	return 0;
}
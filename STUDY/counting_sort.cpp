#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int temp, count[6];
	int arr[30] = { 1, 3, 2,4,3,2,5,3,1,2,
	3,4,4,3,5,1,2,3,5,2,3,1,4,3,5,1,2,1,1,1 };
	for (int i = 1; i <= 5; i++) {
		count[i] = 0;
	}
	for (int i = 0; i < 30; i++)count[arr[i]]++;
	for (int i = 1; i <= 5; i++) {
		if (count[i] != 0) {
			for (int j = 0; j < count[i]; j++)printf("%d ", i);
		}
	}
	printf("\n");
	return 0;
}
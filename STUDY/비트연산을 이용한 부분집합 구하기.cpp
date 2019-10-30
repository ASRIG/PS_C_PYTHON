/*
	모든 부분집합을 찾아내는 알고리즘
*/

#include <iostream>

using namespace std;

char arr[] = { 'a', 'b', 'c' };
int n;

void findSubset() {
	for (int i = 0; i < (1 << n); i++) {
		printf("{");
		for (int j = 0; j < n; j++) {
			
			if (i & (1 << j)) {
				printf("%c ", arr[j]);
			}
		}printf("}\n");
	}
}

int main(void) {
	n = sizeof(arr) / sizeof(char);
	printf("n :: %d\n", n);
	findSubset();
	return 0;
}

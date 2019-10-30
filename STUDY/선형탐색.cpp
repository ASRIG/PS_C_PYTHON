#include <iostream>
#include <algorithm>

using namespace std;

int LSearch(int ar[], int len, int target) {
	int i;
	for (i = 0; i < len; i++) {
		if (ar[i] == target) return i;
	}
	return -1;
}
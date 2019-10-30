#include <iostream>
#include <algorithm>

using namespace std;

int arr[10] = { 1, 2, 3, 5, 6, 7, 8, 9, 10, 11 };
int start_, end_, mid_;

int main(void) {
	start_ = 0; end_ = 9;
	int target = 10;
	while (start_ <= end_) {
		mid_ = (start_ + end_) / 2;
		if (target == arr[mid_]) { printf("%d\n", mid_); break; }
		else {
			if (target < arr[mid_]) end_ = mid_ - 1;
			else start_ = mid_ + 1;
		}
	}

	return 0;
}
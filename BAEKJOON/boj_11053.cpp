#include <iostream>
#include <algorithm>

using namespace std;

int N, i, j;
int answer, count_, temp;
int arr[1005];
int start, end_, mid;

int main(void) {
	cin >> N;

	count_ = 1;
	for (int i = 1; i <= N; i++) {
		cin >> temp;
		if (i == 1) arr[i] = temp;
		else {
			if (arr[count_] < temp) {
				count_++; arr[count_] = temp;
			}
			else {
				start = 1; end_ = count_;
				while (end_ - start >= 0) {
					mid = (start + end_) / 2;
					if (temp <= arr[mid] && temp > arr[mid - 1]) {
						arr[mid] = temp; break;
					}
					else if (temp < arr[mid]) {
						end_ = mid - 1;
					}
					else {
						start = mid + 1;
					}
				}
			}
		}
	}

	printf("%d\n", count_);

	return 0;
}
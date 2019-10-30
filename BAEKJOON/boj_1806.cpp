#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n, i, answer;
long s, sum;
int arr[100005];
int start_, end_, length_;

int main(void) {
	cin >> n >> s;
	start_ = end_ = 1; sum = 0;
	length_ = 0; answer = 100005;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	
	for (i = 1; i <= 2 * n + 1; i++) {
		//printf("start : %d, end : %d\n", start_, end_);
		if (sum < s) {
			if (end_ > n) break;
			sum += arr[end_++];
			length_++;
		}
		else {
			if (answer > length_) answer = length_;
			sum -= arr[start_++]; length_--;
		}
	}

	if (answer == 100005) answer = 0;
	printf("%d\n", answer);


	return 0;
}
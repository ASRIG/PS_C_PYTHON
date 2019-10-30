#include <iostream>
#include <algorithm>

using namespace std;

int N, M, a[100005], b[100005];

bool comp(int aa, int bb) {
	return aa < bb;
}

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	cin >> M;
	for (int j = 0; j < M;j++) {
		cin >> b[j];
	}
	
	int start_ = 0, end_ = N - 1, mid_;
	
	sort(a, a + N, comp);

	for (int i = 0; i < M; i++) {
		int target = b[i]; 
		start_ = 0; end_ = N - 1;
		bool find_sw = false;

		while (start_ <= end_) {
			mid_ = (start_ + end_) / 2;
			if (a[mid_] == target) {
				printf("1\n"); find_sw = true;
				break;
			}
			else if (a[mid_] > target) end_ = mid_ - 1;
			else start_ = mid_ + 1;
		}
		if (find_sw == false) printf("0\n");
	}
	


	return 0;
}
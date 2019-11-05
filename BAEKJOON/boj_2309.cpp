#include <iostream>

using namespace std;

int arr[10], pick_[10], idx1, idx2, answer[8];
bool find_sw = false;

void swap(int &num1, int &num2) {
	int tmp = num1; num1 = num2; num2 = tmp;
}

void qsort(int start_, int end_) {
	if (start_ == end_) return;
	int mid_ = (start_ + end_) / 2;
	swap(arr[start_], arr[mid_]);
	
	int pivot = start_;
	int left = start_ + 1, right = end_ - 1;


	while (left <= right) {
		while (left <= right && arr[left] <= arr[pivot]) left++;
		while (left <= right && arr[right] >= arr[pivot]) right--;
		if (left <= right) {
			swap(arr[left], arr[right]);
		}
	}
	swap(arr[pivot], arr[right]);
	qsort(start_, right);
	qsort(right + 1, end_);
}

void dfs(int idx, int cnt) {
	if (find_sw) return;
	if (cnt == 2) {
		int tmp = 0;
		for (int i = 0; i < 9; i++) tmp += pick_[i] * arr[i];
		if (tmp == 100) {
			find_sw = true;
			int ia = 0;
			for (int i = 0; i < 9; i++) {
				if (pick_[i] == 1) answer[ia++] = arr[i];
			}
			return;
		}
		return;
	}
	
	for (int i = idx; i < 9; i++) {
		pick_[i] = 0;
		dfs(i + 1, cnt + 1);
		pick_[i] = 1;
	}
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(nullptr);
	for (int i = 0; i < 9; i++) cin >> arr[i];
	for (int i = 0; i < 9; i++) pick_[i] = 1;
	qsort(0, 9);
	dfs(0, 0);
	for (int i = 0; i < 7; i++) {
		printf("%d\n", answer[i]);
	}
	return 0;
}
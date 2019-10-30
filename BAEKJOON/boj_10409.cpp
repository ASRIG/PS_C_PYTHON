#include <iostream>

using namespace std;

typedef struct queue{
	int* Data;
	int first, end_, capacity;

	queue(int size = 50) {
		Data = new int[size];
		first = end_ = 0; capacity = size;
	}

	void pop() {
		first++;
	}
	
	bool empty() {
		return first == end_;
	}

	int front() {
		return Data[first];
	}

	int rear() {
		return Data[end_];
	}

	int size() {
		return end_ - first;
	}

	void push(const int& data) {
		Data[end_++] = data;
	}

};

queue qq;
int n, T, tmp;

int main(void) {
	cin >> n >> T;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		qq.push(tmp);
	}
	int answer = 0;
	while (!qq.empty()) {
		int tmpp = qq.front(); qq.pop();
		if (T - tmpp < 0) break;
		T -= tmpp; answer++;
	}
	printf("%d\n", answer);
	return 0;
}
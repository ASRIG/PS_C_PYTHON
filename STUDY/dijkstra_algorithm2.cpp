#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int number = 6;
const int INF = 10000000;

vector<pair<int, int>> a[7]; // 간선 정보
int d[7]; // 최소 비용

void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int>> pq; // 힙 구조입니다.
	pq.push(make_pair(0, start));
	// 가까운 순서대로 처리하므로 큐 사용
	while (!pq.empty()) {
		int distance = -pq.top().first;
		int current = pq.top().second;
		pq.pop();
		if (d[current] < distance) continue;
		for (int i = 0; i < a[current].size(); i++) {
			int next = a[current][i].first;
			int next_distance = distance + a[current][i].second;
			if (next_distance < d[next]) {
				d[next] = next_distance;
				pq.push(make_pair(-next_distance, next));
			}
		}
	}
}

int main(void) {
	for (int i = 1; i <= number; i++) {
		d[i] = INF;
	}
	a[1].push_back(make_pair(2, 2));
	a[1].push_back(make_pair(3, 5));
	a[1].push_back(make_pair(4, 1));

	a[2].push_back(make_pair(1, 2));
	a[2].push_back(make_pair(3, 3));
	a[2].push_back(make_pair(4, 2));

	a[3].push_back(make_pair(1, 5));
	a[3].push_back(make_pair(2, 3));
	a[3].push_back(make_pair(4, 3));
	a[3].push_back(make_pair(5, 1));
	a[3].push_back(make_pair(6, 5));

	a[4].push_back(make_pair(1, 1));
	a[4].push_back(make_pair(2, 2));
	a[4].push_back(make_pair(3, 3));
	a[4].push_back(make_pair(5, 1));

	a[5].push_back(make_pair(3, 1));
	a[5].push_back(make_pair(4, 1));
	a[5].push_back(make_pair(6, 2));

	a[6].push_back(make_pair(3, 5));
	a[6].push_back(make_pair(5, 2));

	dijkstra(1);
	for (int i = 1; i <= number; i++) {
		printf("%d ", d[i]);
	} printf("\n");
}

#include <iostream>
#include <algorithm>

using namespace std;

int start_hour[3], end_hour[3], start_min[3], end_min[3];
int start_sec[3], end_sec[3], h, m, s;

int main(void) {
	for (int i = 0; i < 3; i++) {
		cin >> start_hour[i] >> start_min[i] >> start_sec[i];
		cin >> end_hour[i] >> end_min[i] >> end_sec[i];
	}
	for (int i = 0; i < 3; i++) {
		s = end_sec[i] - start_sec[i];
		if (s < 0) {
			s += 60; end_min[i]--;
		}
		m = end_min[i] - start_min[i];
		if (m < 0) {
			m += 60; end_hour[i]--;
		}
		h = end_hour[i] - start_hour[i];
		printf("%d %d %d\n", h, m, s);
	}
	return 0;
}
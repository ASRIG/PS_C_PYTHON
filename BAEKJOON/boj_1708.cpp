#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>

#define MAXN 100005
#define sz(v) ((int)(v).size())
typedef long long lld;

using namespace std;

int T, N;

int ccw(int ax, int ay, int bx, int by, int cx, int cy) {
	lld k = (lld)(bx - ax) * (cy - ay) - (lld)(cx - ax)*(by - ay);
	if (k > 0) return 1;
	if (k) return -1;
	return 0;
}

struct Z {
	int x, y;
	bool operator < (const Z &ot) const {
		int k = ccw(0, 0, x, y, ot.x, ot.y);
		if (k) return k > 0;
		return abs(x) + y < abs(ot.x) + ot.y;
	}
}A[MAXN];

int ccw(const Z &a, const Z &b, const Z &c) {
	return ccw(a.x, a.y, b.x, b.y, c.x, c.y);
}

int main(void) {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i].x >> A[i].y;
	for (int i = 2; i <= N; i++) {
		if (A[1].y > A[i].y || A[1].y == A[i].y && A[1].x > A[i].x)
			swap(A[1], A[i]);
	}
	for (int i = N; i > 0; i--) A[i].x -= A[1].x, A[i].y -= A[1].y;
	sort(A + 2, A + N + 1);


	return 0;
}
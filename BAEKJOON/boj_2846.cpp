#include <iostream>
#define max(a, b) a < b ? b : a

using namespace std;

int n, tmp, answer = 0, cnt = 0;

int main(void) {
	cin >> n;
	cin >> tmp;
	int tmpp = tmp; int cur_x = tmp;

	for (int i = 2; i <= n + 1; i++) {
		if(i <= n) cin >> tmp;
		if (tmp - tmpp <= 0){
			//printf("%d %d %d \n", tmp, tmpp, cur_x);
			answer = max(answer, tmpp - cur_x);
			
			cur_x = tmp;
		}
		tmpp = tmp;
	}
	printf("%d\n", answer);
	return 0;
}
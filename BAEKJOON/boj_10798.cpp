#include <iostream>
#define max(a, b) a < b ? b : a
using namespace std;

int tmp = 0, max_line = 0;
char a[5][16];

int main(void) {
	for (int i = 0; i < 5; i++) {
		cin >> a[i];
		cout << (int)strlen(a[i]) << endl;
	}
	

	while (tmp < 15){
		for (int i = 0; i < 5; i++) {
			if(a[i][tmp] != '\0') printf("%c", a[i][tmp]);
		}
		tmp++;
	}	printf("\n");
	return 0;
}
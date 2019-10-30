#include <iostream>
#define INF 999900
using namespace std;

int v, e, a, b, c;
int m[405][405];

int min(int a, int b) {
	if (a < b) return a;
	else return b;
}


int main(void) {
	cin >> v >> e;

	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			m[i][j] = INF;
		}
	}

	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		m[a][b] = c;
	}

	for (int k = 1; k <= v; k++)
		for (int i = 1; i <= v; i++)
			for (int j = 1; j <= v; j++)
				m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
		

	int answer = INF;
	for (int i = 1; i <= v; i++) {
		answer = min(answer, m[i][i]);
	}
	
	if (answer == INF) printf("-1\n");
	else printf("%d\n", answer);
	return 0;
}
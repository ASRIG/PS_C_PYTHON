#include <iostream>

using namespace std;

int n, x, y, d, g, map[103][103];
int cmd[20][1050], cmd_cnt = 0;

const int dx[] = { 0, -1, 0, 1 };
const int dy[] = { 1, 0, -1, 0 };

void view_() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			printf("%d ", map[i][j]);
		}printf("\n");
	}
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> d >> g;
		int tmp = x; x = y; y = tmp;

		// 0세대
		map[x][y] = 1;
		int new_x = x + dx[d], new_y = y + dy[d];
		map[new_x][new_y] = 1; 
		cmd[i][0] = d; cmd_cnt = 1;

		for (int tim = 1; tim <= g; tim++) {
			for (int ia = cmd_cnt - 1; ia >= 0; ia--) {
				int cmdt = (cmd[i][ia] + 1) % 4;
				//printf("prev -> new_x : %d,  new_y : %d\n", new_x, new_y);
				//printf("prev -> cmd[i][ia] : %d,  cmdt : %d\n", cmd[i][ia], cmdt);
				new_x += dx[cmdt]; new_y += dy[cmdt];
				//printf("next -> new_x : %d,  new_y : %d\n", new_x, new_y);

				if (new_x < 0 || new_x > 100 || new_y < 0 || new_y > 100) continue;
				map[new_x][new_y] = 1;
				cmd[i][cmd_cnt++] = cmdt;
			}
			//printf("[드래곤 커브 완성]\n");
			//view_();
		}	
		//printf("[드래곤 커브 완성]\n");
		//view_();
	}

	int answer = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j] == 1 && map[i + 1][j + 1] == 1) answer++;
		}
	}
	printf("%d\n", answer);

	return 0;
}
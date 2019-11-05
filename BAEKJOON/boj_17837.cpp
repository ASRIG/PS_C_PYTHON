#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

struct DRON {
	int x, y, dir;
};

int n, k, map[13][13];
vector<int> dron_map[13][13];
const int dx[] = { 0, 0, 0, -1, 1 };
const int dy[] = { 0, 1, -1, 0, 0 };
const int change_[] = { 0, 2, 1, 4, 3 };
DRON dron[11];

int move_(int cur) {
	// 파랑색, 끝 부분 처리
	int new_x = dron[cur].x + dx[dron[cur].dir], new_y = dron[cur].y + dy[dron[cur].dir];
	if ((new_x < 1 || new_x > n || new_y < 1 || new_y > n) || map[new_x][new_y] == 2) {
		dron[cur].dir = change_[dron[cur].dir];
		new_x = dron[cur].x + dx[dron[cur].dir], new_y = dron[cur].y + dy[dron[cur].dir];
		if ((new_x < 1 || new_x > n || new_y < 1 || new_y > n) || map[new_x][new_y] == 2) return 0;
	}

	
	vector<int> &cur_v = dron_map[dron[cur].x][dron[cur].y];
	vector<int> &nxt_v = dron_map[new_x][new_y];
	auto s = find(cur_v.begin(), cur_v.end(), cur);
	if (map[new_x][new_y] == 1) {
		// 빨강색 처리
		reverse(s, cur_v.end());
	}

	// 이동하기
	for (auto i = s; i != cur_v.end(); i++) {
		dron[*i].x = new_x; dron[*i].y = new_y;
		nxt_v.push_back(*i);
	}
	cur_v.erase(s, cur_v.end());
	return nxt_v.size();
}

int game_start() {
	for (int time_ = 1; time_ <= 1000; time_++) {
		for (int drone_idx = 1; drone_idx <= k; drone_idx++) {
			// 이동
			int tmp_cnt = move_(drone_idx);
			// 말이 4개이상 쌓이면 종료
			if (tmp_cnt >= 4) return time_;
			
		}

	}
	return -1;
}


int main(void) {
	ios::sync_with_stdio(0); cin.tie(nullptr);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];

	for (int i = 1; i <= k; i++) {
		cin >> dron[i].x >> dron[i].y >> dron[i].dir;
		dron_map[dron[i].x][dron[i].y].push_back(i);
	}

	cout << game_start() << endl;

	return 0;
}
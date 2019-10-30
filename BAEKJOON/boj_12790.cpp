#include <iostream>
#define set_item(a) a < 1 ? 1 : a
#define set_item2(a) a < 0 ? 0 : a

using namespace std;

int T, hp, mp, atk, dfs, e_hp, e_mp, e_atk, e_dfs;

int main(void) {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> hp >> mp >> atk >> dfs >> e_hp >> e_mp >> e_atk >> e_dfs;
		int final_hp = hp + e_hp; final_hp = set_item(final_hp);
		int final_mp = mp + e_mp; final_mp = set_item(final_mp);
		int final_atk = atk + e_atk; final_atk = set_item2(final_atk);
		int final_dfs = dfs + e_dfs;
		int damage = final_hp + (5 * final_mp) + 2 * final_atk + 2 * final_dfs;
		printf("%d\n", damage);
	}
	return 0;
}
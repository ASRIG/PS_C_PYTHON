#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

typedef pair<int, int> pii;

int n, m;
pii arr[10];

map<pii, int> visit;
map<vector<int>, int> mp;
vector<int> vc;

void dfs(int cnt)
{
	if (vc.size() == m && !mp.count(vc))
	{
		mp[vc] = 1;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (vc.size() < m)
		{
			if (!visit[arr[i]])
			{
				vc.push_back(arr[i].first);
				visit[arr[i]] = true;
				dfs(i + 1);
				visit[arr[i]] = false;
				vc.pop_back();
			}
		}
	}
}
int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		int val;
		scanf("%d", &val);

		arr[i] = { val, i };
	}
	sort(arr, arr + n);
	dfs(0);

	for (auto it = mp.begin(); it != mp.end(); it++)
	{
		for (auto i : it->first)
			printf("%d ", i);
		printf("\n");
	}
	return 0;
}

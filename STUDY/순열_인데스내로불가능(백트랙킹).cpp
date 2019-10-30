#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n, m;
int arr[10];
unordered_map<int, int> visit;
vector<int> vc;

void dfs(int cnt)
{
	if (vc.size() == m)
	{
		for (auto i : vc)
			printf("%d ", i);
		printf("\n");
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (vc.size() < m)
		{
			if (!visit[arr[i]])
			{
				vc.push_back(arr[i]);
				visit[arr[i]] = 1;
				dfs(i + 1);
				visit[arr[i]] = 0;
				vc.pop_back();
			}
		}
	}
}
int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	dfs(0);
	return 0;
}


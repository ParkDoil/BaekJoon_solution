#define _CRT_SECURE_NO_WARNINGS
#include <stack>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int map[25][25];
bool isVisited[25][25] = { false };
int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0 , -1, 0 };

int dfs(int x, int y, int N)
{
	isVisited[x][y] = true;

	int houseCount = 1;
	for (int i = 0; i < 4; ++i)
	{
		int gx = x + dx[i];
		int gy = y + dy[i];
		
		if (gx < 0 || gx >= N || gy < 0 || gy >= N)
		{
			continue;
		}
		else
		{
			if (isVisited[gx][gy] == false && map[gx][gy] == 1)
			{
				houseCount += dfs(gx, gy, N);
			}
		}
	}

	return houseCount;
}

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	int complexCount = 0;
	vector<int> houseCounts;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (map[i][j] == 1 && false == isVisited[i][j])
			{
				int houseCount = dfs(i, j, N);
				houseCounts.push_back(houseCount);
				++complexCount;
			}
		}
	}

	sort(houseCounts.begin(), houseCounts.end());

	printf("%d\n", complexCount);

	for (int i = 0; i < houseCounts.size(); ++i)
	{
		printf("%d\n", houseCounts[i]);
	}
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int estate = 0;
int graph[25][25];
bool isVisited[25][25] = { false };
int px[] = { -1, 0, 1, 0 }, py[] = { 0, 1, 0, -1 };

void dfs(int x, int y, int N)
{
	++estate;
	isVisited[x][y] = true;
	for (int i = 0; i < 4; ++i)
	{
		int gx = x + px[i], gy = y + py[i];

		if (gx < 0 || gy < 0 || gx >= N || gy >= N)
		{
			continue;
		}

		if (graph[gx][gy] == 1 && false == isVisited[gx][gy])
		{
			dfs(gx, gy, N);
		}
	}

}

int main()
{
	int N;
	cin >> N;
	
	vector<int> result;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			scanf("%1d", &graph[i][j]);
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (graph[i][j] == 1 && false == isVisited[i][j])
			{
				estate = 0;
				
				dfs(i, j, N);

				result.push_back(estate);
			}
		}
	}

	sort(result.begin(), result.end());

	cout << result.size() << "\n";

	for (size_t i = 0; i < result.size(); ++i)
	{
		cout << result[i] << "\n";
	}

	return 0;
}
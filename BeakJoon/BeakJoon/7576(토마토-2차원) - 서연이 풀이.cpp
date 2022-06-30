#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int moon, N;

enum { EMPTY = -1, TOMATO, LIPEND };

int box[1000][1000];

queue <pair<int, int>> Tomato;

int result = 0;
int notLipCount;

void bfs()
{
	while (false == Tomato.empty())
	{
		static const int dr[] = { 1, -1, 0, 0 };
		static const int dc[] = { 0, 0, 1, -1 };

		int tr = Tomato.front().first;
		int tc = Tomato.front().second;

		Tomato.pop();

		for (int i = 0; i < 4; ++i)
		{
			int gr = tr + dr[i];
			int gc = tc + dc[i];

			if (gr < 0 || gr >= N || gc < 0 || gc >= moon)
			{
				continue;
			}

			else
			{
				if (box[gr][gc] == 0)
				{
					box[gr][gc] = box[tr][tc] + 1;
					Tomato.push({ gr, gc });
					--notLipCount;

					if (box[gr][gc] > result)
					{
						result = box[gr][gc] - 1;
					}
				}
			}

		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 1. M, N을 입력 받는다.
	// M : 가로, N : 세로
	cin >> moon >> N;

	notLipCount = moon * N;
	// 2. 토마토 상자의 정보를 입력 받는다.
	for (int r = 0; r < N; ++r)
	{
		for (int c = 0; c < moon; ++c)
		{
			cin >> box[r][c];

			if (box[r][c] == 1)
			{
				Tomato.push({ r, c });
			}

			if (box[r][c] == -1 || box[r][c] == 1)
			{
				--notLipCount;
			}
		}
	}

	bfs();

	if (notLipCount != 0)
	{
		cout << "-1\n";
	}
	else
	{
		cout << result << "\n";
	}

	return 0;
}
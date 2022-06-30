#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int testCase, chessI;
int knightR, knightC;
int destinationR, destinationC;

int chessBoard[300][300];
int moveCount;
bool isVisited[300][300];

void bfs(int kr, int kc)
{
	isVisited[kr][kc] = true;
	chessBoard[kr][kc] = moveCount;

	queue<pair<int, int>> Chess;
	Chess.push({ kr, kc });

	while (false == Chess.empty())
	{
		static const int dr[] = { 1, 1, -1, -1, 2, 2, -2, -2 };
		static const int dc[] = { 2, -2, 2, -2, 1, -1, 1, -1 };

		int tr = Chess.front().first;
		int tc = Chess.front().second;

		Chess.pop();

		if (tr == destinationR && tc == destinationC)
		{
			cout << chessBoard[tr][tc] << "\n";
		}
		
		for (int i = 0; i < 8; ++i)
		{
			int gr = tr + dr[i];
			int gc = tc + dc[i];

			if (gr < 0 || gr >= chessI || gc < 0 || gc >= chessI)
			{
				continue;
			}
			else
			{
				if (false == isVisited[gr][gc])
				{
					isVisited[gr][gc] = true;
					Chess.push({ gr, gc });
					chessBoard[gr][gc] = chessBoard[tr][tc] + 1;
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

	cin >> testCase;

	for (int i = 0; i < testCase; ++i)
	{
		memset(chessBoard, 0, sizeof(chessBoard));
		memset(isVisited, false, sizeof(isVisited));
		moveCount = 0;

		cin >> chessI;
		cin >> knightR >> knightC;
		cin >> destinationR >> destinationC;

		bfs(knightR, knightC);

		cout << "\n";
		for (int r = 0; r < chessI; ++r)
		{
			for (int c = 0; c < chessI; ++c)
			{
				cout << chessBoard[r][c] << "  ";
			}
			cout << "\n";
			cout << "\n";
		}

	}

	return 0;
}
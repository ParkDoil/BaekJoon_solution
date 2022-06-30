#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

vector<int> computer[101];

bool isVisited[101];

int bfs()
{
	int infectionCount = 0;
	// 2. BFS�� ����� ť ����
	queue<int> q;
	q.push(1);
	isVisited[1] = true;

	// 3. ���̻� �湮�� ������ ���� �� ���� �湮
	while (false == q.empty()) // ������ ����ִٸ� ��� ������ �湮�� ��
	{
		// 3-1. ������ �湮
		int node = q.front();
		q.pop();


		// 3-2. �������� �湮�� ������ ã�´�.
		for (size_t i = 0; i < computer[node].size(); ++i)
		{
			int nextnode = computer[node][i];

			if (false == isVisited[nextnode])
			{
				q.push(nextnode);
				isVisited[nextnode] = true;
				++infectionCount;
			}
		}
	}
	
	return infectionCount;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// ��ǻ���� �� = ������ ����
	int C;
	cin >> C;

	// ��Ʈ��ũ�� �� = ������ ����
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int start, end;
		cin >> start >> end;
		computer[start].push_back(end);
		computer[end].push_back(start);
	}

	int virusComputer = 0;

	virusComputer = bfs();


	cout << virusComputer << "\n";

	return 0;
}
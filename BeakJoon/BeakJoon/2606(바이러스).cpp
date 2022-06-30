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
	// 2. BFS에 사용할 큐 생성
	queue<int> q;
	q.push(1);
	isVisited[1] = true;

	// 3. 더이상 방문할 정점이 없을 때 까지 방문
	while (false == q.empty()) // 스택이 비어있다면 모든 정점을 방문한 것
	{
		// 3-1. 정점을 방문
		int node = q.front();
		q.pop();


		// 3-2. 다음으로 방문할 정점을 찾는다.
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

	// 컴퓨터의 수 = 정점의 개수
	int C;
	cin >> C;

	// 네트워크의 수 = 간선의 개수
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
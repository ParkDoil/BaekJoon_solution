#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<int> graph[100'001];
bool isVisited[100'001] = { false };
int order[100'001] = { 0 };
int o = 1;

void bfs(int R)
{
	queue<int> q;
	q.push(R);
	isVisited[R] = true;

	while (false == q.empty())
	{
		int node = q.front();
		q.pop();

		order[node] = o;
		++o;

		for (size_t i = 0; i < graph[node].size(); ++i)
		{
			int nextnode = graph[node][i];

			if (false == isVisited[nextnode])
			{
				q.push(nextnode);
				isVisited[nextnode] = true;

			}
		}
	}

}

int main()
{
	int N, M, R;
	cin >> N >> M >> R;

	for (int i = 0; i < M; ++i)
	{
		int start, end;
		cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}

	for (size_t i = 1; i <= N; ++i)
	{
		sort(graph[i].begin(), graph[i].end(), greater<int>());
	}

	bfs(R);

	for (int i = 1; i <= N; ++i)
	{
		cout << order[i] << "\n";
	}

	return 0;
}
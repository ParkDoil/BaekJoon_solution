#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> graph[1001];
bool isVisited[1001];


void dfs(int V)
{
	isVisited[V] = true;
	cout << V << " ";

	for (size_t i = 0; i < graph[V].size(); ++i)
	{
		int nextnode = graph[V][i];

		if (false == isVisited[nextnode])
		{
			dfs(nextnode);
		}
	}
	//// 2. DFS�� ����� ������ �����
	//stack<int> st; // ������ �湮�� ������ ����

	//st.push(V); // ù��°�� �湮�� ����
	//isVisited[V] = true;


	//// 3. ���̻� �湮�� ������ ���� �� ���� �湮
	//while (false == st.empty()) // ������ ����ִٸ� ��� ������ �湮�� ��
	//{
	//	// 3-1. ������ �湮
	//	int node = st.top();
	//	st.pop();

	//	cout << node << ' ';
	//	
	//	

	//	// 3-2. �������� �湮�� ������ ã�´�.
	//	for (int i = 0; i < graph[node].size(); ++i)
	//	{
	//		int nextnode = graph[node][i];

	//		if (false == isVisited[nextnode])
	//		{
	//			st.push(nextnode);
	//			isVisited[nextnode] = true;
	//		}
	//	}
	//}
}

void bfs(int V)
{
	// 2. BFS�� ����� ť ����
	queue<int> q;
	q.push(V);
	isVisited[V] = true;

	// 3. ���̻� �湮�� ������ ���� �� ���� �湮
	while (false == q.empty()) // ������ ����ִٸ� ��� ������ �湮�� ��
	{
		// 3-1. ������ �湮
		int node = q.front();
		q.pop();

		cout << node << " ";


		// 3-2. �������� �湮�� ������ ã�´�.
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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M, V;
	cin >> N >> M >> V;
	
	// 1. �׷��� ����
	for (int i = 0; i < M; ++i)
	{
		int s, e;
		cin >> s >> e;

		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	// 2. ���� �������� �湮 ��Ű�� ���� ����
	for (int i = 1; i <= M; ++i)
	{
		std::sort(graph[i].begin(), graph[i].end());
	}

	// 3. DFS
	dfs(V);
	cout << "\n";

	memset(isVisited, false, sizeof(isVisited));

	// 4. BFS
	bfs(V);
	cout << "\n";

	return 0;
}
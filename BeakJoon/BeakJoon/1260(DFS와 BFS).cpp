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
	//// 2. DFS에 사용할 스택을 만든다
	//stack<int> st; // 앞으로 방문할 정점이 저장

	//st.push(V); // 첫번째로 방문할 정점
	//isVisited[V] = true;


	//// 3. 더이상 방문할 정점이 없을 때 까지 방문
	//while (false == st.empty()) // 스택이 비어있다면 모든 정점을 방문한 것
	//{
	//	// 3-1. 정점을 방문
	//	int node = st.top();
	//	st.pop();

	//	cout << node << ' ';
	//	
	//	

	//	// 3-2. 다음으로 방문할 정점을 찾는다.
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
	// 2. BFS에 사용할 큐 생성
	queue<int> q;
	q.push(V);
	isVisited[V] = true;

	// 3. 더이상 방문할 정점이 없을 때 까지 방문
	while (false == q.empty()) // 스택이 비어있다면 모든 정점을 방문한 것
	{
		// 3-1. 정점을 방문
		int node = q.front();
		q.pop();

		cout << node << " ";


		// 3-2. 다음으로 방문할 정점을 찾는다.
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
	
	// 1. 그래프 구성
	for (int i = 0; i < M; ++i)
	{
		int s, e;
		cin >> s >> e;

		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	// 2. 작은 정점부터 방문 시키기 위해 정렬
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
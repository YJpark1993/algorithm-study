#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int edgeTile[1001][1001];
char visited[1001] = { 0 };
int vertices, edges, start;

void bfs()
{
	visited[start] = 1;
	cout << start << " ";

	int cur;
	queue<int> que;
	que.push(start);
	while (que.empty() == false)
	{
		cur = que.front();
		que.pop();

		for (int j = 1; j < vertices + 1; j++)
		{
			if (edgeTile[cur][j] == 1 && visited[j] == 0)
			{
				visited[j] = 1;
				que.push(j);
				cout << j << " ";
			}
		}
	}
}

void dfs(int cur)
{
	visited[cur] = 1;
	cout << cur << " ";
	for (int j = 1; j < vertices + 1; j++)
	{
		if (edgeTile[cur][j] == 1 && visited[j] == 0)
		{
			dfs(j);
		}
	}
}

int main()
{
	int v1, v2;

	cin >> vertices >> edges >> start;

	for (int i = 0; i < edges; i++)
	{
		cin >> v1 >> v2;
		edgeTile[v1][v2] = edgeTile[v2][v1] = 1;
	}
	
	dfs(start);
	memset(visited, 0, sizeof(visited));
	cout << endl;
	bfs();

	return 0;
}
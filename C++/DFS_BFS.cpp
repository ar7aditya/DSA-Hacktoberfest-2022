# include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>graph[], vector<int>&vis, vector<int>&store) {
	vis[node] = 1;
	store.push_back(node);

	for (auto it : graph[node]) {
		if (!vis[it])
			dfs(it, graph, vis, store);
	}
}
void bfs(int node, vector<int>graph[], vector<int>&vis, vector<int>&ans) {
	queue<int>Queue;

	Queue.push(node);

	while (!Queue.empty()) {
		node = Queue.front();
		Queue.pop();

		ans.push_back(node);
		for (auto it : graph[node]) {
			if (!vis[it]) {
				Queue.push(it);
				vis[it] = 1;
			}
		}
	}
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{

	vector<int>vis(vertex, 0);
	// creating graph
	vector<int>graph[vertex];

	for (int i = 0; i < edges.size(); i++) {
		graph[edges[i].first].push_back(edges[i].second);
		graph[edges[i].second].push_back(edges[i].first);
	}

	for (int i = 0; i < vertex; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	vector<int>ans;
	for (int i = 0; i < vertex; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			bfs(i, graph, vis, ans);
		}
	}

	return ans;
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
	// creating graph
	vector<int>graph[V];

	for (int i = 0; i < E; i++) {
		graph[edges[i][0]].push_back(edges[i][1]);
		graph[edges[i][1]].push_back(edges[i][0]);
	}

	vector<vector<int>>ans;
	vector<int>vis(V, 0);

	for (int i = 0; i < V; i++) {
		if (!vis[i]) {
			vector<int>v;
			dfs(i, graph, vis, v);
			ans.push_back(v);
		}
	}

	return ans;
}
int main() {

	// n= no of vertices
	// m = no of edges
	// vertices start from 0 and end on n-1
	int n, m;
	cin >> n >> m;

	vector<vector<int>>edges;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		edges.push_back({x, y});
	}

	vector<int>arr = depthFirstSearch(n, m, edges); // dfs of graph
	vector<int>arry = BFS(n, edges); // bfs starting from vertex 0

	for (auto it : arr)
		cout << it << " ";
	cout << '\n';

	for (auto it : arry)
		cout << it << " ";

	return 0;
}
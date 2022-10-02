#include <bits/stdc++.h>
using namespace std;
void stronglyConnected(int node, vector<int>transpose[], vector<int>&visited, vector<int>&find) {
    visited[node] = 1;

    find.push_back(node);
    for (auto neighbor : transpose[node]) {
        if (!visited[neighbor]) {
            stronglyConnected(neighbor, transpose, visited, find);
        }
    }
}
void reverse(vector<int>graph[], vector<int>transpose[], int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (auto neighbor : graph[i]) {
            transpose[neighbor].push_back(i);
        }
    }
}
void dfs(int node, vector<int>&visited, vector<int>graph[], stack<int>&store) {
    visited[node] = 1;

    for (auto neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, graph, store);
        }
    }

    store.push(node);
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
//     O(E) + O(V+E) + O(E) + O(V+E)
//        4 * O(N)
    vector<int>graph[n];

    for (int i = 0; i < edges.size(); i++) {
        graph[edges[i][0]].push_back(edges[i][1]);
    }

    stack<int>store;

    vector<int>visited(n, 0);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, visited, graph, store);
        }
    }

    vector<int>transpose[n];

    reverse(graph, transpose, n);

    for (int i = 0; i < n; i++)
        visited[i] = 0;
    vector<vector<int>>components;

    while (!store.empty()) {

        int node = store.top();
        store.pop();

        if (visited[node]) continue;

        vector<int>find;
        stronglyConnected(node, transpose, visited, find);
        components.push_back(find);
    }

    return components;
}

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int v, e;
        cin >> v >> e;

        vector<vector<int>>edges;

        for (int i = 0; i < e; i++) {
            int x, y;
            cin >> x >> y;
            edges.push_back({x, y});
        }

        vector<vector<int>> comp = stronglyConnectedComponents(v, edges);

        for (int i = 0; i < comp.size(); i++) {
            for (auto it : comp[i])
                cout << it << " ";
            cout << '\n';
        }
    }
    return 0;
}
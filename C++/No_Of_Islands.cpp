/*
Problem Statement:
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
*/
# include <bits/stdc++.h>
using namespace std;


int Row[4] = {1, -1, 0, 0};
int Col[4] = {0, 0, 1, -1};

void bfs(int row, int col, vector<vector<char>>&grid) {

    queue<pair<int, int>>Queue;
    Queue.push({row, col});

    while (!Queue.empty()) {
        row = Queue.front().first;
        col = Queue.front().second;

        Queue.pop();

        for (int i = 0; i < 4; i++) {
            int cellRow = row + Row[i];
            int cellCol = col + Col[i];

            if (cellRow >= 0 && cellRow < grid.size() && cellCol >= 0 && cellCol < grid[0].size() && grid[cellRow][cellCol] == '1') {
                Queue.push({cellRow, cellCol});
                grid[cellRow][cellCol] = '0';
            }
        }
    }
}
int numIslands(vector<vector<char>>& grid) {
    int rows = grid.size(), columns = grid[0].size();

    int noOfIslands = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (grid[i][j] == '1') {
                noOfIslands++;
                grid[i][j] = '0';
                bfs(i, j, grid);
            }
        }
    }

    return noOfIslands;
}

int main() {

    int n, m;
    cin >> n >> m;
    vector<vector<char>>grid;

    for (int i = 0; i < n; i++) {
        vector<char>v(m);
        for (int j = 0; j < m; j++) {
            cin >> v[j];
        }
        grid.push_back(v);
    }

    cout << numIslands(grid);
    return 0;
}
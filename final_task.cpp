#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
int n, m;
char maze[MAXN][MAXN];
bool visited[MAXN][MAXN];
pair<int, int> parent[MAXN][MAXN];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
pair<int, int> start, end_pos;

// TODO 1: Check if (x, y) is a valid move
bool isValid(int x, int y) {
    // Fill this function
    return x >= 0 && x < n && y >= 0 && y < m &&
           !visited[x][y] && (maze[x][y] == '1' || maze[x][y] == 'E');
}

// TODO 2: BFS Implementation
void bfs() {
    queue<pair<int, int>> q;
    visited[start.first][start.second] = true;
    q.push(start);

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        if (cur == end_pos) break;

        for (int i = 0; i < 4; ++i) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            // Fill the condition and logic
            if (isValid(nx, ny)) {
                visited[nx][ny] = true;
                parent[nx][ny] = cur;
                q.push({nx, ny});
        }
    }
}}


// TODO 3: DFS Implementation
bool dfs(int x, int y) {
    // Fill this function (recursive DFS)
     if (!isValid(x, y)) return false;
    visited[x][y] = true;

    if (make_pair(x, y) == end_pos) return true;

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (dfs(nx, ny)) {
            parent[nx][ny] = {x, y};
            return true;
        }
    }
    return false; // Placeholder
}

// TODO 4: Reconstruct and print the path
void reconstructPath(pair<int, int> end_point) {
    // Fill this function
    vector<pair<int, int>> path;
    pair<int, int> cur = end_point;

    while (cur != start) {
        path.push_back(cur);
        cur = parent[cur.first][cur.second];
    }
    path.push_back(start);

    // Mark path with '*'
    for (auto& p : path) {
        if (maze[p.first][p.second] != 'S' && maze[p.first][p.second] != 'E') {
            maze[p.first][p.second] = '*';
        }
    }
}


void printMaze() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << maze[i][j];
        }
        cout << '\n';
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> maze[i][j];
            if (maze[i][j] == 'S') start = {i, j};
            if (maze[i][j] == 'E') end_pos = {i, j};
        }
    }

    // Uncomment the one you want to test
    // bfs();
    // dfs(start.first, start.second);

    // reconstructPath(end_pos);
    // printMaze();


    return 0;
}

set<int> g[101];
int n, m;
// Рекурсивная версия
void dfs(int start, vector<bool> & visited) {
  visited[start] = true;
  for (auto u : g[start]) {
    if (!visited[u]) {
      dfs(u, visited);
    }
  }
}
void dfs(int start, vector<bool> & visited) {
  // Итеративная версия
  stack<int> s;
  s.push(start);
  visited[start] = true;
  while (!s.empty()) {
    int v = s.top();
    s.pop();
    for (auto neighbor : g[v]) {
      if (!visited[neighbor]) {
        s.push(neighbor);
        visited[neighbor] = true;
      }
    }
  }
}
  signed main() {
  // Список смежности
    cin >> n >> m;
    vector<bool> visited(n + 1);
    forll(m) {
      int tmp, tmp2;
      cin >> tmp >> tmp2;
      g[tmp2].insert(tmp);
      g[tmp].insert(tmp2);
    }
  }
// Переделал со списком смежностей
#include "queue"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <utility>
#define int long long
#define endl "\n"
#define forll(n) for(long long i = 0; i < (n); i++)
#define forllr(n) for(long long i = (n); i >= 0; i--)
#define forll2(m) for(long long j = 0; j < (m); j++)
#define fori(n) for(int i = 0; i < (n); i++)
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define ou(x) cout<<x
#define in(x) cin>>x
using namespace std;

void fastOutput() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
}
set<int> g[101];
int n, m;
int mmax=0;
// Находит наибольшее расстояние от корня до вершин
void bfs (int start, vector <bool>& visited, vector<int>& dst, vector<int>& pr) {
  queue<int> q;
  q.push(start);
  visited[start] = true;
  dst[start] = 0;
  pr[start] = -1;   //Пометка, означающая, что у вершины 0 нет предыдущей.
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (auto neighbor: g[cur]) {
      if (!visited[neighbor]) {
        q.push(neighbor);
        visited[neighbor] = true;
        dst[neighbor] = dst[cur] + 1; // Дистанция до вершины
        pr[neighbor] = cur;   //сохранение предыдущей вершины
      }
    }
  }
}
signed main() {
  freopen("wave.in", "r", stdin);
  freopen("wave.out", "w", stdout);
  vector<int> dst(101, -1); // массив для дистанций
  vector<int> pr(101, -1); // массив для записи путя
  int start;
  int m;
  cin >> n>>m>>start;
  vector<bool> visited(n + 1);
  for (int i=1; i<=m; ++i) {
    int tmp, tmp2;
    cin >> tmp >> tmp2;
    g[tmp2].insert(tmp);
    g[tmp].insert(tmp2);
  }
  int count=0;
  bfs(start, visited, dst, pr);
  int j=start;
  int i=0;
  cout<<n<<endl;
  // Вывод пути обхода
  cout<<start<< " ";
  int used=1;
  bool fl = false;
  int lasti=start;
  int firsti=start;
  set<int> temp;
  temp.insert(start);
  while (true) {
    set<int> temp1;
    for (i=1; i<=n; ++i) {
      for (auto it: temp) {
        if (pr[i] == it) {
          cout << i << " ";
          temp1.insert(i);
          used++;
        }
      }
    }
    if (used>=n) break;
    temp = temp1;
  }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////// Вариант 2

int n, m, root;
vector<int> G[101];
vector<int> ans;
vector<int> used(101, 0);
void bfs(int root) {
  queue<int> q;
  used[root] = 1;
  q.push(root);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    ans.push_back(v);
    for (auto u : G[v]) {
      if (!used[u]) {
        used[u] = 1;
        q.push(u);
      }
    }
  }
}

int main() {
  freopen("wave.in", "r", stdin);
  freopen("wave.out", "w", stdout);
  cin >> n >> m >> root;
  for (int i = 0; i < m; ++i) {
    int v, u;
    cin >> v >> u;
    v--, u--;
    G[v].push_back(u);
    G[u].push_back(v);
  }
  bfs(root - 1);
  cout << ans.size() << '\n';
  for (auto x : ans) {
    cout << x + 1 << ' ';
  }
  return 0;
}
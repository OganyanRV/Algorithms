// Переделал со списком смежностей
#include <stack>
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
set<int> g[20001];
int n, m, q=0;
void dfs(int start, vector<bool> & visited, vector<int> &ans) {
  stack<int> s;
  s.push(start);
  visited[start] = true;
  ans[start] = q;
  while (!s.empty()) {
    int v = s.top();
    s.pop();
    for (auto neighbor : g[v]) {
      if (!visited[neighbor]) {
        s.push(neighbor);
        visited[neighbor] = true;
        ans[neighbor] = q;
      }
    }
  }
}

signed main() {
  freopen("connect.in", "r", stdin);
 freopen("connect.out", "w", stdout);
  cin >> n >> m;
  vector<bool> visited(n + 1);
  forll(m) {
    int tmp, tmp2;
    cin >> tmp >> tmp2;
    g[tmp2].insert(tmp);
    g[tmp].insert(tmp2);
  }
  vi ans (n+1, 0);
  for (int i = 1; i <= n; ++i) {
    if (!ans[i] && !visited[i]) {
      q++;
      dfs(i, visited, ans);
    }
  }
  cout<<q<<endl;
  for (int i=1; i<=n; ++i) {
    cout<<ans[i]<<" ";
  }

}
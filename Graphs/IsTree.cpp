// Переделал со списком смежностей

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
void dfs(int start, vector<bool> & visited)
{
  visited[start] = true;
  for (auto u : g[start]) {
    if (!visited[u]) {
      dfs(u, visited);
    }
  }
  /*for (auto u : g[start])
    if (u && !visited[u])
      dfs(u, visited, g);
      */
}
signed main() {
  freopen("tree.in", "r", stdin);
freopen("tree.out", "w", stdout);
  cin >> n >> m;
  vector<bool> visited(n + 1);
  forll(m) {
    int tmp, tmp2;
    cin >> tmp >> tmp2;
    g[tmp2].insert(tmp);
    g[tmp].insert(tmp2);
  }
  int ncomp = 0;
  int start = 1;
  for (int i = 1; i <= n; ++i)
    if (!visited[i]) {
      ++ncomp;
      dfs(start, visited);
    }
  ncomp-1 || m!=n-1? cout<<"NO" : cout<<"YES";
}
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <limits.h>
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

void Deixtra(vector < vector < pair<int,int> > > & graph, int &size, vector<int> &distance, int start) {
  distance[start] = 0;
  vector<bool> u (size);
  for (int i=0; i<size; ++i) {
    int v = -1;
    for (int j=0; j<size; ++j)
      if (!u[j] && (v == -1 || distance[j] < distance[v]))
        v = j;
    if (distance[v] == INT_MAX)
      break;
    u[v] = true;

    for (size_t j=0; j<graph[v].size(); ++j) {
      int to = graph[v][j].first,
          len = graph[v][j].second;
      if (distance[v] + len < distance[to]) {
        distance[to] = distance[v] + len;
       // p[to] = v;
      }
    }
  }
}

signed main() {
  int n, begin, end;
  freopen("dijkstra.in", "r", stdin);
  freopen("dijkstra.out", "w", stdout);

  //vector <int> p (size);
  cin >> n>>begin>>end;
  vector<int> distance (n, INT_MAX);
  vector < vector < pair<int,int> > > g; // Список смежностей, причем первый эелмент - смежная вершина, правый - вес ребра
  forll(n) {
    g.resize(n);
    forll2(n){
      int k;
      cin>>k;
      if (i!=j && k!=-1)
        g[i].push_back(std::make_pair(j,k));
    }
  }
  Deixtra(g, n, distance, --begin );
  distance[end-1]==INT_MAX? cout<<"-1" : cout<<distance[end-1];


}
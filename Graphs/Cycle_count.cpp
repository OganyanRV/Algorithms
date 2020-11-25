#pragma comment(linker, "/STACK:16777216")
#include <vector>
#include<algorithm>
#include <iostream>
#include<set>
#include <string>
#include <math.h>
#include <numeric>
#include<map>
#include<queue>
#include <deque>
#include<unordered_map>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define vll vector<long long int>
#define ve vector
#define fi first
#define se second
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define pb push_back
#define mp make_pair
#define len(a) (int)(a).size()
#define all(a) (a).begin(),(a).end()
#define endl '\n'
#define M_PI 3.14159265358979323846
const int INF = 2 * 1e9;
const ll MOD = 1000000007;
//#define int long long
using namespace std;


int n;
vector < vector<int> > graph;
vector<char> color;
vector<int> path;
int cycle_st, cycle_end;

bool dfs (int v) {
    color[v] = 1;
    for (size_t i=0; i<graph[v].size(); ++i) {
        int to = graph[v][i];
        if (color[to] == 0) {
            path[to] = v;
            if (dfs (to))  return true;
        }
        else if (color[to] == 1) {
            cycle_end = v;
            cycle_st = to;
            return true;
        }
    }
    color[v] = 2;
    return false;
}


void solve() {
    int m;
    cin>>n>>m;
    graph.resize(n);
    //  Список смежности
    rep(i,m) {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        graph[a].push_back(b);
    }
    path.assign (n, -1);
    color.assign (n, 0);
    cycle_st = -1;
    for (int i=0; i<n; ++i)
        if (dfs (i))
            break;

    if (cycle_st == -1)
        puts ("NO");
    else {
        puts ("YES");
        vector<int> cycle;
        cycle.push_back (cycle_st);
        for (int v=cycle_end; v!=cycle_st; v=path[v])
            cycle.push_back (v);
        cycle.push_back (cycle_st);
        reverse (cycle.begin(), cycle.end());
        for (size_t i=0; i<cycle.size() - 1; ++i)
            printf ("%d ", cycle[i]+1);
    }
    return;


}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cout.fixed; cout.precision(12);

    solve();
  return 0;
}
